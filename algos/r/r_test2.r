
#install.packages("urca")
#install.packages("plotly")

# Preliminaries
library(urca)
#library(plotly)
source("data_pipeline.r")
 
prices <- load_data(c('XOM', 'CVX'), start='2010-01-01', end = '2019-06-01', source='av', 
                    return_data = 'Adjusted', save_indiv = TRUE)
plot(prices, col=c('blue', 'red'), main = 'XOM and CVX')
legend('bottomright', col=c('blue', 'red'), legend=c('XOM', 'CVX'), lty=1, bty='n')

# scatter plot of prices
plot(coredata(prices[, 'XOM.Adjusted']), coredata(prices[, 'CVX.Adjusted']), col='blue',
     xlab='XOM', ylab='CVX')
 
# linear regression of prices
fit <- lm(coredata(prices[, 'CVX.Adjusted']) ~ coredata(prices[, 'XOM.Adjusted']))
summary(fit)
 
'''
# output:
 
# Call:
#   lm(formula = coredata(prices[, "CVX.Adjusted"]) ~ coredata(prices[, 
#                                                                     "XOM.Adjusted"]))
# 
# Residuals:
#   Min      1Q  Median      3Q     Max 
# -9.6122 -2.2196 -0.3546  2.4747  9.3366 
# 
# Coefficients:
#   Estimate Std. Error t value Pr(>|t|)    
# (Intercept)                        -41.39747    1.88181  -22.00   <2e-16 ***
#   coredata(prices[, "XOM.Adjusted"])   1.67875    0.02309   72.71   <2e-16 ***
#   ---
#   Signif. codes:  0 ‘***’ 0.001 ‘**’ 0.01 ‘*’ 0.05 ‘.’ 0.1 ‘ ’ 1
# 
# Residual standard error: 3.865 on 754 degrees of freedom
# Multiple R-squared:  0.8752,	Adjusted R-squared:  0.875 
# F-statistic:  5287 on 1 and 754 DF,  p-value: < 2.2e-16
'''
 
clip(min(coredata(prices[, 'XOM.Adjusted'])), max(coredata(prices[, 'XOM.Adjusted'])),
     min(coredata(prices[, 'CVX.Adjusted'])), max(coredata(prices[, 'CVX.Adjusted'])))
abline(fit$coefficients, col='red')


# construct and plot spread
hedge <- fit$coefficients[2]
spread <- prices[, 'CVX.Adjusted'] - hedge*coredata(prices[, 'XOM.Adjusted'])
plot(spread, main='CVX-XOM Spread', col='black')