


MyFunc <- function(){
    library(plotly)
    library(Quandl)
    Quandl.api_key('VUsfvNfybt3vg2KnMTvu')
    USAUNR <- Quandl('SGE/AUSUNR', start_date='1950-01-01', end_date='2020-01-01')
    USAUNR
    p <- plot_ly(USAUNR, x = ~Date, y = ~Value, type= "bar", theme="Plotly Dark")
    p
}

install.packages("devtools")
devtools::install_bitbucket("infrontdev/InfrontConnect")

library(InfrontConnect)


