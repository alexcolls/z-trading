library('deepnet', quietly = T) 
library('caret', quietly = T)

neural.train = function(model,XY) 
{
  XY <- as.matrix(XY)
  X <- XY[,-ncol(XY)]
  Y <- XY[,ncol(XY)]
  Y <- ifelse(Y > 0,1,0)
  Models[[model]] <<- sae.dnn.train(X,Y,
      hidden = c(50,100,50), 
      activationfun = "tanh", 
      learningrate = 0.5, 
      momentum = 0.5, 
      learningrate_scale = 1.0, 
      output = "sigm", 
      sae_output = "linear", 
      numepochs = 100, 
      batchsize = 100,
      hidden_dropout = 0, 
      visible_dropout = 0)
}

neural.predict = function(model,X) 
{
  if(is.vector(X)) X <- t(X)
  return(nn.predict(Models[[model]],X))
}

neural.save = function(name)
{
  save(Models,file=name)  
}

neural.init = function()
{
  set.seed(365)
  Models <<- vector("list")
}

TestOOS = function() 
{
  neural.init()
  XY <<- read.csv('C:/Zorro/Data/DeepSignalsEURUSD_L.csv',header = F)
  splits <- nrow(XY)*0.8
  XY.tr <<- head(XY,splits);
  XY.ts <<- tail(XY,-splits)
  neural.train(2,XY.tr)
  X <<- XY.ts[,-ncol(XY.ts)]
  Y <<- XY.ts[,ncol(XY.ts)]
  Y.ob <<- ifelse(Y > 0,1,0)
  Y <<- neural.predict(2,X)
  Y.pr <<- ifelse(Y > 0.5,1,0)
  confusionMatrix(Y.pr,Y.ob)
}
