install.packages(c("fiery", "routr", "reqres", "htmltools", "base64enc", 
    "plotly", "mime", "crayon", "devtools"))

install.packages("GitHub")



library(devtools)
install_github("plotly/dashR")
usethis::browse_github_pat()
usethis::edit_r_environ()

Sys.getenv("GITHUB_PAT")

devtools::install("C:\\Users\\pmarquez\\Desktop\\dashR-master", dependencies = TRUE)

library(dash)
library(dashHtmlComponents)
library(dashCoreComponents)
library(dashTable)

app <- Dash$new()

app$layout(
  dccInput(id = "inputID", value = "initial value", type = "text"),
  htmlDiv(id = "outputID")
)

app$callback(output = list(id="outputID", property="children"), 
             params = list(input(id="inputID", property="value"),
                      state(id="inputID", property="type")), 
  function(x, y) {
    sprintf("You've entered: '%s' into a '%s' input control", x, y)
  }
)

app$run_server(showcase = TRUE)

####

app <- Dash$new()

app$layout(
  dccInput(id = "graphTitle", 
            value = "Let's Dance!", 
            type = "text"),
  htmlDiv(id = "outputID"),
  dccGraph(id = "giraffe",
            figure = list(
              data = list(x = c(1,2,3), y = c(3,2,8), type = 'bar'),
              layout = list(title = "Let's Dance!")
            )
  )
)

app$callback(output = list(id = "giraffe", property = "figure"), 
             params = list(input("graphTitle", "value")),     
             function(newTitle) {
                 
                 rand1 <- sample(1:10, 1)
                 
                 rand2 <- sample(1:10, 1)
                 rand3 <- sample(1:10, 1)
                 rand4 <- sample(1:10, 1)
                 
                 x <- c(1,2,3)
                 y <- c(3,6,rand1)
                 y2 <- c(rand2,rand3,rand4)
                 
                 df = data.frame(x, y, y2)
                 
                 list(
                   data = 
                     list(            
                       list(
                         x = df$x, 
                         y = df$y, 
                         type = 'bar'
                       ),
                       list(
                         x = df$x, 
                         y = df$y2, 
                         type = 'scatter',
                         mode = 'lines+markers',
                         line = list(width = 4)
                       )                
                     ),
                   layout = list(title = newTitle)
                 )
               }
)

app$callback(output = list(id = "outputID", property = "children"), 
             params = list(input("graphTitle", "value"),
                           state("graphTitle", "type")), 
             function(x, y) {
                 sprintf("You've entered: '%s' into a '%s' input control", x, y)
             }
)

app$run_server(showcase = TRUE)

#####

library(plotly)
p <- plot_ly(midwest, x = ~percollege, color = ~state, type = "box")
p

Sys.setenv("plotly_username"="your_plotly_username")
Sys.setenv("plotly_api_key"="your_api_key")

library(plotly)
p <- plot_ly(midwest, x = ~percollege, color = ~state, type = "box")
api_create(p, filename = "r-docs-midwest-boxplots")


######

library(Quandl)

Quandl.api_key('VUsfvNfybt3vg2KnMTvu')

USAUNR <- Quandl('SGE/USAUNR', start_date='1950-01-01', end_date='2020-01-01')
USAUNR

p <- plot_ly(USAUNR, x = ~Date, y = ~Value, type= "bar", theme="Plotly Dark")
p
