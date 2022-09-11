#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "PublicAPI.h"


#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)

// Authenticate
//
// Retrieve an Oauth access token, to be used for authentication of 'private' requests.  Three methods of authentication are supported:  - <code>password</code> - using email and and password as when logging on to the website - <code>client_credentials</code> - using the access key and access secret that can be found on the API page on the website - <code>client_signature</code> - using the access key that can be found on the API page on the website and user generated signature. The signature is calculated using some fields provided in the request, using formula described here [Deribit signature credentials](#additional-authorization-method-deribit-signature-credentials) - <code>refresh_token</code> - using a refresh token that was received from an earlier invocation  The response will contain an access token, expiration period (number of seconds that the token is valid) and a refresh token that can be used to get a new set of tokens. 
//
object_t*
PublicAPI_publicAuthGet(apiClient_t *apiClient ,grant_type_e grant_type ,char * username ,char * password ,char * client_id ,char * client_secret ,char * refresh_token ,char * timestamp ,char * signature ,char * nonce ,char * state ,char * scope)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/auth")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/auth");




    // query parameters
    char *keyQuery_grant_type;
    grant_type_e valueQuery_grant_type;
    keyValuePair_t *keyPairQuery_grant_type = 0;
    if (grant_type)
    {
        keyQuery_grant_type = strdup("grant_type");
        valueQuery_grant_type = (grant_type);
        keyPairQuery_grant_type = keyValuePair_create(keyQuery_grant_type, (void *)valueQuery_grant_type);
        list_addElement(localVarQueryParameters,keyPairQuery_grant_type);
    }

    // query parameters
    char *keyQuery_username;
    char * valueQuery_username;
    keyValuePair_t *keyPairQuery_username = 0;
    if (username)
    {
        keyQuery_username = strdup("username");
        valueQuery_username = strdup((username));
        keyPairQuery_username = keyValuePair_create(keyQuery_username, valueQuery_username);
        list_addElement(localVarQueryParameters,keyPairQuery_username);
    }

    // query parameters
    char *keyQuery_password;
    char * valueQuery_password;
    keyValuePair_t *keyPairQuery_password = 0;
    if (password)
    {
        keyQuery_password = strdup("password");
        valueQuery_password = strdup((password));
        keyPairQuery_password = keyValuePair_create(keyQuery_password, valueQuery_password);
        list_addElement(localVarQueryParameters,keyPairQuery_password);
    }

    // query parameters
    char *keyQuery_client_id;
    char * valueQuery_client_id;
    keyValuePair_t *keyPairQuery_client_id = 0;
    if (client_id)
    {
        keyQuery_client_id = strdup("client_id");
        valueQuery_client_id = strdup((client_id));
        keyPairQuery_client_id = keyValuePair_create(keyQuery_client_id, valueQuery_client_id);
        list_addElement(localVarQueryParameters,keyPairQuery_client_id);
    }

    // query parameters
    char *keyQuery_client_secret;
    char * valueQuery_client_secret;
    keyValuePair_t *keyPairQuery_client_secret = 0;
    if (client_secret)
    {
        keyQuery_client_secret = strdup("client_secret");
        valueQuery_client_secret = strdup((client_secret));
        keyPairQuery_client_secret = keyValuePair_create(keyQuery_client_secret, valueQuery_client_secret);
        list_addElement(localVarQueryParameters,keyPairQuery_client_secret);
    }

    // query parameters
    char *keyQuery_refresh_token;
    char * valueQuery_refresh_token;
    keyValuePair_t *keyPairQuery_refresh_token = 0;
    if (refresh_token)
    {
        keyQuery_refresh_token = strdup("refresh_token");
        valueQuery_refresh_token = strdup((refresh_token));
        keyPairQuery_refresh_token = keyValuePair_create(keyQuery_refresh_token, valueQuery_refresh_token);
        list_addElement(localVarQueryParameters,keyPairQuery_refresh_token);
    }

    // query parameters
    char *keyQuery_timestamp;
    char * valueQuery_timestamp;
    keyValuePair_t *keyPairQuery_timestamp = 0;
    if (timestamp)
    {
        keyQuery_timestamp = strdup("timestamp");
        valueQuery_timestamp = strdup((timestamp));
        keyPairQuery_timestamp = keyValuePair_create(keyQuery_timestamp, valueQuery_timestamp);
        list_addElement(localVarQueryParameters,keyPairQuery_timestamp);
    }

    // query parameters
    char *keyQuery_signature;
    char * valueQuery_signature;
    keyValuePair_t *keyPairQuery_signature = 0;
    if (signature)
    {
        keyQuery_signature = strdup("signature");
        valueQuery_signature = strdup((signature));
        keyPairQuery_signature = keyValuePair_create(keyQuery_signature, valueQuery_signature);
        list_addElement(localVarQueryParameters,keyPairQuery_signature);
    }

    // query parameters
    char *keyQuery_nonce;
    char * valueQuery_nonce;
    keyValuePair_t *keyPairQuery_nonce = 0;
    if (nonce)
    {
        keyQuery_nonce = strdup("nonce");
        valueQuery_nonce = strdup((nonce));
        keyPairQuery_nonce = keyValuePair_create(keyQuery_nonce, valueQuery_nonce);
        list_addElement(localVarQueryParameters,keyPairQuery_nonce);
    }

    // query parameters
    char *keyQuery_state;
    char * valueQuery_state;
    keyValuePair_t *keyPairQuery_state = 0;
    if (state)
    {
        keyQuery_state = strdup("state");
        valueQuery_state = strdup((state));
        keyPairQuery_state = keyValuePair_create(keyQuery_state, valueQuery_state);
        list_addElement(localVarQueryParameters,keyPairQuery_state);
    }

    // query parameters
    char *keyQuery_scope;
    char * valueQuery_scope;
    keyValuePair_t *keyPairQuery_scope = 0;
    if (scope)
    {
        keyQuery_scope = strdup("scope");
        valueQuery_scope = strdup((scope));
        keyPairQuery_scope = keyValuePair_create(keyQuery_scope, valueQuery_scope);
        list_addElement(localVarQueryParameters,keyPairQuery_scope);
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
    if (apiClient->response_code == 429) {
        printf("%s\n","over limit");
    }
    //nonprimitive not container
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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
    free(keyQuery_grant_type);
    free(valueQuery_grant_type);
    keyValuePair_free(keyPairQuery_grant_type);
    free(keyQuery_username);
    free(valueQuery_username);
    keyValuePair_free(keyPairQuery_username);
    free(keyQuery_password);
    free(valueQuery_password);
    keyValuePair_free(keyPairQuery_password);
    free(keyQuery_client_id);
    free(valueQuery_client_id);
    keyValuePair_free(keyPairQuery_client_id);
    free(keyQuery_client_secret);
    free(valueQuery_client_secret);
    keyValuePair_free(keyPairQuery_client_secret);
    free(keyQuery_refresh_token);
    free(valueQuery_refresh_token);
    keyValuePair_free(keyPairQuery_refresh_token);
    free(keyQuery_timestamp);
    free(valueQuery_timestamp);
    keyValuePair_free(keyPairQuery_timestamp);
    free(keyQuery_signature);
    free(valueQuery_signature);
    keyValuePair_free(keyPairQuery_signature);
    free(keyQuery_nonce);
    free(valueQuery_nonce);
    keyValuePair_free(keyPairQuery_nonce);
    free(keyQuery_state);
    free(valueQuery_state);
    keyValuePair_free(keyPairQuery_state);
    free(keyQuery_scope);
    free(valueQuery_scope);
    keyValuePair_free(keyPairQuery_scope);
    return elementToReturn;
end:
    return NULL;

}

// Retrieves announcements from the last 30 days.
//
object_t*
PublicAPI_publicGetAnnouncementsGet(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_announcements")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_announcements");



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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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

// Retrieves the summary information such as open interest, 24h volume, etc. for all instruments for the currency (optionally filtered by kind).
//
object_t*
PublicAPI_publicGetBookSummaryByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind)
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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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
PublicAPI_publicGetBookSummaryByInstrumentGet(apiClient_t *apiClient ,char * instrument_name)
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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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
PublicAPI_publicGetContractSizeGet(apiClient_t *apiClient ,char * instrument_name)
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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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
PublicAPI_publicGetCurrenciesGet(apiClient_t *apiClient)
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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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
PublicAPI_publicGetFundingChartDataGet(apiClient_t *apiClient ,char * instrument_name ,length_e length)
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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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
PublicAPI_publicGetHistoricalVolatilityGet(apiClient_t *apiClient ,currency_e currency)
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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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
PublicAPI_publicGetIndexGet(apiClient_t *apiClient ,currency_e currency)
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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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
PublicAPI_publicGetInstrumentsGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind ,int expired)
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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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
PublicAPI_publicGetLastSettlementsByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,type_e type ,int count ,char * continuation ,int search_start_timestamp)
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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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
PublicAPI_publicGetLastSettlementsByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,type_e type ,int count ,char * continuation ,int search_start_timestamp)
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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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
PublicAPI_publicGetLastTradesByCurrencyAndTimeGet(apiClient_t *apiClient ,currency_e currency ,int start_timestamp ,int end_timestamp ,kind_e kind ,int count ,int include_old ,sorting_e sorting)
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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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
PublicAPI_publicGetLastTradesByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind ,char * start_id ,char * end_id ,int count ,int include_old ,sorting_e sorting)
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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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
PublicAPI_publicGetLastTradesByInstrumentAndTimeGet(apiClient_t *apiClient ,char * instrument_name ,int start_timestamp ,int end_timestamp ,int count ,int include_old ,sorting_e sorting)
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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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
PublicAPI_publicGetLastTradesByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,int start_seq ,int end_seq ,int count ,int include_old ,sorting_e sorting)
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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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
PublicAPI_publicGetOrderBookGet(apiClient_t *apiClient ,char * instrument_name ,double depth)
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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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

// Retrieves the current time (in milliseconds). This API endpoint can be used to check the clock skew between your software and Deribit's systems.
//
object_t*
PublicAPI_publicGetTimeGet(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_time")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_time");



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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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

// Retrieves aggregated 24h trade volumes for different instrument types and currencies.
//
object_t*
PublicAPI_publicGetTradeVolumesGet(apiClient_t *apiClient)
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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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
PublicAPI_publicGetTradingviewChartDataGet(apiClient_t *apiClient ,char * instrument_name ,int start_timestamp ,int end_timestamp)
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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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

// Tests the connection to the API server, and returns its version. You can use this to make sure the API is reachable, and matches the expected version.
//
object_t*
PublicAPI_publicTestGet(apiClient_t *apiClient ,expected_result_e expected_result)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/test")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/test");




    // query parameters
    char *keyQuery_expected_result;
    expected_result_e valueQuery_expected_result;
    keyValuePair_t *keyPairQuery_expected_result = 0;
    if (expected_result)
    {
        keyQuery_expected_result = strdup("expected_result");
        valueQuery_expected_result = (expected_result);
        keyPairQuery_expected_result = keyValuePair_create(keyQuery_expected_result, (void *)valueQuery_expected_result);
        list_addElement(localVarQueryParameters,keyPairQuery_expected_result);
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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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
    free(keyQuery_expected_result);
    free(valueQuery_expected_result);
    keyValuePair_free(keyPairQuery_expected_result);
    return elementToReturn;
end:
    return NULL;

}

// Get ticker for an instrument.
//
object_t*
PublicAPI_publicTickerGet(apiClient_t *apiClient ,char * instrument_name)
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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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

// Method used to introduce the client software connected to Deribit platform over websocket. Provided data may have an impact on the maintained connection and will be collected for internal statistical purposes. In response, Deribit will also introduce itself.
//
object_t*
PublicAPI_publicValidateFieldGet(apiClient_t *apiClient ,char * field ,char * value ,char * value2)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/validate_field")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/validate_field");




    // query parameters
    char *keyQuery_field;
    char * valueQuery_field;
    keyValuePair_t *keyPairQuery_field = 0;
    if (field)
    {
        keyQuery_field = strdup("field");
        valueQuery_field = strdup((field));
        keyPairQuery_field = keyValuePair_create(keyQuery_field, valueQuery_field);
        list_addElement(localVarQueryParameters,keyPairQuery_field);
    }

    // query parameters
    char *keyQuery_value;
    char * valueQuery_value;
    keyValuePair_t *keyPairQuery_value = 0;
    if (value)
    {
        keyQuery_value = strdup("value");
        valueQuery_value = strdup((value));
        keyPairQuery_value = keyValuePair_create(keyQuery_value, valueQuery_value);
        list_addElement(localVarQueryParameters,keyPairQuery_value);
    }

    // query parameters
    char *keyQuery_value2;
    char * valueQuery_value2;
    keyValuePair_t *keyPairQuery_value2 = 0;
    if (value2)
    {
        keyQuery_value2 = strdup("value2");
        valueQuery_value2 = strdup((value2));
        keyPairQuery_value2 = keyValuePair_create(keyQuery_value2, valueQuery_value2);
        list_addElement(localVarQueryParameters,keyPairQuery_value2);
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
    cJSON *PublicAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PublicAPIlocalVarJSON);
    cJSON_Delete(PublicAPIlocalVarJSON);
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
    free(keyQuery_field);
    free(valueQuery_field);
    keyValuePair_free(keyPairQuery_field);
    free(keyQuery_value);
    free(valueQuery_value);
    keyValuePair_free(keyPairQuery_value);
    free(keyQuery_value2);
    free(valueQuery_value2);
    keyValuePair_free(keyPairQuery_value2);
    return elementToReturn;
end:
    return NULL;

}

