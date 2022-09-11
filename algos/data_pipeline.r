#install.packages("quantmod")

library(quantmod)

# GLOBALS
setDefaults("getSymbols.av", api.key = "9N8M5L3765MKOJLL")
setDefaults("getSymbols.csv", dir = "my.csv.directory")
setDefaults("getSymbols.rda", dir = getwd())
setDefaults("getSymbols.RData", dir = "my.RData.directory")
data_directory <- getwd()

# HELPERS
process_dates <- function(start, end) {
  "Helper function for converting character strings to dates"
  
  if(class(start) == "character") start = as.Date(start,format='%Y-%m-%d')
  if(class(start) != "Date") stop("start must be of character of Date class")
  if(class(end) == "character") end = as.Date(end, format='%Y-%m-%d')
  if(class(end) != "Date") stop("end must be character or Date class")
  
  dates <- (list(start = start, end = end))
  return(dates)
}

dump_data <- function(data, symbols, return_data) {
  "helper function for saving data to rds"
  
  file_name <- ''
  for(i in 1:length(symbols)) {
    file_name <- paste0(file_name, symbols[i], '_')
  }
  file_name <- paste0(file_name, return_data, '.rds')
  saveRDS(data, paste0(data_directory, '/', file_name))
}

# DATA RETRIEVAL AND SAVING
load_data <- function(symbols, start=Sys.Date()-501, end=Sys.Date()-1, 
                      synth_params=c(500, 0, 0.03), source='av', 
                      save_indiv=FALSE, save_data_object=FALSE,
                      return_data='Close'){
  {"
    Generic wrapper function for loading or creating financial data from several sources.
    ________________________________________________________________________________________________________
    Wraps: 
    * quantmod::getSymbols()
    * Quandl::Quandl() (in development)
    * custom functions for generating synthetic price data
    ________________________________________________________________________________________________________
    Args:
    * symbols: (optional) character vector of tickers or symbols, must be specified if source != synthetic
    * start: start date of requested data as either a character string 'YYYY-MM-DD' or Date object (default: 501 days prior to today's date)
    * end: end date of requested data as either a character string 'YYYY-MM-DD' or Date object (default: 1 day prior to today's date)
    * synth_params: (optional) vector of c(data_length, mean_return, stddev_return) for synthetic prices, must be specified if source == 'synthetic'
    * source: source from which to obtain data; options are:
      - 'av': Alpha Vantage. Requires personal API key
      - 'google': Google Finance
      - 'yahoo' : Yahoo Finance
      - 'oanda' : Oanda (exchange rates, max date range is last 180 days)
      - 'FRED' : Federal Reserve Economic Database
      - 'Quandl' : Quandl. Rquires personal API key
      - 'csv' : local csv file
      - 'RData' or 'rds': local R binary file
      - 'MySQL' or 'SQLite': MySQL or SQLite database (in development)
      - 'synthetic': generates synthetic data with statistical properties given by synth_params:
        # normally distributed returns
        # geometric brownian motion
        # positive autocorrelation (in development)
        # negative autocorrelation (in development)
        # Ornstein-Uhlenbeck process (in development)
        # two or more cointegrated time series (in development)
    * save_indiv: save individual symbols' data to individual RDS objects (default=FALSE)
    * save_data_object: dump downloaded and transformed data to an R binary file (default=FALSE)
    * return_data: (not effect for source='synthetic') specify the columns to return, options are (default='close'):
      - 'Open': open prices only
      - 'High': high prices only
      - 'Low': low prices only
      - 'Close': closing prices only
      - 'Volume': volumes only
    - 'Adjusted': adjusted closing prices only
    - 'all': return all downloaded data 
    ________________________________________________________________________________________________________
    Returns:
    * data.frame or xts object 
    ________________________________________________________________________________________________________
    TODO:
    * support SQL DB 
    * add more options for return data 
    * more options for statistical properties of synthetic data
    * more intelligent error handling
    "}
  
  if(source == "synthetic") {
    # generate several types of synthetic data
    
    norm <- cumsum(rnorm(synth_params[1], synth_params[2], 100*synth_params[3]))
    gbm <- cumprod(1 + rnorm(synth_params[1], synth_params[2]/100, synth_params[3])) 
    data <- data.frame(norm, gbm)
  }
  
  else
  {
    # retrieve data from other source
    
    # preliminaries
    require(quantmod)
    extraction_functions <- list(Open=Op, High=Hi, Low=Lo, Close=Cl, Adjusted=Ad, Volume=Vo, all=OHLCV)
    data_env = new.env()
    dates <- process_dates(start, end)
    
    # retrieve data to new environment
    getSymbols(symbols, src=source, from=dates[['start']], to=dates[['end']], env=data_env, adjust=TRUE)
    
    # save individual symbols' data to rds
    if(save_indiv == TRUE) {
      SAVE_INDIV = function(x){
        name = paste0(data_directory, '/', strsplit(names(x)[1], '\\.')[[1]][1], '.rds')
        saveRDS(x, name)
      }
      eapply(data_env, SAVE_INDIV)
    }
    
    # Extract return_data from each object and combine into one xts object
    FUN = extraction_functions[[return_data]]
    data = do.call(merge, eapply(data_env, FUN))
  }
  
  if(save_data_object == TRUE) {
    # dump data to R binary
    
    dump_data(data, symbols, return_data)
  }
  
  return(data)
}

