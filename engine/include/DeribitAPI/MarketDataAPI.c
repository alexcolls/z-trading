#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "MarketDataAPI.h"


#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)

// Retrieves the summary information such as open interest, 24h volume, etc. for all instruments for the currency (optionally filtered by kind).
//
object_t*
MarketDataAPI_publicGetBookSummaryByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_book_summary_by_currency")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_book_summary_by_currency");




    // query parameters
    char *keyQuery_currency;
    currency_e valueQuery_currency;
    keyValuePair_t *keyPairQuery_currency = 0;
    if (currency)
    {
        keyQuery_currency = strdup("currency");
        valueQuery_currency = (currency);
        keyPairQuery_currency = keyValuePair_create(keyQuery_currency, (void *)valueQuery_currency);
        list_addElement(localVarQueryParameters,keyPairQuery_currency);
    }

    // query parameters
    char *keyQuery_kind;
    kind_e valueQuery_kind;
    keyValuePair_t *keyPairQuery_kind = 0;
    if (kind)
    {
        keyQuery_kind = strdup("kind");
        valueQuery_kind = (kind);
        keyPairQuery_kind = keyValuePair_create(keyQuery_kind, (void *)valueQuery_kind);
        list_addElement(localVarQueryParameters,keyPairQuery_kind);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","");
    }
    //nonprimitive not container
    cJSON *MarketDataAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(MarketDataAPIlocalVarJSON);
    cJSON_Delete(MarketDataAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_currency);
    free(valueQuery_currency);
    keyValuePair_free(keyPairQuery_currency);
    free(keyQuery_kind);
    free(valueQuery_kind);
    keyValuePair_free(keyPairQuery_kind);
    return elementToReturn;
end:
    return NULL;

}

// Retrieves the summary information such as open interest, 24h volume, etc. for a specific instrument.
//
object_t*
MarketDataAPI_publicGetBookSummaryByInstrumentGet(apiClient_t *apiClient ,char * instrument_name)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_book_summary_by_instrument")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_book_summary_by_instrument");




    // query parameters
    char *keyQuery_instrument_name;
    char * valueQuery_instrument_name;
    keyValuePair_t *keyPairQuery_instrument_name = 0;
    if (instrument_name)
    {
        keyQuery_instrument_name = strdup("instrument_name");
        valueQuery_instrument_name = strdup((instrument_name));
        keyPairQuery_instrument_name = keyValuePair_create(keyQuery_instrument_name, valueQuery_instrument_name);
        list_addElement(localVarQueryParameters,keyPairQuery_instrument_name);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","");
    }
    //nonprimitive not container
    cJSON *MarketDataAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(MarketDataAPIlocalVarJSON);
    cJSON_Delete(MarketDataAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_instrument_name);
    free(valueQuery_instrument_name);
    keyValuePair_free(keyPairQuery_instrument_name);
    return elementToReturn;
end:
    return NULL;

}

// Retrieves contract size of provided instrument.
//
object_t*
MarketDataAPI_publicGetContractSizeGet(apiClient_t *apiClient ,char * instrument_name)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_contract_size")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_contract_size");




    // query parameters
    char *keyQuery_instrument_name;
    char * valueQuery_instrument_name;
    keyValuePair_t *keyPairQuery_instrument_name = 0;
    if (instrument_name)
    {
        keyQuery_instrument_name = strdup("instrument_name");
        valueQuery_instrument_name = strdup((instrument_name));
        keyPairQuery_instrument_name = keyValuePair_create(keyQuery_instrument_name, valueQuery_instrument_name);
        list_addElement(localVarQueryParameters,keyPairQuery_instrument_name);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","ok response");
    }
    //nonprimitive not container
    cJSON *MarketDataAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(MarketDataAPIlocalVarJSON);
    cJSON_Delete(MarketDataAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_instrument_name);
    free(valueQuery_instrument_name);
    keyValuePair_free(keyPairQuery_instrument_name);
    return elementToReturn;
end:
    return NULL;

}

// Retrieves all cryptocurrencies supported by the API.
//
object_t*
MarketDataAPI_publicGetCurrenciesGet(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_currencies")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_currencies");



    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","ok response");
    }
    //nonprimitive not container
    cJSON *MarketDataAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(MarketDataAPIlocalVarJSON);
    cJSON_Delete(MarketDataAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    return NULL;

}

// Retrieve the latest user trades that have occurred for PERPETUAL instruments in a specific currency symbol and within given time range.
//
object_t*
MarketDataAPI_publicGetFundingChartDataGet(apiClient_t *apiClient ,char * instrument_name ,length_e length)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_funding_chart_data")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_funding_chart_data");




    // query parameters
    char *keyQuery_instrument_name;
    char * valueQuery_instrument_name;
    keyValuePair_t *keyPairQuery_instrument_name = 0;
    if (instrument_name)
    {
        keyQuery_instrument_name = strdup("instrument_name");
        valueQuery_instrument_name = strdup((instrument_name));
        keyPairQuery_instrument_name = keyValuePair_create(keyQuery_instrument_name, valueQuery_instrument_name);
        list_addElement(localVarQueryParameters,keyPairQuery_instrument_name);
    }

    // query parameters
    char *keyQuery_length;
    length_e valueQuery_length;
    keyValuePair_t *keyPairQuery_length = 0;
    if (length)
    {
        keyQuery_length = strdup("length");
        valueQuery_length = (length);
        keyPairQuery_length = keyValuePair_create(keyQuery_length, (void *)valueQuery_length);
        list_addElement(localVarQueryParameters,keyPairQuery_length);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","");
    }
    //nonprimitive not container
    cJSON *MarketDataAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(MarketDataAPIlocalVarJSON);
    cJSON_Delete(MarketDataAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_instrument_name);
    free(valueQuery_instrument_name);
    keyValuePair_free(keyPairQuery_instrument_name);
    free(keyQuery_length);
    free(valueQuery_length);
    keyValuePair_free(keyPairQuery_length);
    return elementToReturn;
end:
    return NULL;

}

// Provides information about historical volatility for given cryptocurrency.
//
object_t*
MarketDataAPI_publicGetHistoricalVolatilityGet(apiClient_t *apiClient ,currency_e currency)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_historical_volatility")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_historical_volatility");




    // query parameters
    char *keyQuery_currency;
    currency_e valueQuery_currency;
    keyValuePair_t *keyPairQuery_currency = 0;
    if (currency)
    {
        keyQuery_currency = strdup("currency");
        valueQuery_currency = (currency);
        keyPairQuery_currency = keyValuePair_create(keyQuery_currency, (void *)valueQuery_currency);
        list_addElement(localVarQueryParameters,keyPairQuery_currency);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","ok response");
    }
    //nonprimitive not container
    cJSON *MarketDataAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(MarketDataAPIlocalVarJSON);
    cJSON_Delete(MarketDataAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_currency);
    free(valueQuery_currency);
    keyValuePair_free(keyPairQuery_currency);
    return elementToReturn;
end:
    return NULL;

}

// Retrieves the current index price for the instruments, for the selected currency.
//
object_t*
MarketDataAPI_publicGetIndexGet(apiClient_t *apiClient ,currency_e currency)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_index")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_index");




    // query parameters
    char *keyQuery_currency;
    currency_e valueQuery_currency;
    keyValuePair_t *keyPairQuery_currency = 0;
    if (currency)
    {
        keyQuery_currency = strdup("currency");
        valueQuery_currency = (currency);
        keyPairQuery_currency = keyValuePair_create(keyQuery_currency, (void *)valueQuery_currency);
        list_addElement(localVarQueryParameters,keyPairQuery_currency);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","");
    }
    //nonprimitive not container
    cJSON *MarketDataAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(MarketDataAPIlocalVarJSON);
    cJSON_Delete(MarketDataAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_currency);
    free(valueQuery_currency);
    keyValuePair_free(keyPairQuery_currency);
    return elementToReturn;
end:
    return NULL;

}

// Retrieves available trading instruments. This method can be used to see which instruments are available for trading, or which instruments have existed historically.
//
object_t*
MarketDataAPI_publicGetInstrumentsGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind ,int expired)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_instruments")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_instruments");




    // query parameters
    char *keyQuery_currency;
    currency_e valueQuery_currency;
    keyValuePair_t *keyPairQuery_currency = 0;
    if (currency)
    {
        keyQuery_currency = strdup("currency");
        valueQuery_currency = (currency);
        keyPairQuery_currency = keyValuePair_create(keyQuery_currency, (void *)valueQuery_currency);
        list_addElement(localVarQueryParameters,keyPairQuery_currency);
    }

    // query parameters
    char *keyQuery_kind;
    kind_e valueQuery_kind;
    keyValuePair_t *keyPairQuery_kind = 0;
    if (kind)
    {
        keyQuery_kind = strdup("kind");
        valueQuery_kind = (kind);
        keyPairQuery_kind = keyValuePair_create(keyQuery_kind, (void *)valueQuery_kind);
        list_addElement(localVarQueryParameters,keyPairQuery_kind);
    }

    // query parameters
    char *keyQuery_expired;
    int valueQuery_expired;
    keyValuePair_t *keyPairQuery_expired = 0;
    if (expired)
    {
        keyQuery_expired = strdup("expired");
        valueQuery_expired = (expired);
        keyPairQuery_expired = keyValuePair_create(keyQuery_expired, &valueQuery_expired);
        list_addElement(localVarQueryParameters,keyPairQuery_expired);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","ok response");
    }
    //nonprimitive not container
    cJSON *MarketDataAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(MarketDataAPIlocalVarJSON);
    cJSON_Delete(MarketDataAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_currency);
    free(valueQuery_currency);
    keyValuePair_free(keyPairQuery_currency);
    free(keyQuery_kind);
    free(valueQuery_kind);
    keyValuePair_free(keyPairQuery_kind);
    free(keyQuery_expired);
    keyValuePair_free(keyPairQuery_expired);
    return elementToReturn;
end:
    return NULL;

}

// Retrieves historical settlement, delivery and bankruptcy events coming from all instruments within given currency.
//
object_t*
MarketDataAPI_publicGetLastSettlementsByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,type_e type ,int count ,char * continuation ,int search_start_timestamp)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_last_settlements_by_currency")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_last_settlements_by_currency");




    // query parameters
    char *keyQuery_currency;
    currency_e valueQuery_currency;
    keyValuePair_t *keyPairQuery_currency = 0;
    if (currency)
    {
        keyQuery_currency = strdup("currency");
        valueQuery_currency = (currency);
        keyPairQuery_currency = keyValuePair_create(keyQuery_currency, (void *)valueQuery_currency);
        list_addElement(localVarQueryParameters,keyPairQuery_currency);
    }

    // query parameters
    char *keyQuery_type;
    type_e valueQuery_type;
    keyValuePair_t *keyPairQuery_type = 0;
    if (type)
    {
        keyQuery_type = strdup("type");
        valueQuery_type = (type);
        keyPairQuery_type = keyValuePair_create(keyQuery_type, (void *)valueQuery_type);
        list_addElement(localVarQueryParameters,keyPairQuery_type);
    }

    // query parameters
    char *keyQuery_count;
    int valueQuery_count;
    keyValuePair_t *keyPairQuery_count = 0;
    if (count)
    {
        keyQuery_count = strdup("count");
        valueQuery_count = (count);
        keyPairQuery_count = keyValuePair_create(keyQuery_count, &valueQuery_count);
        list_addElement(localVarQueryParameters,keyPairQuery_count);
    }

    // query parameters
    char *keyQuery_continuation;
    char * valueQuery_continuation;
    keyValuePair_t *keyPairQuery_continuation = 0;
    if (continuation)
    {
        keyQuery_continuation = strdup("continuation");
        valueQuery_continuation = strdup((continuation));
        keyPairQuery_continuation = keyValuePair_create(keyQuery_continuation, valueQuery_continuation);
        list_addElement(localVarQueryParameters,keyPairQuery_continuation);
    }

    // query parameters
    char *keyQuery_search_start_timestamp;
    int valueQuery_search_start_timestamp;
    keyValuePair_t *keyPairQuery_search_start_timestamp = 0;
    if (search_start_timestamp)
    {
        keyQuery_search_start_timestamp = strdup("search_start_timestamp");
        valueQuery_search_start_timestamp = (search_start_timestamp);
        keyPairQuery_search_start_timestamp = keyValuePair_create(keyQuery_search_start_timestamp, &valueQuery_search_start_timestamp);
        list_addElement(localVarQueryParameters,keyPairQuery_search_start_timestamp);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","");
    }
    //nonprimitive not container
    cJSON *MarketDataAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(MarketDataAPIlocalVarJSON);
    cJSON_Delete(MarketDataAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_currency);
    free(valueQuery_currency);
    keyValuePair_free(keyPairQuery_currency);
    free(keyQuery_type);
    free(valueQuery_type);
    keyValuePair_free(keyPairQuery_type);
    free(keyQuery_count);
    keyValuePair_free(keyPairQuery_count);
    free(keyQuery_continuation);
    free(valueQuery_continuation);
    keyValuePair_free(keyPairQuery_continuation);
    free(keyQuery_search_start_timestamp);
    keyValuePair_free(keyPairQuery_search_start_timestamp);
    return elementToReturn;
end:
    return NULL;

}

// Retrieves historical public settlement, delivery and bankruptcy events filtered by instrument name.
//
object_t*
MarketDataAPI_publicGetLastSettlementsByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,type_e type ,int count ,char * continuation ,int search_start_timestamp)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_last_settlements_by_instrument")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_last_settlements_by_instrument");




    // query parameters
    char *keyQuery_instrument_name;
    char * valueQuery_instrument_name;
    keyValuePair_t *keyPairQuery_instrument_name = 0;
    if (instrument_name)
    {
        keyQuery_instrument_name = strdup("instrument_name");
        valueQuery_instrument_name = strdup((instrument_name));
        keyPairQuery_instrument_name = keyValuePair_create(keyQuery_instrument_name, valueQuery_instrument_name);
        list_addElement(localVarQueryParameters,keyPairQuery_instrument_name);
    }

    // query parameters
    char *keyQuery_type;
    type_e valueQuery_type;
    keyValuePair_t *keyPairQuery_type = 0;
    if (type)
    {
        keyQuery_type = strdup("type");
        valueQuery_type = (type);
        keyPairQuery_type = keyValuePair_create(keyQuery_type, (void *)valueQuery_type);
        list_addElement(localVarQueryParameters,keyPairQuery_type);
    }

    // query parameters
    char *keyQuery_count;
    int valueQuery_count;
    keyValuePair_t *keyPairQuery_count = 0;
    if (count)
    {
        keyQuery_count = strdup("count");
        valueQuery_count = (count);
        keyPairQuery_count = keyValuePair_create(keyQuery_count, &valueQuery_count);
        list_addElement(localVarQueryParameters,keyPairQuery_count);
    }

    // query parameters
    char *keyQuery_continuation;
    char * valueQuery_continuation;
    keyValuePair_t *keyPairQuery_continuation = 0;
    if (continuation)
    {
        keyQuery_continuation = strdup("continuation");
        valueQuery_continuation = strdup((continuation));
        keyPairQuery_continuation = keyValuePair_create(keyQuery_continuation, valueQuery_continuation);
        list_addElement(localVarQueryParameters,keyPairQuery_continuation);
    }

    // query parameters
    char *keyQuery_search_start_timestamp;
    int valueQuery_search_start_timestamp;
    keyValuePair_t *keyPairQuery_search_start_timestamp = 0;
    if (search_start_timestamp)
    {
        keyQuery_search_start_timestamp = strdup("search_start_timestamp");
        valueQuery_search_start_timestamp = (search_start_timestamp);
        keyPairQuery_search_start_timestamp = keyValuePair_create(keyQuery_search_start_timestamp, &valueQuery_search_start_timestamp);
        list_addElement(localVarQueryParameters,keyPairQuery_search_start_timestamp);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","");
    }
    //nonprimitive not container
    cJSON *MarketDataAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(MarketDataAPIlocalVarJSON);
    cJSON_Delete(MarketDataAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_instrument_name);
    free(valueQuery_instrument_name);
    keyValuePair_free(keyPairQuery_instrument_name);
    free(keyQuery_type);
    free(valueQuery_type);
    keyValuePair_free(keyPairQuery_type);
    free(keyQuery_count);
    keyValuePair_free(keyPairQuery_count);
    free(keyQuery_continuation);
    free(valueQuery_continuation);
    keyValuePair_free(keyPairQuery_continuation);
    free(keyQuery_search_start_timestamp);
    keyValuePair_free(keyPairQuery_search_start_timestamp);
    return elementToReturn;
end:
    return NULL;

}

// Retrieve the latest trades that have occurred for instruments in a specific currency symbol and within given time range.
//
object_t*
MarketDataAPI_publicGetLastTradesByCurrencyAndTimeGet(apiClient_t *apiClient ,currency_e currency ,int start_timestamp ,int end_timestamp ,kind_e kind ,int count ,int include_old ,sorting_e sorting)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_last_trades_by_currency_and_time")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_last_trades_by_currency_and_time");




    // query parameters
    char *keyQuery_currency;
    currency_e valueQuery_currency;
    keyValuePair_t *keyPairQuery_currency = 0;
    if (currency)
    {
        keyQuery_currency = strdup("currency");
        valueQuery_currency = (currency);
        keyPairQuery_currency = keyValuePair_create(keyQuery_currency, (void *)valueQuery_currency);
        list_addElement(localVarQueryParameters,keyPairQuery_currency);
    }

    // query parameters
    char *keyQuery_kind;
    kind_e valueQuery_kind;
    keyValuePair_t *keyPairQuery_kind = 0;
    if (kind)
    {
        keyQuery_kind = strdup("kind");
        valueQuery_kind = (kind);
        keyPairQuery_kind = keyValuePair_create(keyQuery_kind, (void *)valueQuery_kind);
        list_addElement(localVarQueryParameters,keyPairQuery_kind);
    }

    // query parameters
    char *keyQuery_start_timestamp;
    int valueQuery_start_timestamp;
    keyValuePair_t *keyPairQuery_start_timestamp = 0;
    if (start_timestamp)
    {
        keyQuery_start_timestamp = strdup("start_timestamp");
        valueQuery_start_timestamp = (start_timestamp);
        keyPairQuery_start_timestamp = keyValuePair_create(keyQuery_start_timestamp, &valueQuery_start_timestamp);
        list_addElement(localVarQueryParameters,keyPairQuery_start_timestamp);
    }

    // query parameters
    char *keyQuery_end_timestamp;
    int valueQuery_end_timestamp;
    keyValuePair_t *keyPairQuery_end_timestamp = 0;
    if (end_timestamp)
    {
        keyQuery_end_timestamp = strdup("end_timestamp");
        valueQuery_end_timestamp = (end_timestamp);
        keyPairQuery_end_timestamp = keyValuePair_create(keyQuery_end_timestamp, &valueQuery_end_timestamp);
        list_addElement(localVarQueryParameters,keyPairQuery_end_timestamp);
    }

    // query parameters
    char *keyQuery_count;
    int valueQuery_count;
    keyValuePair_t *keyPairQuery_count = 0;
    if (count)
    {
        keyQuery_count = strdup("count");
        valueQuery_count = (count);
        keyPairQuery_count = keyValuePair_create(keyQuery_count, &valueQuery_count);
        list_addElement(localVarQueryParameters,keyPairQuery_count);
    }

    // query parameters
    char *keyQuery_include_old;
    int valueQuery_include_old;
    keyValuePair_t *keyPairQuery_include_old = 0;
    if (include_old)
    {
        keyQuery_include_old = strdup("include_old");
        valueQuery_include_old = (include_old);
        keyPairQuery_include_old = keyValuePair_create(keyQuery_include_old, &valueQuery_include_old);
        list_addElement(localVarQueryParameters,keyPairQuery_include_old);
    }

    // query parameters
    char *keyQuery_sorting;
    sorting_e valueQuery_sorting;
    keyValuePair_t *keyPairQuery_sorting = 0;
    if (sorting)
    {
        keyQuery_sorting = strdup("sorting");
        valueQuery_sorting = (sorting);
        keyPairQuery_sorting = keyValuePair_create(keyQuery_sorting, (void *)valueQuery_sorting);
        list_addElement(localVarQueryParameters,keyPairQuery_sorting);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","");
    }
    //nonprimitive not container
    cJSON *MarketDataAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(MarketDataAPIlocalVarJSON);
    cJSON_Delete(MarketDataAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_currency);
    free(valueQuery_currency);
    keyValuePair_free(keyPairQuery_currency);
    free(keyQuery_kind);
    free(valueQuery_kind);
    keyValuePair_free(keyPairQuery_kind);
    free(keyQuery_start_timestamp);
    keyValuePair_free(keyPairQuery_start_timestamp);
    free(keyQuery_end_timestamp);
    keyValuePair_free(keyPairQuery_end_timestamp);
    free(keyQuery_count);
    keyValuePair_free(keyPairQuery_count);
    free(keyQuery_include_old);
    keyValuePair_free(keyPairQuery_include_old);
    free(keyQuery_sorting);
    free(valueQuery_sorting);
    keyValuePair_free(keyPairQuery_sorting);
    return elementToReturn;
end:
    return NULL;

}

// Retrieve the latest trades that have occurred for instruments in a specific currency symbol.
//
object_t*
MarketDataAPI_publicGetLastTradesByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind ,char * start_id ,char * end_id ,int count ,int include_old ,sorting_e sorting)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_last_trades_by_currency")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_last_trades_by_currency");




    // query parameters
    char *keyQuery_currency;
    currency_e valueQuery_currency;
    keyValuePair_t *keyPairQuery_currency = 0;
    if (currency)
    {
        keyQuery_currency = strdup("currency");
        valueQuery_currency = (currency);
        keyPairQuery_currency = keyValuePair_create(keyQuery_currency, (void *)valueQuery_currency);
        list_addElement(localVarQueryParameters,keyPairQuery_currency);
    }

    // query parameters
    char *keyQuery_kind;
    kind_e valueQuery_kind;
    keyValuePair_t *keyPairQuery_kind = 0;
    if (kind)
    {
        keyQuery_kind = strdup("kind");
        valueQuery_kind = (kind);
        keyPairQuery_kind = keyValuePair_create(keyQuery_kind, (void *)valueQuery_kind);
        list_addElement(localVarQueryParameters,keyPairQuery_kind);
    }

    // query parameters
    char *keyQuery_start_id;
    char * valueQuery_start_id;
    keyValuePair_t *keyPairQuery_start_id = 0;
    if (start_id)
    {
        keyQuery_start_id = strdup("start_id");
        valueQuery_start_id = strdup((start_id));
        keyPairQuery_start_id = keyValuePair_create(keyQuery_start_id, valueQuery_start_id);
        list_addElement(localVarQueryParameters,keyPairQuery_start_id);
    }

    // query parameters
    char *keyQuery_end_id;
    char * valueQuery_end_id;
    keyValuePair_t *keyPairQuery_end_id = 0;
    if (end_id)
    {
        keyQuery_end_id = strdup("end_id");
        valueQuery_end_id = strdup((end_id));
        keyPairQuery_end_id = keyValuePair_create(keyQuery_end_id, valueQuery_end_id);
        list_addElement(localVarQueryParameters,keyPairQuery_end_id);
    }

    // query parameters
    char *keyQuery_count;
    int valueQuery_count;
    keyValuePair_t *keyPairQuery_count = 0;
    if (count)
    {
        keyQuery_count = strdup("count");
        valueQuery_count = (count);
        keyPairQuery_count = keyValuePair_create(keyQuery_count, &valueQuery_count);
        list_addElement(localVarQueryParameters,keyPairQuery_count);
    }

    // query parameters
    char *keyQuery_include_old;
    int valueQuery_include_old;
    keyValuePair_t *keyPairQuery_include_old = 0;
    if (include_old)
    {
        keyQuery_include_old = strdup("include_old");
        valueQuery_include_old = (include_old);
        keyPairQuery_include_old = keyValuePair_create(keyQuery_include_old, &valueQuery_include_old);
        list_addElement(localVarQueryParameters,keyPairQuery_include_old);
    }

    // query parameters
    char *keyQuery_sorting;
    sorting_e valueQuery_sorting;
    keyValuePair_t *keyPairQuery_sorting = 0;
    if (sorting)
    {
        keyQuery_sorting = strdup("sorting");
        valueQuery_sorting = (sorting);
        keyPairQuery_sorting = keyValuePair_create(keyQuery_sorting, (void *)valueQuery_sorting);
        list_addElement(localVarQueryParameters,keyPairQuery_sorting);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","");
    }
    //nonprimitive not container
    cJSON *MarketDataAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(MarketDataAPIlocalVarJSON);
    cJSON_Delete(MarketDataAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_currency);
    free(valueQuery_currency);
    keyValuePair_free(keyPairQuery_currency);
    free(keyQuery_kind);
    free(valueQuery_kind);
    keyValuePair_free(keyPairQuery_kind);
    free(keyQuery_start_id);
    free(valueQuery_start_id);
    keyValuePair_free(keyPairQuery_start_id);
    free(keyQuery_end_id);
    free(valueQuery_end_id);
    keyValuePair_free(keyPairQuery_end_id);
    free(keyQuery_count);
    keyValuePair_free(keyPairQuery_count);
    free(keyQuery_include_old);
    keyValuePair_free(keyPairQuery_include_old);
    free(keyQuery_sorting);
    free(valueQuery_sorting);
    keyValuePair_free(keyPairQuery_sorting);
    return elementToReturn;
end:
    return NULL;

}

// Retrieve the latest trades that have occurred for a specific instrument and within given time range.
//
object_t*
MarketDataAPI_publicGetLastTradesByInstrumentAndTimeGet(apiClient_t *apiClient ,char * instrument_name ,int start_timestamp ,int end_timestamp ,int count ,int include_old ,sorting_e sorting)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_last_trades_by_instrument_and_time")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_last_trades_by_instrument_and_time");




    // query parameters
    char *keyQuery_instrument_name;
    char * valueQuery_instrument_name;
    keyValuePair_t *keyPairQuery_instrument_name = 0;
    if (instrument_name)
    {
        keyQuery_instrument_name = strdup("instrument_name");
        valueQuery_instrument_name = strdup((instrument_name));
        keyPairQuery_instrument_name = keyValuePair_create(keyQuery_instrument_name, valueQuery_instrument_name);
        list_addElement(localVarQueryParameters,keyPairQuery_instrument_name);
    }

    // query parameters
    char *keyQuery_start_timestamp;
    int valueQuery_start_timestamp;
    keyValuePair_t *keyPairQuery_start_timestamp = 0;
    if (start_timestamp)
    {
        keyQuery_start_timestamp = strdup("start_timestamp");
        valueQuery_start_timestamp = (start_timestamp);
        keyPairQuery_start_timestamp = keyValuePair_create(keyQuery_start_timestamp, &valueQuery_start_timestamp);
        list_addElement(localVarQueryParameters,keyPairQuery_start_timestamp);
    }

    // query parameters
    char *keyQuery_end_timestamp;
    int valueQuery_end_timestamp;
    keyValuePair_t *keyPairQuery_end_timestamp = 0;
    if (end_timestamp)
    {
        keyQuery_end_timestamp = strdup("end_timestamp");
        valueQuery_end_timestamp = (end_timestamp);
        keyPairQuery_end_timestamp = keyValuePair_create(keyQuery_end_timestamp, &valueQuery_end_timestamp);
        list_addElement(localVarQueryParameters,keyPairQuery_end_timestamp);
    }

    // query parameters
    char *keyQuery_count;
    int valueQuery_count;
    keyValuePair_t *keyPairQuery_count = 0;
    if (count)
    {
        keyQuery_count = strdup("count");
        valueQuery_count = (count);
        keyPairQuery_count = keyValuePair_create(keyQuery_count, &valueQuery_count);
        list_addElement(localVarQueryParameters,keyPairQuery_count);
    }

    // query parameters
    char *keyQuery_include_old;
    int valueQuery_include_old;
    keyValuePair_t *keyPairQuery_include_old = 0;
    if (include_old)
    {
        keyQuery_include_old = strdup("include_old");
        valueQuery_include_old = (include_old);
        keyPairQuery_include_old = keyValuePair_create(keyQuery_include_old, &valueQuery_include_old);
        list_addElement(localVarQueryParameters,keyPairQuery_include_old);
    }

    // query parameters
    char *keyQuery_sorting;
    sorting_e valueQuery_sorting;
    keyValuePair_t *keyPairQuery_sorting = 0;
    if (sorting)
    {
        keyQuery_sorting = strdup("sorting");
        valueQuery_sorting = (sorting);
        keyPairQuery_sorting = keyValuePair_create(keyQuery_sorting, (void *)valueQuery_sorting);
        list_addElement(localVarQueryParameters,keyPairQuery_sorting);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","");
    }
    //nonprimitive not container
    cJSON *MarketDataAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(MarketDataAPIlocalVarJSON);
    cJSON_Delete(MarketDataAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_instrument_name);
    free(valueQuery_instrument_name);
    keyValuePair_free(keyPairQuery_instrument_name);
    free(keyQuery_start_timestamp);
    keyValuePair_free(keyPairQuery_start_timestamp);
    free(keyQuery_end_timestamp);
    keyValuePair_free(keyPairQuery_end_timestamp);
    free(keyQuery_count);
    keyValuePair_free(keyPairQuery_count);
    free(keyQuery_include_old);
    keyValuePair_free(keyPairQuery_include_old);
    free(keyQuery_sorting);
    free(valueQuery_sorting);
    keyValuePair_free(keyPairQuery_sorting);
    return elementToReturn;
end:
    return NULL;

}

// Retrieve the latest trades that have occurred for a specific instrument.
//
object_t*
MarketDataAPI_publicGetLastTradesByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,int start_seq ,int end_seq ,int count ,int include_old ,sorting_e sorting)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_last_trades_by_instrument")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_last_trades_by_instrument");




    // query parameters
    char *keyQuery_instrument_name;
    char * valueQuery_instrument_name;
    keyValuePair_t *keyPairQuery_instrument_name = 0;
    if (instrument_name)
    {
        keyQuery_instrument_name = strdup("instrument_name");
        valueQuery_instrument_name = strdup((instrument_name));
        keyPairQuery_instrument_name = keyValuePair_create(keyQuery_instrument_name, valueQuery_instrument_name);
        list_addElement(localVarQueryParameters,keyPairQuery_instrument_name);
    }

    // query parameters
    char *keyQuery_start_seq;
    int valueQuery_start_seq;
    keyValuePair_t *keyPairQuery_start_seq = 0;
    if (start_seq)
    {
        keyQuery_start_seq = strdup("start_seq");
        valueQuery_start_seq = (start_seq);
        keyPairQuery_start_seq = keyValuePair_create(keyQuery_start_seq, &valueQuery_start_seq);
        list_addElement(localVarQueryParameters,keyPairQuery_start_seq);
    }

    // query parameters
    char *keyQuery_end_seq;
    int valueQuery_end_seq;
    keyValuePair_t *keyPairQuery_end_seq = 0;
    if (end_seq)
    {
        keyQuery_end_seq = strdup("end_seq");
        valueQuery_end_seq = (end_seq);
        keyPairQuery_end_seq = keyValuePair_create(keyQuery_end_seq, &valueQuery_end_seq);
        list_addElement(localVarQueryParameters,keyPairQuery_end_seq);
    }

    // query parameters
    char *keyQuery_count;
    int valueQuery_count;
    keyValuePair_t *keyPairQuery_count = 0;
    if (count)
    {
        keyQuery_count = strdup("count");
        valueQuery_count = (count);
        keyPairQuery_count = keyValuePair_create(keyQuery_count, &valueQuery_count);
        list_addElement(localVarQueryParameters,keyPairQuery_count);
    }

    // query parameters
    char *keyQuery_include_old;
    int valueQuery_include_old;
    keyValuePair_t *keyPairQuery_include_old = 0;
    if (include_old)
    {
        keyQuery_include_old = strdup("include_old");
        valueQuery_include_old = (include_old);
        keyPairQuery_include_old = keyValuePair_create(keyQuery_include_old, &valueQuery_include_old);
        list_addElement(localVarQueryParameters,keyPairQuery_include_old);
    }

    // query parameters
    char *keyQuery_sorting;
    sorting_e valueQuery_sorting;
    keyValuePair_t *keyPairQuery_sorting = 0;
    if (sorting)
    {
        keyQuery_sorting = strdup("sorting");
        valueQuery_sorting = (sorting);
        keyPairQuery_sorting = keyValuePair_create(keyQuery_sorting, (void *)valueQuery_sorting);
        list_addElement(localVarQueryParameters,keyPairQuery_sorting);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","");
    }
    //nonprimitive not container
    cJSON *MarketDataAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(MarketDataAPIlocalVarJSON);
    cJSON_Delete(MarketDataAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_instrument_name);
    free(valueQuery_instrument_name);
    keyValuePair_free(keyPairQuery_instrument_name);
    free(keyQuery_start_seq);
    keyValuePair_free(keyPairQuery_start_seq);
    free(keyQuery_end_seq);
    keyValuePair_free(keyPairQuery_end_seq);
    free(keyQuery_count);
    keyValuePair_free(keyPairQuery_count);
    free(keyQuery_include_old);
    keyValuePair_free(keyPairQuery_include_old);
    free(keyQuery_sorting);
    free(valueQuery_sorting);
    keyValuePair_free(keyPairQuery_sorting);
    return elementToReturn;
end:
    return NULL;

}

// Retrieves the order book, along with other market values for a given instrument.
//
object_t*
MarketDataAPI_publicGetOrderBookGet(apiClient_t *apiClient ,char * instrument_name ,double depth)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_order_book")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_order_book");




    // query parameters
    char *keyQuery_instrument_name;
    char * valueQuery_instrument_name;
    keyValuePair_t *keyPairQuery_instrument_name = 0;
    if (instrument_name)
    {
        keyQuery_instrument_name = strdup("instrument_name");
        valueQuery_instrument_name = strdup((instrument_name));
        keyPairQuery_instrument_name = keyValuePair_create(keyQuery_instrument_name, valueQuery_instrument_name);
        list_addElement(localVarQueryParameters,keyPairQuery_instrument_name);
    }

    // query parameters
    char *keyQuery_depth;
    double valueQuery_depth;
    keyValuePair_t *keyPairQuery_depth = 0;
    if (depth)
    {
        keyQuery_depth = strdup("depth");
        valueQuery_depth = (depth);
        keyPairQuery_depth = keyValuePair_create(keyQuery_depth, &valueQuery_depth);
        list_addElement(localVarQueryParameters,keyPairQuery_depth);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","");
    }
    //nonprimitive not container
    cJSON *MarketDataAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(MarketDataAPIlocalVarJSON);
    cJSON_Delete(MarketDataAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_instrument_name);
    free(valueQuery_instrument_name);
    keyValuePair_free(keyPairQuery_instrument_name);
    free(keyQuery_depth);
    keyValuePair_free(keyPairQuery_depth);
    return elementToReturn;
end:
    return NULL;

}

// Retrieves aggregated 24h trade volumes for different instrument types and currencies.
//
object_t*
MarketDataAPI_publicGetTradeVolumesGet(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_trade_volumes")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_trade_volumes");



    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","");
    }
    //nonprimitive not container
    cJSON *MarketDataAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(MarketDataAPIlocalVarJSON);
    cJSON_Delete(MarketDataAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    return NULL;

}

// Publicly available market data used to generate a TradingView candle chart.
//
object_t*
MarketDataAPI_publicGetTradingviewChartDataGet(apiClient_t *apiClient ,char * instrument_name ,int start_timestamp ,int end_timestamp)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_tradingview_chart_data")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_tradingview_chart_data");




    // query parameters
    char *keyQuery_instrument_name;
    char * valueQuery_instrument_name;
    keyValuePair_t *keyPairQuery_instrument_name = 0;
    if (instrument_name)
    {
        keyQuery_instrument_name = strdup("instrument_name");
        valueQuery_instrument_name = strdup((instrument_name));
        keyPairQuery_instrument_name = keyValuePair_create(keyQuery_instrument_name, valueQuery_instrument_name);
        list_addElement(localVarQueryParameters,keyPairQuery_instrument_name);
    }

    // query parameters
    char *keyQuery_start_timestamp;
    int valueQuery_start_timestamp;
    keyValuePair_t *keyPairQuery_start_timestamp = 0;
    if (start_timestamp)
    {
        keyQuery_start_timestamp = strdup("start_timestamp");
        valueQuery_start_timestamp = (start_timestamp);
        keyPairQuery_start_timestamp = keyValuePair_create(keyQuery_start_timestamp, &valueQuery_start_timestamp);
        list_addElement(localVarQueryParameters,keyPairQuery_start_timestamp);
    }

    // query parameters
    char *keyQuery_end_timestamp;
    int valueQuery_end_timestamp;
    keyValuePair_t *keyPairQuery_end_timestamp = 0;
    if (end_timestamp)
    {
        keyQuery_end_timestamp = strdup("end_timestamp");
        valueQuery_end_timestamp = (end_timestamp);
        keyPairQuery_end_timestamp = keyValuePair_create(keyQuery_end_timestamp, &valueQuery_end_timestamp);
        list_addElement(localVarQueryParameters,keyPairQuery_end_timestamp);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","");
    }
    //nonprimitive not container
    cJSON *MarketDataAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(MarketDataAPIlocalVarJSON);
    cJSON_Delete(MarketDataAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_instrument_name);
    free(valueQuery_instrument_name);
    keyValuePair_free(keyPairQuery_instrument_name);
    free(keyQuery_start_timestamp);
    keyValuePair_free(keyPairQuery_start_timestamp);
    free(keyQuery_end_timestamp);
    keyValuePair_free(keyPairQuery_end_timestamp);
    return elementToReturn;
end:
    return NULL;

}

// Get ticker for an instrument.
//
object_t*
MarketDataAPI_publicTickerGet(apiClient_t *apiClient ,char * instrument_name)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/ticker")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/ticker");




    // query parameters
    char *keyQuery_instrument_name;
    char * valueQuery_instrument_name;
    keyValuePair_t *keyPairQuery_instrument_name = 0;
    if (instrument_name)
    {
        keyQuery_instrument_name = strdup("instrument_name");
        valueQuery_instrument_name = strdup((instrument_name));
        keyPairQuery_instrument_name = keyValuePair_create(keyQuery_instrument_name, valueQuery_instrument_name);
        list_addElement(localVarQueryParameters,keyPairQuery_instrument_name);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","ok response");
    }
    //nonprimitive not container
    cJSON *MarketDataAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(MarketDataAPIlocalVarJSON);
    cJSON_Delete(MarketDataAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(keyQuery_instrument_name);
    free(valueQuery_instrument_name);
    keyValuePair_free(keyPairQuery_instrument_name);
    return elementToReturn;
end:
    return NULL;

}

