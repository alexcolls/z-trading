#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "WalletAPI.h"


#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)

// Adds new entry to address book of given type
//
object_t*
WalletAPI_privateAddToAddressBookGet(apiClient_t *apiClient ,currency_e currency ,type_e type ,char * address ,char * name ,char * tfa)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/add_to_address_book")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/add_to_address_book");




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
    char *keyQuery_address;
    char * valueQuery_address;
    keyValuePair_t *keyPairQuery_address = 0;
    if (address)
    {
        keyQuery_address = strdup("address");
        valueQuery_address = strdup((address));
        keyPairQuery_address = keyValuePair_create(keyQuery_address, valueQuery_address);
        list_addElement(localVarQueryParameters,keyPairQuery_address);
    }

    // query parameters
    char *keyQuery_name;
    char * valueQuery_name;
    keyValuePair_t *keyPairQuery_name = 0;
    if (name)
    {
        keyQuery_name = strdup("name");
        valueQuery_name = strdup((name));
        keyPairQuery_name = keyValuePair_create(keyQuery_name, valueQuery_name);
        list_addElement(localVarQueryParameters,keyPairQuery_name);
    }

    // query parameters
    char *keyQuery_tfa;
    char * valueQuery_tfa;
    keyValuePair_t *keyPairQuery_tfa = 0;
    if (tfa)
    {
        keyQuery_tfa = strdup("tfa");
        valueQuery_tfa = strdup((tfa));
        keyPairQuery_tfa = keyValuePair_create(keyQuery_tfa, valueQuery_tfa);
        list_addElement(localVarQueryParameters,keyPairQuery_tfa);
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
    cJSON *WalletAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(WalletAPIlocalVarJSON);
    cJSON_Delete(WalletAPIlocalVarJSON);
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
    free(keyQuery_address);
    free(valueQuery_address);
    keyValuePair_free(keyPairQuery_address);
    free(keyQuery_name);
    free(valueQuery_name);
    keyValuePair_free(keyPairQuery_name);
    free(keyQuery_tfa);
    free(valueQuery_tfa);
    keyValuePair_free(keyPairQuery_tfa);
    return elementToReturn;
end:
    return NULL;

}

// Cancel transfer
//
object_t*
WalletAPI_privateCancelTransferByIdGet(apiClient_t *apiClient ,currency_e currency ,int id ,char * tfa)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/cancel_transfer_by_id")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/cancel_transfer_by_id");




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
    char *keyQuery_id;
    int valueQuery_id;
    keyValuePair_t *keyPairQuery_id = 0;
    if (id)
    {
        keyQuery_id = strdup("id");
        valueQuery_id = (id);
        keyPairQuery_id = keyValuePair_create(keyQuery_id, &valueQuery_id);
        list_addElement(localVarQueryParameters,keyPairQuery_id);
    }

    // query parameters
    char *keyQuery_tfa;
    char * valueQuery_tfa;
    keyValuePair_t *keyPairQuery_tfa = 0;
    if (tfa)
    {
        keyQuery_tfa = strdup("tfa");
        valueQuery_tfa = strdup((tfa));
        keyPairQuery_tfa = keyValuePair_create(keyQuery_tfa, valueQuery_tfa);
        list_addElement(localVarQueryParameters,keyPairQuery_tfa);
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
    cJSON *WalletAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(WalletAPIlocalVarJSON);
    cJSON_Delete(WalletAPIlocalVarJSON);
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
    free(keyQuery_id);
    keyValuePair_free(keyPairQuery_id);
    free(keyQuery_tfa);
    free(valueQuery_tfa);
    keyValuePair_free(keyPairQuery_tfa);
    return elementToReturn;
end:
    return NULL;

}

// Cancels withdrawal request
//
object_t*
WalletAPI_privateCancelWithdrawalGet(apiClient_t *apiClient ,currency_e currency ,double id)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/cancel_withdrawal")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/cancel_withdrawal");




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
    char *keyQuery_id;
    double valueQuery_id;
    keyValuePair_t *keyPairQuery_id = 0;
    if (id)
    {
        keyQuery_id = strdup("id");
        valueQuery_id = (id);
        keyPairQuery_id = keyValuePair_create(keyQuery_id, &valueQuery_id);
        list_addElement(localVarQueryParameters,keyPairQuery_id);
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
    cJSON *WalletAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(WalletAPIlocalVarJSON);
    cJSON_Delete(WalletAPIlocalVarJSON);
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
    free(keyQuery_id);
    keyValuePair_free(keyPairQuery_id);
    return elementToReturn;
end:
    return NULL;

}

// Creates deposit address in currency
//
object_t*
WalletAPI_privateCreateDepositAddressGet(apiClient_t *apiClient ,currency_e currency)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/create_deposit_address")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/create_deposit_address");




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
    cJSON *WalletAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(WalletAPIlocalVarJSON);
    cJSON_Delete(WalletAPIlocalVarJSON);
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

// Retrieves address book of given type
//
object_t*
WalletAPI_privateGetAddressBookGet(apiClient_t *apiClient ,currency_e currency ,type_e type)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_address_book")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_address_book");




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
    cJSON *WalletAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(WalletAPIlocalVarJSON);
    cJSON_Delete(WalletAPIlocalVarJSON);
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
    return elementToReturn;
end:
    return NULL;

}

// Retrieve deposit address for currency
//
object_t*
WalletAPI_privateGetCurrentDepositAddressGet(apiClient_t *apiClient ,currency_e currency)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_current_deposit_address")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_current_deposit_address");




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
    cJSON *WalletAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(WalletAPIlocalVarJSON);
    cJSON_Delete(WalletAPIlocalVarJSON);
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

// Retrieve the latest users deposits
//
object_t*
WalletAPI_privateGetDepositsGet(apiClient_t *apiClient ,currency_e currency ,int count ,int offset)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_deposits")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_deposits");




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
    char *keyQuery_offset;
    int valueQuery_offset;
    keyValuePair_t *keyPairQuery_offset = 0;
    if (offset)
    {
        keyQuery_offset = strdup("offset");
        valueQuery_offset = (offset);
        keyPairQuery_offset = keyValuePair_create(keyQuery_offset, &valueQuery_offset);
        list_addElement(localVarQueryParameters,keyPairQuery_offset);
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
    cJSON *WalletAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(WalletAPIlocalVarJSON);
    cJSON_Delete(WalletAPIlocalVarJSON);
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
    free(keyQuery_count);
    keyValuePair_free(keyPairQuery_count);
    free(keyQuery_offset);
    keyValuePair_free(keyPairQuery_offset);
    return elementToReturn;
end:
    return NULL;

}

// Adds new entry to address book of given type
//
object_t*
WalletAPI_privateGetTransfersGet(apiClient_t *apiClient ,currency_e currency ,int count ,int offset)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_transfers")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_transfers");




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
    char *keyQuery_offset;
    int valueQuery_offset;
    keyValuePair_t *keyPairQuery_offset = 0;
    if (offset)
    {
        keyQuery_offset = strdup("offset");
        valueQuery_offset = (offset);
        keyPairQuery_offset = keyValuePair_create(keyQuery_offset, &valueQuery_offset);
        list_addElement(localVarQueryParameters,keyPairQuery_offset);
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
    cJSON *WalletAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(WalletAPIlocalVarJSON);
    cJSON_Delete(WalletAPIlocalVarJSON);
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
    free(keyQuery_count);
    keyValuePair_free(keyPairQuery_count);
    free(keyQuery_offset);
    keyValuePair_free(keyPairQuery_offset);
    return elementToReturn;
end:
    return NULL;

}

// Retrieve the latest users withdrawals
//
object_t*
WalletAPI_privateGetWithdrawalsGet(apiClient_t *apiClient ,currency_e currency ,int count ,int offset)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_withdrawals")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_withdrawals");




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
    char *keyQuery_offset;
    int valueQuery_offset;
    keyValuePair_t *keyPairQuery_offset = 0;
    if (offset)
    {
        keyQuery_offset = strdup("offset");
        valueQuery_offset = (offset);
        keyPairQuery_offset = keyValuePair_create(keyQuery_offset, &valueQuery_offset);
        list_addElement(localVarQueryParameters,keyPairQuery_offset);
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
    cJSON *WalletAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(WalletAPIlocalVarJSON);
    cJSON_Delete(WalletAPIlocalVarJSON);
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
    free(keyQuery_count);
    keyValuePair_free(keyPairQuery_count);
    free(keyQuery_offset);
    keyValuePair_free(keyPairQuery_offset);
    return elementToReturn;
end:
    return NULL;

}

// Adds new entry to address book of given type
//
object_t*
WalletAPI_privateRemoveFromAddressBookGet(apiClient_t *apiClient ,currency_e currency ,type_e type ,char * address ,char * tfa)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/remove_from_address_book")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/remove_from_address_book");




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
    char *keyQuery_address;
    char * valueQuery_address;
    keyValuePair_t *keyPairQuery_address = 0;
    if (address)
    {
        keyQuery_address = strdup("address");
        valueQuery_address = strdup((address));
        keyPairQuery_address = keyValuePair_create(keyQuery_address, valueQuery_address);
        list_addElement(localVarQueryParameters,keyPairQuery_address);
    }

    // query parameters
    char *keyQuery_tfa;
    char * valueQuery_tfa;
    keyValuePair_t *keyPairQuery_tfa = 0;
    if (tfa)
    {
        keyQuery_tfa = strdup("tfa");
        valueQuery_tfa = strdup((tfa));
        keyPairQuery_tfa = keyValuePair_create(keyQuery_tfa, valueQuery_tfa);
        list_addElement(localVarQueryParameters,keyPairQuery_tfa);
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
    cJSON *WalletAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(WalletAPIlocalVarJSON);
    cJSON_Delete(WalletAPIlocalVarJSON);
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
    free(keyQuery_address);
    free(valueQuery_address);
    keyValuePair_free(keyPairQuery_address);
    free(keyQuery_tfa);
    free(valueQuery_tfa);
    keyValuePair_free(keyPairQuery_tfa);
    return elementToReturn;
end:
    return NULL;

}

// Transfer funds to a subaccount.
//
object_t*
WalletAPI_privateSubmitTransferToSubaccountGet(apiClient_t *apiClient ,currency_e currency ,double amount ,int destination)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/submit_transfer_to_subaccount")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/submit_transfer_to_subaccount");




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
    char *keyQuery_amount;
    double valueQuery_amount;
    keyValuePair_t *keyPairQuery_amount = 0;
    if (amount)
    {
        keyQuery_amount = strdup("amount");
        valueQuery_amount = (amount);
        keyPairQuery_amount = keyValuePair_create(keyQuery_amount, &valueQuery_amount);
        list_addElement(localVarQueryParameters,keyPairQuery_amount);
    }

    // query parameters
    char *keyQuery_destination;
    int valueQuery_destination;
    keyValuePair_t *keyPairQuery_destination = 0;
    if (destination)
    {
        keyQuery_destination = strdup("destination");
        valueQuery_destination = (destination);
        keyPairQuery_destination = keyValuePair_create(keyQuery_destination, &valueQuery_destination);
        list_addElement(localVarQueryParameters,keyPairQuery_destination);
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
    cJSON *WalletAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(WalletAPIlocalVarJSON);
    cJSON_Delete(WalletAPIlocalVarJSON);
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
    free(keyQuery_amount);
    keyValuePair_free(keyPairQuery_amount);
    free(keyQuery_destination);
    keyValuePair_free(keyPairQuery_destination);
    return elementToReturn;
end:
    return NULL;

}

// Transfer funds to a another user.
//
object_t*
WalletAPI_privateSubmitTransferToUserGet(apiClient_t *apiClient ,currency_e currency ,double amount ,char * destination ,char * tfa)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/submit_transfer_to_user")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/submit_transfer_to_user");




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
    char *keyQuery_amount;
    double valueQuery_amount;
    keyValuePair_t *keyPairQuery_amount = 0;
    if (amount)
    {
        keyQuery_amount = strdup("amount");
        valueQuery_amount = (amount);
        keyPairQuery_amount = keyValuePair_create(keyQuery_amount, &valueQuery_amount);
        list_addElement(localVarQueryParameters,keyPairQuery_amount);
    }

    // query parameters
    char *keyQuery_destination;
    char * valueQuery_destination;
    keyValuePair_t *keyPairQuery_destination = 0;
    if (destination)
    {
        keyQuery_destination = strdup("destination");
        valueQuery_destination = strdup((destination));
        keyPairQuery_destination = keyValuePair_create(keyQuery_destination, valueQuery_destination);
        list_addElement(localVarQueryParameters,keyPairQuery_destination);
    }

    // query parameters
    char *keyQuery_tfa;
    char * valueQuery_tfa;
    keyValuePair_t *keyPairQuery_tfa = 0;
    if (tfa)
    {
        keyQuery_tfa = strdup("tfa");
        valueQuery_tfa = strdup((tfa));
        keyPairQuery_tfa = keyValuePair_create(keyQuery_tfa, valueQuery_tfa);
        list_addElement(localVarQueryParameters,keyPairQuery_tfa);
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
    cJSON *WalletAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(WalletAPIlocalVarJSON);
    cJSON_Delete(WalletAPIlocalVarJSON);
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
    free(keyQuery_amount);
    keyValuePair_free(keyPairQuery_amount);
    free(keyQuery_destination);
    free(valueQuery_destination);
    keyValuePair_free(keyPairQuery_destination);
    free(keyQuery_tfa);
    free(valueQuery_tfa);
    keyValuePair_free(keyPairQuery_tfa);
    return elementToReturn;
end:
    return NULL;

}

// Enable or disable deposit address creation
//
object_t*
WalletAPI_privateToggleDepositAddressCreationGet(apiClient_t *apiClient ,currency_e currency ,int state)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/toggle_deposit_address_creation")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/toggle_deposit_address_creation");




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
    char *keyQuery_state;
    int valueQuery_state;
    keyValuePair_t *keyPairQuery_state = 0;
    if (state)
    {
        keyQuery_state = strdup("state");
        valueQuery_state = (state);
        keyPairQuery_state = keyValuePair_create(keyQuery_state, &valueQuery_state);
        list_addElement(localVarQueryParameters,keyPairQuery_state);
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
    cJSON *WalletAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(WalletAPIlocalVarJSON);
    cJSON_Delete(WalletAPIlocalVarJSON);
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
    free(keyQuery_state);
    keyValuePair_free(keyPairQuery_state);
    return elementToReturn;
end:
    return NULL;

}

// Creates a new withdrawal request
//
object_t*
WalletAPI_privateWithdrawGet(apiClient_t *apiClient ,currency_e currency ,char * address ,double amount ,priority_e priority ,char * tfa)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/withdraw")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/withdraw");




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
    char *keyQuery_address;
    char * valueQuery_address;
    keyValuePair_t *keyPairQuery_address = 0;
    if (address)
    {
        keyQuery_address = strdup("address");
        valueQuery_address = strdup((address));
        keyPairQuery_address = keyValuePair_create(keyQuery_address, valueQuery_address);
        list_addElement(localVarQueryParameters,keyPairQuery_address);
    }

    // query parameters
    char *keyQuery_amount;
    double valueQuery_amount;
    keyValuePair_t *keyPairQuery_amount = 0;
    if (amount)
    {
        keyQuery_amount = strdup("amount");
        valueQuery_amount = (amount);
        keyPairQuery_amount = keyValuePair_create(keyQuery_amount, &valueQuery_amount);
        list_addElement(localVarQueryParameters,keyPairQuery_amount);
    }

    // query parameters
    char *keyQuery_priority;
    priority_e valueQuery_priority;
    keyValuePair_t *keyPairQuery_priority = 0;
    if (priority)
    {
        keyQuery_priority = strdup("priority");
        valueQuery_priority = (priority);
        keyPairQuery_priority = keyValuePair_create(keyQuery_priority, (void *)valueQuery_priority);
        list_addElement(localVarQueryParameters,keyPairQuery_priority);
    }

    // query parameters
    char *keyQuery_tfa;
    char * valueQuery_tfa;
    keyValuePair_t *keyPairQuery_tfa = 0;
    if (tfa)
    {
        keyQuery_tfa = strdup("tfa");
        valueQuery_tfa = strdup((tfa));
        keyPairQuery_tfa = keyValuePair_create(keyQuery_tfa, valueQuery_tfa);
        list_addElement(localVarQueryParameters,keyPairQuery_tfa);
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
    cJSON *WalletAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(WalletAPIlocalVarJSON);
    cJSON_Delete(WalletAPIlocalVarJSON);
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
    free(keyQuery_address);
    free(valueQuery_address);
    keyValuePair_free(keyPairQuery_address);
    free(keyQuery_amount);
    keyValuePair_free(keyPairQuery_amount);
    free(keyQuery_priority);
    free(valueQuery_priority);
    keyValuePair_free(keyPairQuery_priority);
    free(keyQuery_tfa);
    free(valueQuery_tfa);
    keyValuePair_free(keyPairQuery_tfa);
    return elementToReturn;
end:
    return NULL;

}

