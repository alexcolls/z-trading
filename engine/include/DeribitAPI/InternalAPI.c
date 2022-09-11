#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "InternalAPI.h"


#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)

// Adds new entry to address book of given type
//
object_t*
InternalAPI_privateAddToAddressBookGet(apiClient_t *apiClient ,currency_e currency ,type_e type ,char * address ,char * name ,char * tfa)
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
    cJSON *InternalAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(InternalAPIlocalVarJSON);
    cJSON_Delete(InternalAPIlocalVarJSON);
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

// Disables TFA with one time recovery code
//
object_t*
InternalAPI_privateDisableTfaWithRecoveryCodeGet(apiClient_t *apiClient ,char * password ,char * code)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/disable_tfa_with_recovery_code")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/disable_tfa_with_recovery_code");




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
    char *keyQuery_code;
    char * valueQuery_code;
    keyValuePair_t *keyPairQuery_code = 0;
    if (code)
    {
        keyQuery_code = strdup("code");
        valueQuery_code = strdup((code));
        keyPairQuery_code = keyValuePair_create(keyQuery_code, valueQuery_code);
        list_addElement(localVarQueryParameters,keyPairQuery_code);
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
    cJSON *InternalAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(InternalAPIlocalVarJSON);
    cJSON_Delete(InternalAPIlocalVarJSON);
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
    free(keyQuery_password);
    free(valueQuery_password);
    keyValuePair_free(keyPairQuery_password);
    free(keyQuery_code);
    free(valueQuery_code);
    keyValuePair_free(keyPairQuery_code);
    return elementToReturn;
end:
    return NULL;

}

// Retrieves address book of given type
//
object_t*
InternalAPI_privateGetAddressBookGet(apiClient_t *apiClient ,currency_e currency ,type_e type)
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
    cJSON *InternalAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(InternalAPIlocalVarJSON);
    cJSON_Delete(InternalAPIlocalVarJSON);
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

// Adds new entry to address book of given type
//
object_t*
InternalAPI_privateRemoveFromAddressBookGet(apiClient_t *apiClient ,currency_e currency ,type_e type ,char * address ,char * tfa)
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
    cJSON *InternalAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(InternalAPIlocalVarJSON);
    cJSON_Delete(InternalAPIlocalVarJSON);
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
InternalAPI_privateSubmitTransferToSubaccountGet(apiClient_t *apiClient ,currency_e currency ,double amount ,int destination)
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
    cJSON *InternalAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(InternalAPIlocalVarJSON);
    cJSON_Delete(InternalAPIlocalVarJSON);
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
InternalAPI_privateSubmitTransferToUserGet(apiClient_t *apiClient ,currency_e currency ,double amount ,char * destination ,char * tfa)
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
    cJSON *InternalAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(InternalAPIlocalVarJSON);
    cJSON_Delete(InternalAPIlocalVarJSON);
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
InternalAPI_privateToggleDepositAddressCreationGet(apiClient_t *apiClient ,currency_e currency ,int state)
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
    cJSON *InternalAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(InternalAPIlocalVarJSON);
    cJSON_Delete(InternalAPIlocalVarJSON);
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

// Get information to be displayed in the footer of the website.
//
object_t*
InternalAPI_publicGetFooterGet(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_footer")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_footer");



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
    cJSON *InternalAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(InternalAPIlocalVarJSON);
    cJSON_Delete(InternalAPIlocalVarJSON);
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

// Retrives market prices and its implied volatility of options instruments
//
object_t*
InternalAPI_publicGetOptionMarkPricesGet(apiClient_t *apiClient ,currency_e currency)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/public/get_option_mark_prices")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/public/get_option_mark_prices");




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
    cJSON *InternalAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(InternalAPIlocalVarJSON);
    cJSON_Delete(InternalAPIlocalVarJSON);
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

// Method used to introduce the client software connected to Deribit platform over websocket. Provided data may have an impact on the maintained connection and will be collected for internal statistical purposes. In response, Deribit will also introduce itself.
//
object_t*
InternalAPI_publicValidateFieldGet(apiClient_t *apiClient ,char * field ,char * value ,char * value2)
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
    cJSON *InternalAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(InternalAPIlocalVarJSON);
    cJSON_Delete(InternalAPIlocalVarJSON);
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

