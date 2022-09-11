#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/object.h"


// Retrieves the summary information such as open interest, 24h volume, etc. for all instruments for the currency (optionally filtered by kind).
//
object_t*
MarketDataAPI_publicGetBookSummaryByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind);


// Retrieves the summary information such as open interest, 24h volume, etc. for a specific instrument.
//
object_t*
MarketDataAPI_publicGetBookSummaryByInstrumentGet(apiClient_t *apiClient ,char * instrument_name);


// Retrieves contract size of provided instrument.
//
object_t*
MarketDataAPI_publicGetContractSizeGet(apiClient_t *apiClient ,char * instrument_name);


// Retrieves all cryptocurrencies supported by the API.
//
object_t*
MarketDataAPI_publicGetCurrenciesGet(apiClient_t *apiClient);


// Retrieve the latest user trades that have occurred for PERPETUAL instruments in a specific currency symbol and within given time range.
//
object_t*
MarketDataAPI_publicGetFundingChartDataGet(apiClient_t *apiClient ,char * instrument_name ,length_e length);


// Provides information about historical volatility for given cryptocurrency.
//
object_t*
MarketDataAPI_publicGetHistoricalVolatilityGet(apiClient_t *apiClient ,currency_e currency);


// Retrieves the current index price for the instruments, for the selected currency.
//
object_t*
MarketDataAPI_publicGetIndexGet(apiClient_t *apiClient ,currency_e currency);


// Retrieves available trading instruments. This method can be used to see which instruments are available for trading, or which instruments have existed historically.
//
object_t*
MarketDataAPI_publicGetInstrumentsGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind ,int expired);


// Retrieves historical settlement, delivery and bankruptcy events coming from all instruments within given currency.
//
object_t*
MarketDataAPI_publicGetLastSettlementsByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,type_e type ,int count ,char * continuation ,int search_start_timestamp);


// Retrieves historical public settlement, delivery and bankruptcy events filtered by instrument name.
//
object_t*
MarketDataAPI_publicGetLastSettlementsByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,type_e type ,int count ,char * continuation ,int search_start_timestamp);


// Retrieve the latest trades that have occurred for instruments in a specific currency symbol and within given time range.
//
object_t*
MarketDataAPI_publicGetLastTradesByCurrencyAndTimeGet(apiClient_t *apiClient ,currency_e currency ,int start_timestamp ,int end_timestamp ,kind_e kind ,int count ,int include_old ,sorting_e sorting);


// Retrieve the latest trades that have occurred for instruments in a specific currency symbol.
//
object_t*
MarketDataAPI_publicGetLastTradesByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind ,char * start_id ,char * end_id ,int count ,int include_old ,sorting_e sorting);


// Retrieve the latest trades that have occurred for a specific instrument and within given time range.
//
object_t*
MarketDataAPI_publicGetLastTradesByInstrumentAndTimeGet(apiClient_t *apiClient ,char * instrument_name ,int start_timestamp ,int end_timestamp ,int count ,int include_old ,sorting_e sorting);


// Retrieve the latest trades that have occurred for a specific instrument.
//
object_t*
MarketDataAPI_publicGetLastTradesByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,int start_seq ,int end_seq ,int count ,int include_old ,sorting_e sorting);


// Retrieves the order book, along with other market values for a given instrument.
//
object_t*
MarketDataAPI_publicGetOrderBookGet(apiClient_t *apiClient ,char * instrument_name ,double depth);


// Retrieves aggregated 24h trade volumes for different instrument types and currencies.
//
object_t*
MarketDataAPI_publicGetTradeVolumesGet(apiClient_t *apiClient);


// Publicly available market data used to generate a TradingView candle chart.
//
object_t*
MarketDataAPI_publicGetTradingviewChartDataGet(apiClient_t *apiClient ,char * instrument_name ,int start_timestamp ,int end_timestamp);


// Get ticker for an instrument.
//
object_t*
MarketDataAPI_publicTickerGet(apiClient_t *apiClient ,char * instrument_name);


