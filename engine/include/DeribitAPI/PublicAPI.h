#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/object.h"


// Authenticate
//
// Retrieve an Oauth access token, to be used for authentication of 'private' requests.  Three methods of authentication are supported:  - <code>password</code> - using email and and password as when logging on to the website - <code>client_credentials</code> - using the access key and access secret that can be found on the API page on the website - <code>client_signature</code> - using the access key that can be found on the API page on the website and user generated signature. The signature is calculated using some fields provided in the request, using formula described here [Deribit signature credentials](#additional-authorization-method-deribit-signature-credentials) - <code>refresh_token</code> - using a refresh token that was received from an earlier invocation  The response will contain an access token, expiration period (number of seconds that the token is valid) and a refresh token that can be used to get a new set of tokens. 
//
object_t*
PublicAPI_publicAuthGet(apiClient_t *apiClient ,grant_type_e grant_type ,char * username ,char * password ,char * client_id ,char * client_secret ,char * refresh_token ,char * timestamp ,char * signature ,char * nonce ,char * state ,char * scope);


// Retrieves announcements from the last 30 days.
//
object_t*
PublicAPI_publicGetAnnouncementsGet(apiClient_t *apiClient);


// Retrieves the summary information such as open interest, 24h volume, etc. for all instruments for the currency (optionally filtered by kind).
//
object_t*
PublicAPI_publicGetBookSummaryByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind);


// Retrieves the summary information such as open interest, 24h volume, etc. for a specific instrument.
//
object_t*
PublicAPI_publicGetBookSummaryByInstrumentGet(apiClient_t *apiClient ,char * instrument_name);


// Retrieves contract size of provided instrument.
//
object_t*
PublicAPI_publicGetContractSizeGet(apiClient_t *apiClient ,char * instrument_name);


// Retrieves all cryptocurrencies supported by the API.
//
object_t*
PublicAPI_publicGetCurrenciesGet(apiClient_t *apiClient);


// Retrieve the latest user trades that have occurred for PERPETUAL instruments in a specific currency symbol and within given time range.
//
object_t*
PublicAPI_publicGetFundingChartDataGet(apiClient_t *apiClient ,char * instrument_name ,length_e length);


// Provides information about historical volatility for given cryptocurrency.
//
object_t*
PublicAPI_publicGetHistoricalVolatilityGet(apiClient_t *apiClient ,currency_e currency);


// Retrieves the current index price for the instruments, for the selected currency.
//
object_t*
PublicAPI_publicGetIndexGet(apiClient_t *apiClient ,currency_e currency);


// Retrieves available trading instruments. This method can be used to see which instruments are available for trading, or which instruments have existed historically.
//
object_t*
PublicAPI_publicGetInstrumentsGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind ,int expired);


// Retrieves historical settlement, delivery and bankruptcy events coming from all instruments within given currency.
//
object_t*
PublicAPI_publicGetLastSettlementsByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,type_e type ,int count ,char * continuation ,int search_start_timestamp);


// Retrieves historical public settlement, delivery and bankruptcy events filtered by instrument name.
//
object_t*
PublicAPI_publicGetLastSettlementsByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,type_e type ,int count ,char * continuation ,int search_start_timestamp);


// Retrieve the latest trades that have occurred for instruments in a specific currency symbol and within given time range.
//
object_t*
PublicAPI_publicGetLastTradesByCurrencyAndTimeGet(apiClient_t *apiClient ,currency_e currency ,int start_timestamp ,int end_timestamp ,kind_e kind ,int count ,int include_old ,sorting_e sorting);


// Retrieve the latest trades that have occurred for instruments in a specific currency symbol.
//
object_t*
PublicAPI_publicGetLastTradesByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind ,char * start_id ,char * end_id ,int count ,int include_old ,sorting_e sorting);


// Retrieve the latest trades that have occurred for a specific instrument and within given time range.
//
object_t*
PublicAPI_publicGetLastTradesByInstrumentAndTimeGet(apiClient_t *apiClient ,char * instrument_name ,int start_timestamp ,int end_timestamp ,int count ,int include_old ,sorting_e sorting);


// Retrieve the latest trades that have occurred for a specific instrument.
//
object_t*
PublicAPI_publicGetLastTradesByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,int start_seq ,int end_seq ,int count ,int include_old ,sorting_e sorting);


// Retrieves the order book, along with other market values for a given instrument.
//
object_t*
PublicAPI_publicGetOrderBookGet(apiClient_t *apiClient ,char * instrument_name ,double depth);


// Retrieves the current time (in milliseconds). This API endpoint can be used to check the clock skew between your software and Deribit's systems.
//
object_t*
PublicAPI_publicGetTimeGet(apiClient_t *apiClient);


// Retrieves aggregated 24h trade volumes for different instrument types and currencies.
//
object_t*
PublicAPI_publicGetTradeVolumesGet(apiClient_t *apiClient);


// Publicly available market data used to generate a TradingView candle chart.
//
object_t*
PublicAPI_publicGetTradingviewChartDataGet(apiClient_t *apiClient ,char * instrument_name ,int start_timestamp ,int end_timestamp);


// Tests the connection to the API server, and returns its version. You can use this to make sure the API is reachable, and matches the expected version.
//
object_t*
PublicAPI_publicTestGet(apiClient_t *apiClient ,expected_result_e expected_result);


// Get ticker for an instrument.
//
object_t*
PublicAPI_publicTickerGet(apiClient_t *apiClient ,char * instrument_name);


// Method used to introduce the client software connected to Deribit platform over websocket. Provided data may have an impact on the maintained connection and will be collected for internal statistical purposes. In response, Deribit will also introduce itself.
//
object_t*
PublicAPI_publicValidateFieldGet(apiClient_t *apiClient ,char * field ,char * value ,char * value2);


