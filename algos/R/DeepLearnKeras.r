library('keras', quietly = T)
library('caret', quietly = T)
#call install_keras() after loading the library the first time

neural.train = function(model,XY) 
{
  X <- data.matrix(XY[,-ncol(XY)])
  Y <- XY[,ncol(XY)]
  Y <- ifelse(Y > 0,1,0)
  Model <- keras_model_sequential() 
  Model %>% 
    layer_dense(units = 30, activation = 'relu', input_shape = c(ncol(X))) %>% 
    layer_dropout(rate = 0.2) %>% 
    layer_dense(units = 1, activation = 'sigmoid')
  
  Model %>% compile(
    loss = 'binary_crossentropy',
    optimizer = optimizer_rmsprop(),
    metrics = c('accuracy')
  )
  
  Model %>% fit(X, Y, 
    epochs = 20, batch_size = 20, 
    validation_split = 0, shuffle = FALSE
  )
  
  Models[[model]] <<- Model
}

neural.predict = function(model,X) 
{
  if(is.vector(X)) X <- t(X)
  X <- as.matrix(X)
  Y <- Models[[model]] %>% predict_proba(X)
  return(ifelse(Y > 0.5,1,0))
  #return(Y)
}

neural.save = function(name)
{
  for(i in c(1:length(Models)))
    Models[[i]] <<- serialize_model(Models[[i]])
  save(Models,file=name)  
}

neural.load <- function(name)
{
  load(name,.GlobalEnv)
  for(i in c(1:length(Models)))
    Models[[i]] <<- unserialize_model(Models[[i]])
}

neural.init = function()
{
  set.seed(365)
  Models <<- vector("list")
}

neural.test = function() 
{
  neural.init()
  XY <<- read.csv('MyZorroPath/Data/DeepLearnKeras.csv',header = F)
  splits <- nrow(XY)*0.8
  XY.tr <<- head(XY,splits)
  XY.ts <<- tail(XY,-splits)
  neural.train(1,XY.tr)
  
  X <<- XY.ts[,-ncol(XY.ts)]
  Y <<- XY.ts[,ncol(XY.ts)]
  Y.ob <<- ifelse(Y > 0,1,0)
  Y.pr <<- neural.predict(1,X)
  confusionMatrix(as.factor(Y.pr),as.factor(Y.ob))
}

