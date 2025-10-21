# how to install
#cran <- getOption("repos")
#cran["dmlc"] <- "https://s3-us-west-2.amazonaws.com/apache-mxnet/R/CRAN/"
#options(repos = cran)
#install.packages('mxnet')
# - or (if not yet available for current version) -
#install.packages("https://s3.ca-central-1.amazonaws.com/jeremiedb/share/mxnet/CPU/mxnet.zip", repos = NULL)
library('mxnet', quietly = T)
library('caret', quietly = T)

neural.train = function(model,XY) 
{
  X <- data.matrix(XY[,-ncol(XY)])
  Y <- XY[,ncol(XY)]
  Y <- ifelse(Y > 0,1,0)
  Models[[model]] <<- mx.mlp(X,Y,
       hidden_node = c(30), 
       out_node = 2, 
       activation = "sigmoid",
       out_activation = "softmax",
       num.round = 20,
       array.batch.size = 20,
       learning.rate = 0.05,
       momentum = 0.9,
       eval.metric = mx.metric.accuracy)
}

neural.predict = function(model,X) 
{
  if(is.vector(X)) X <- t(X)
  X <- data.matrix(X)
  Y <- predict(Models[[model]],X)
  return(ifelse(Y[1,] > Y[2,],0,1))
}

neural.save = function(name)
{
  for(i in c(1:length(Models)))
    Models[[i]] <<- mx.serialize(Models[[i]])
  save(Models,file=name)  
}

neural.load <- function(name)
{
  load(name,.GlobalEnv)
  for(i in c(1:length(Models)))
    Models[[i]] <<- mx.unserialize(Models[[i]])
}

neural.init = function()
{
  mx.set.seed(365)
  Models <<- vector("list")
}

neural.test = function() 
{
  neural.init()
  XY <<- read.csv('MyZorroPath/Data/DeepLearnMX.csv',header = F)
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

