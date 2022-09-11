
library('deepnet', quietly = T) 
library('caret', quietly = T)

neural.train = function(model,XY) 
{
  XY <- as.matrix(XY)
  X <- XY[,-ncol(XY)]
  Y <- XY[,ncol(XY)]
  Y <- ifelse(Y > 0,1,0)
  Models[[model]] <<- sae.dnn.train(X,Y,
      hidden = c(30,30,30), 
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
