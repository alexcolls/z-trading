library('h2o', quietly = T) # also needs the Java JDK
library('caret', quietly = T)
library('e1071', quietly = T)

neural.train = function(model,XY) 
{
  XY <- as.h2o(XY)
  Models[[model]] <<- h2o.deeplearning(-ncol(XY),ncol(XY),XY,
    hidden = c(30,30,30),
    seed = 365)
}

# sends anything to the cluster. Fast for batches, really slow for single predictions. 
neural.predict = function(model,X) 
{
  if(is.vector(X)) 
    X <- as.h2o(as.data.frame(t(X)))
  else
    X <- as.h2o(X)
  Y <- h2o.predict(Models[[model]],X)
  return(as.vector(Y))
}

neural.save = function(name)
{
  save(Models,file=name)  
}

# won't run parallel. Any new client connects happily to the running cluster.
neural.init = function()
{
  h2o.init()
  Models <<- vector("list")
}

neural.test = function() 
{
  neural.init()
# read the training data frame generated with the SIGNALS method
  XY <<- read.csv('MyZorroPath/Data/DeepLearnH2O.csv',header = F)
  splits <- nrow(XY)*0.8
  XY.tr <<- head(XY,splits)
  XY.ts <<- tail(XY,-splits)
  neural.train(2,XY.tr)
  X <<- XY.ts[,-ncol(XY.ts)]
  Y <<- XY.ts[,ncol(XY.ts)]
  Y.ob <<- ifelse(Y > 0,1,0)
  Y <<- neural.predict(2,X)
  Y.pr <<- ifelse(Y > 0,1,0)
  confusionMatrix(as_factor(Y.pr),as_factor(Y.ob))
}
