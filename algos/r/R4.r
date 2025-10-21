
#install.packages("Quandl")
#install.packages("ggplot2")
#install.packages("fpp2")
#install.packages("ggfortify")
#install.packages("devtools")
#install.packages("Rcpp")

library(Quandl)
library(Rcpp)
library(ggplot2)
library(fpp2)
library(ggfortify)
library(devtools)

Quandl.api_key('VUsfvNfybt3vg2KnMTvu')

X <- Quandl('SGE/USAUNR', type="ts", start_date='1995-01-01', end_date='2020-01-01')
X

Y <- Quandl('SGE/EURUNR', type="ts", start_date='1995-01-01', end_date='2020-01-01')
Y

# Time plots

autoplot(X) + 
    ggtitle("USA GGR") + 
    xlab("Year") + 
    ylab("Rate")


# Seasonal plots

ggseasonplot(X,year.labels=TRUE,years.labels.left=TRUE) + 
    ylab("%") +
    ggtitle("Seasonal plot: USA UNR")

ggseasonplot(X, polar=TRUE) + 
    ylab("%") + 
    ggtitle("Seasonal plot: USA UNR")

# Seasonal subseries plots

ggsubseriesplot(X) +
    ylab("%") + 
    ggtitle("Seasonal plot: USA UNR")

# Scatterplolts

XY <- X/Y

qplot(x = X,y = Y)