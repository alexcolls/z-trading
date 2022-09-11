#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "PrivateAPI.h"


#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)

// Adds new entry to address book of given type
//
object_t*
PrivateAPI_privateAddToAddressBookGet(apiClient_t *apiClient ,currency_e currency ,type_e type ,char * address ,char * name ,char * tfa)
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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

// Places a buy order for an instrument.
//
object_t*
PrivateAPI_privateBuyGet(apiClient_t *apiClient ,char * instrument_name ,double amount ,type_e type ,char * label ,double price ,time_in_force_e time_in_force ,double max_show ,int post_only ,int reduce_only ,double stop_price ,trigger_e trigger ,advanced_e advanced)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/buy")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/buy");




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
    char *keyQuery_label;
    char * valueQuery_label;
    keyValuePair_t *keyPairQuery_label = 0;
    if (label)
    {
        keyQuery_label = strdup("label");
        valueQuery_label = strdup((label));
        keyPairQuery_label = keyValuePair_create(keyQuery_label, valueQuery_label);
        list_addElement(localVarQueryParameters,keyPairQuery_label);
    }

    // query parameters
    char *keyQuery_price;
    double valueQuery_price;
    keyValuePair_t *keyPairQuery_price = 0;
    if (price)
    {
        keyQuery_price = strdup("price");
        valueQuery_price = (price);
        keyPairQuery_price = keyValuePair_create(keyQuery_price, &valueQuery_price);
        list_addElement(localVarQueryParameters,keyPairQuery_price);
    }

    // query parameters
    char *keyQuery_time_in_force;
    time_in_force_e valueQuery_time_in_force;
    keyValuePair_t *keyPairQuery_time_in_force = 0;
    if (time_in_force)
    {
        keyQuery_time_in_force = strdup("time_in_force");
        valueQuery_time_in_force = (time_in_force);
        keyPairQuery_time_in_force = keyValuePair_create(keyQuery_time_in_force, (void *)valueQuery_time_in_force);
        list_addElement(localVarQueryParameters,keyPairQuery_time_in_force);
    }

    // query parameters
    char *keyQuery_max_show;
    double valueQuery_max_show;
    keyValuePair_t *keyPairQuery_max_show = 0;
    if (max_show)
    {
        keyQuery_max_show = strdup("max_show");
        valueQuery_max_show = (max_show);
        keyPairQuery_max_show = keyValuePair_create(keyQuery_max_show, &valueQuery_max_show);
        list_addElement(localVarQueryParameters,keyPairQuery_max_show);
    }

    // query parameters
    char *keyQuery_post_only;
    int valueQuery_post_only;
    keyValuePair_t *keyPairQuery_post_only = 0;
    if (post_only)
    {
        keyQuery_post_only = strdup("post_only");
        valueQuery_post_only = (post_only);
        keyPairQuery_post_only = keyValuePair_create(keyQuery_post_only, &valueQuery_post_only);
        list_addElement(localVarQueryParameters,keyPairQuery_post_only);
    }

    // query parameters
    char *keyQuery_reduce_only;
    int valueQuery_reduce_only;
    keyValuePair_t *keyPairQuery_reduce_only = 0;
    if (reduce_only)
    {
        keyQuery_reduce_only = strdup("reduce_only");
        valueQuery_reduce_only = (reduce_only);
        keyPairQuery_reduce_only = keyValuePair_create(keyQuery_reduce_only, &valueQuery_reduce_only);
        list_addElement(localVarQueryParameters,keyPairQuery_reduce_only);
    }

    // query parameters
    char *keyQuery_stop_price;
    double valueQuery_stop_price;
    keyValuePair_t *keyPairQuery_stop_price = 0;
    if (stop_price)
    {
        keyQuery_stop_price = strdup("stop_price");
        valueQuery_stop_price = (stop_price);
        keyPairQuery_stop_price = keyValuePair_create(keyQuery_stop_price, &valueQuery_stop_price);
        list_addElement(localVarQueryParameters,keyPairQuery_stop_price);
    }

    // query parameters
    char *keyQuery_trigger;
    trigger_e valueQuery_trigger;
    keyValuePair_t *keyPairQuery_trigger = 0;
    if (trigger)
    {
        keyQuery_trigger = strdup("trigger");
        valueQuery_trigger = (trigger);
        keyPairQuery_trigger = keyValuePair_create(keyQuery_trigger, (void *)valueQuery_trigger);
        list_addElement(localVarQueryParameters,keyPairQuery_trigger);
    }

    // query parameters
    char *keyQuery_advanced;
    advanced_e valueQuery_advanced;
    keyValuePair_t *keyPairQuery_advanced = 0;
    if (advanced)
    {
        keyQuery_advanced = strdup("advanced");
        valueQuery_advanced = (advanced);
        keyPairQuery_advanced = keyValuePair_create(keyQuery_advanced, (void *)valueQuery_advanced);
        list_addElement(localVarQueryParameters,keyPairQuery_advanced);
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_amount);
    keyValuePair_free(keyPairQuery_amount);
    free(keyQuery_type);
    free(valueQuery_type);
    keyValuePair_free(keyPairQuery_type);
    free(keyQuery_label);
    free(valueQuery_label);
    keyValuePair_free(keyPairQuery_label);
    free(keyQuery_price);
    keyValuePair_free(keyPairQuery_price);
    free(keyQuery_time_in_force);
    free(valueQuery_time_in_force);
    keyValuePair_free(keyPairQuery_time_in_force);
    free(keyQuery_max_show);
    keyValuePair_free(keyPairQuery_max_show);
    free(keyQuery_post_only);
    keyValuePair_free(keyPairQuery_post_only);
    free(keyQuery_reduce_only);
    keyValuePair_free(keyPairQuery_reduce_only);
    free(keyQuery_stop_price);
    keyValuePair_free(keyPairQuery_stop_price);
    free(keyQuery_trigger);
    free(valueQuery_trigger);
    keyValuePair_free(keyPairQuery_trigger);
    free(keyQuery_advanced);
    free(valueQuery_advanced);
    keyValuePair_free(keyPairQuery_advanced);
    return elementToReturn;
end:
    return NULL;

}

// Cancels all orders by currency, optionally filtered by instrument kind and/or order type.
//
object_t*
PrivateAPI_privateCancelAllByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind ,type_e type)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/cancel_all_by_currency")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/cancel_all_by_currency");




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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_type);
    free(valueQuery_type);
    keyValuePair_free(keyPairQuery_type);
    return elementToReturn;
end:
    return NULL;

}

// Cancels all orders by instrument, optionally filtered by order type.
//
object_t*
PrivateAPI_privateCancelAllByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,type_e type)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/cancel_all_by_instrument")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/cancel_all_by_instrument");




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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    return elementToReturn;
end:
    return NULL;

}

// This method cancels all users orders and stop orders within all currencies and instrument kinds.
//
object_t*
PrivateAPI_privateCancelAllGet(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/cancel_all")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/cancel_all");



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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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

// Cancel an order, specified by order id
//
object_t*
PrivateAPI_privateCancelGet(apiClient_t *apiClient ,char * order_id)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/cancel")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/cancel");




    // query parameters
    char *keyQuery_order_id;
    char * valueQuery_order_id;
    keyValuePair_t *keyPairQuery_order_id = 0;
    if (order_id)
    {
        keyQuery_order_id = strdup("order_id");
        valueQuery_order_id = strdup((order_id));
        keyPairQuery_order_id = keyValuePair_create(keyQuery_order_id, valueQuery_order_id);
        list_addElement(localVarQueryParameters,keyPairQuery_order_id);
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_order_id);
    free(valueQuery_order_id);
    keyValuePair_free(keyPairQuery_order_id);
    return elementToReturn;
end:
    return NULL;

}

// Cancel transfer
//
object_t*
PrivateAPI_privateCancelTransferByIdGet(apiClient_t *apiClient ,currency_e currency ,int id ,char * tfa)
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
PrivateAPI_privateCancelWithdrawalGet(apiClient_t *apiClient ,currency_e currency ,double id)
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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

// Change the user name for a subaccount
//
object_t*
PrivateAPI_privateChangeSubaccountNameGet(apiClient_t *apiClient ,int sid ,char * name)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/change_subaccount_name")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/change_subaccount_name");




    // query parameters
    char *keyQuery_sid;
    int valueQuery_sid;
    keyValuePair_t *keyPairQuery_sid = 0;
    if (sid)
    {
        keyQuery_sid = strdup("sid");
        valueQuery_sid = (sid);
        keyPairQuery_sid = keyValuePair_create(keyQuery_sid, &valueQuery_sid);
        list_addElement(localVarQueryParameters,keyPairQuery_sid);
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_sid);
    keyValuePair_free(keyPairQuery_sid);
    free(keyQuery_name);
    free(valueQuery_name);
    keyValuePair_free(keyPairQuery_name);
    return elementToReturn;
end:
    return NULL;

}

// Makes closing position reduce only order .
//
object_t*
PrivateAPI_privateClosePositionGet(apiClient_t *apiClient ,char * instrument_name ,type_e type ,double price)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/close_position")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/close_position");




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
    char *keyQuery_price;
    double valueQuery_price;
    keyValuePair_t *keyPairQuery_price = 0;
    if (price)
    {
        keyQuery_price = strdup("price");
        valueQuery_price = (price);
        keyPairQuery_price = keyValuePair_create(keyQuery_price, &valueQuery_price);
        list_addElement(localVarQueryParameters,keyPairQuery_price);
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_price);
    keyValuePair_free(keyPairQuery_price);
    return elementToReturn;
end:
    return NULL;

}

// Creates deposit address in currency
//
object_t*
PrivateAPI_privateCreateDepositAddressGet(apiClient_t *apiClient ,currency_e currency)
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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

// Create a new subaccount
//
object_t*
PrivateAPI_privateCreateSubaccountGet(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/create_subaccount")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/create_subaccount");



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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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

// Disable two factor authentication for a subaccount.
//
object_t*
PrivateAPI_privateDisableTfaForSubaccountGet(apiClient_t *apiClient ,int sid)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/disable_tfa_for_subaccount")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/disable_tfa_for_subaccount");




    // query parameters
    char *keyQuery_sid;
    int valueQuery_sid;
    keyValuePair_t *keyPairQuery_sid = 0;
    if (sid)
    {
        keyQuery_sid = strdup("sid");
        valueQuery_sid = (sid);
        keyPairQuery_sid = keyValuePair_create(keyQuery_sid, &valueQuery_sid);
        list_addElement(localVarQueryParameters,keyPairQuery_sid);
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_sid);
    keyValuePair_free(keyPairQuery_sid);
    return elementToReturn;
end:
    return NULL;

}

// Disables TFA with one time recovery code
//
object_t*
PrivateAPI_privateDisableTfaWithRecoveryCodeGet(apiClient_t *apiClient ,char * password ,char * code)
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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

// Change price, amount and/or other properties of an order.
//
object_t*
PrivateAPI_privateEditGet(apiClient_t *apiClient ,char * order_id ,double amount ,double price ,int post_only ,advanced_e advanced ,double stop_price)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/edit")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/edit");




    // query parameters
    char *keyQuery_order_id;
    char * valueQuery_order_id;
    keyValuePair_t *keyPairQuery_order_id = 0;
    if (order_id)
    {
        keyQuery_order_id = strdup("order_id");
        valueQuery_order_id = strdup((order_id));
        keyPairQuery_order_id = keyValuePair_create(keyQuery_order_id, valueQuery_order_id);
        list_addElement(localVarQueryParameters,keyPairQuery_order_id);
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
    char *keyQuery_price;
    double valueQuery_price;
    keyValuePair_t *keyPairQuery_price = 0;
    if (price)
    {
        keyQuery_price = strdup("price");
        valueQuery_price = (price);
        keyPairQuery_price = keyValuePair_create(keyQuery_price, &valueQuery_price);
        list_addElement(localVarQueryParameters,keyPairQuery_price);
    }

    // query parameters
    char *keyQuery_post_only;
    int valueQuery_post_only;
    keyValuePair_t *keyPairQuery_post_only = 0;
    if (post_only)
    {
        keyQuery_post_only = strdup("post_only");
        valueQuery_post_only = (post_only);
        keyPairQuery_post_only = keyValuePair_create(keyQuery_post_only, &valueQuery_post_only);
        list_addElement(localVarQueryParameters,keyPairQuery_post_only);
    }

    // query parameters
    char *keyQuery_advanced;
    advanced_e valueQuery_advanced;
    keyValuePair_t *keyPairQuery_advanced = 0;
    if (advanced)
    {
        keyQuery_advanced = strdup("advanced");
        valueQuery_advanced = (advanced);
        keyPairQuery_advanced = keyValuePair_create(keyQuery_advanced, (void *)valueQuery_advanced);
        list_addElement(localVarQueryParameters,keyPairQuery_advanced);
    }

    // query parameters
    char *keyQuery_stop_price;
    double valueQuery_stop_price;
    keyValuePair_t *keyPairQuery_stop_price = 0;
    if (stop_price)
    {
        keyQuery_stop_price = strdup("stop_price");
        valueQuery_stop_price = (stop_price);
        keyPairQuery_stop_price = keyValuePair_create(keyQuery_stop_price, &valueQuery_stop_price);
        list_addElement(localVarQueryParameters,keyPairQuery_stop_price);
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_order_id);
    free(valueQuery_order_id);
    keyValuePair_free(keyPairQuery_order_id);
    free(keyQuery_amount);
    keyValuePair_free(keyPairQuery_amount);
    free(keyQuery_price);
    keyValuePair_free(keyPairQuery_price);
    free(keyQuery_post_only);
    keyValuePair_free(keyPairQuery_post_only);
    free(keyQuery_advanced);
    free(valueQuery_advanced);
    keyValuePair_free(keyPairQuery_advanced);
    free(keyQuery_stop_price);
    keyValuePair_free(keyPairQuery_stop_price);
    return elementToReturn;
end:
    return NULL;

}

// Retrieves user account summary.
//
object_t*
PrivateAPI_privateGetAccountSummaryGet(apiClient_t *apiClient ,currency_e currency ,int extended)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_account_summary")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_account_summary");




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
    char *keyQuery_extended;
    int valueQuery_extended;
    keyValuePair_t *keyPairQuery_extended = 0;
    if (extended)
    {
        keyQuery_extended = strdup("extended");
        valueQuery_extended = (extended);
        keyPairQuery_extended = keyValuePair_create(keyQuery_extended, &valueQuery_extended);
        list_addElement(localVarQueryParameters,keyPairQuery_extended);
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_extended);
    keyValuePair_free(keyPairQuery_extended);
    return elementToReturn;
end:
    return NULL;

}

// Retrieves address book of given type
//
object_t*
PrivateAPI_privateGetAddressBookGet(apiClient_t *apiClient ,currency_e currency ,type_e type)
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
PrivateAPI_privateGetCurrentDepositAddressGet(apiClient_t *apiClient ,currency_e currency)
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
PrivateAPI_privateGetDepositsGet(apiClient_t *apiClient ,currency_e currency ,int count ,int offset)
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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

// Retrieves the language to be used for emails.
//
object_t*
PrivateAPI_privateGetEmailLanguageGet(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_email_language")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_email_language");



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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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

// Get margins for given instrument, amount and price.
//
object_t*
PrivateAPI_privateGetMarginsGet(apiClient_t *apiClient ,char * instrument_name ,double amount ,double price)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_margins")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_margins");




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
    char *keyQuery_price;
    double valueQuery_price;
    keyValuePair_t *keyPairQuery_price = 0;
    if (price)
    {
        keyQuery_price = strdup("price");
        valueQuery_price = (price);
        keyPairQuery_price = keyValuePair_create(keyQuery_price, &valueQuery_price);
        list_addElement(localVarQueryParameters,keyPairQuery_price);
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_amount);
    keyValuePair_free(keyPairQuery_amount);
    free(keyQuery_price);
    keyValuePair_free(keyPairQuery_price);
    return elementToReturn;
end:
    return NULL;

}

// Retrieves announcements that have not been marked read by the user.
//
object_t*
PrivateAPI_privateGetNewAnnouncementsGet(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_new_announcements")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_new_announcements");



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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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

// Retrieves list of user's open orders.
//
object_t*
PrivateAPI_privateGetOpenOrdersByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind ,type_e type)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_open_orders_by_currency")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_open_orders_by_currency");




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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_type);
    free(valueQuery_type);
    keyValuePair_free(keyPairQuery_type);
    return elementToReturn;
end:
    return NULL;

}

// Retrieves list of user's open orders within given Instrument.
//
object_t*
PrivateAPI_privateGetOpenOrdersByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,type_e type)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_open_orders_by_instrument")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_open_orders_by_instrument");




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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    return elementToReturn;
end:
    return NULL;

}

// Retrieves history of orders that have been partially or fully filled.
//
object_t*
PrivateAPI_privateGetOrderHistoryByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind ,int count ,int offset ,int include_old ,int include_unfilled)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_order_history_by_currency")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_order_history_by_currency");




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
    char *keyQuery_include_unfilled;
    int valueQuery_include_unfilled;
    keyValuePair_t *keyPairQuery_include_unfilled = 0;
    if (include_unfilled)
    {
        keyQuery_include_unfilled = strdup("include_unfilled");
        valueQuery_include_unfilled = (include_unfilled);
        keyPairQuery_include_unfilled = keyValuePair_create(keyQuery_include_unfilled, &valueQuery_include_unfilled);
        list_addElement(localVarQueryParameters,keyPairQuery_include_unfilled);
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_count);
    keyValuePair_free(keyPairQuery_count);
    free(keyQuery_offset);
    keyValuePair_free(keyPairQuery_offset);
    free(keyQuery_include_old);
    keyValuePair_free(keyPairQuery_include_old);
    free(keyQuery_include_unfilled);
    keyValuePair_free(keyPairQuery_include_unfilled);
    return elementToReturn;
end:
    return NULL;

}

// Retrieves history of orders that have been partially or fully filled.
//
object_t*
PrivateAPI_privateGetOrderHistoryByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,int count ,int offset ,int include_old ,int include_unfilled)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_order_history_by_instrument")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_order_history_by_instrument");




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
    char *keyQuery_include_unfilled;
    int valueQuery_include_unfilled;
    keyValuePair_t *keyPairQuery_include_unfilled = 0;
    if (include_unfilled)
    {
        keyQuery_include_unfilled = strdup("include_unfilled");
        valueQuery_include_unfilled = (include_unfilled);
        keyPairQuery_include_unfilled = keyValuePair_create(keyQuery_include_unfilled, &valueQuery_include_unfilled);
        list_addElement(localVarQueryParameters,keyPairQuery_include_unfilled);
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_count);
    keyValuePair_free(keyPairQuery_count);
    free(keyQuery_offset);
    keyValuePair_free(keyPairQuery_offset);
    free(keyQuery_include_old);
    keyValuePair_free(keyPairQuery_include_old);
    free(keyQuery_include_unfilled);
    keyValuePair_free(keyPairQuery_include_unfilled);
    return elementToReturn;
end:
    return NULL;

}

// Retrieves initial margins of given orders
//
object_t*
PrivateAPI_privateGetOrderMarginByIdsGet(apiClient_t *apiClient ,list_t * ids)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_order_margin_by_ids")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_order_margin_by_ids");




    // query parameters
    if (ids)
    {
        list_addElement(localVarQueryParameters,ids);
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    return elementToReturn;
end:
    return NULL;

}

// Retrieve the current state of an order.
//
object_t*
PrivateAPI_privateGetOrderStateGet(apiClient_t *apiClient ,char * order_id)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_order_state")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_order_state");




    // query parameters
    char *keyQuery_order_id;
    char * valueQuery_order_id;
    keyValuePair_t *keyPairQuery_order_id = 0;
    if (order_id)
    {
        keyQuery_order_id = strdup("order_id");
        valueQuery_order_id = strdup((order_id));
        keyPairQuery_order_id = keyValuePair_create(keyQuery_order_id, valueQuery_order_id);
        list_addElement(localVarQueryParameters,keyPairQuery_order_id);
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
    if (apiClient->response_code == 400) {
        printf("%s\n","result when used via rest/HTTP");
    }
    //nonprimitive not container
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_order_id);
    free(valueQuery_order_id);
    keyValuePair_free(keyPairQuery_order_id);
    return elementToReturn;
end:
    return NULL;

}

// Retrieve user position.
//
object_t*
PrivateAPI_privateGetPositionGet(apiClient_t *apiClient ,char * instrument_name)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_position")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_position");




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
        printf("%s\n","When successful returns position");
    }
    if (apiClient->response_code == 400) {
        printf("%s\n","When some error occurs");
    }
    //nonprimitive not container
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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

// Retrieve user positions.
//
object_t*
PrivateAPI_privateGetPositionsGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_positions")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_positions");




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
        printf("%s\n","When successful returns array of positions");
    }
    if (apiClient->response_code == 400) {
        printf("%s\n","When some error occurs");
    }
    //nonprimitive not container
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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

// Retrieves settlement, delivery and bankruptcy events that have affected your account.
//
object_t*
PrivateAPI_privateGetSettlementHistoryByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,type_e type ,int count)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_settlement_history_by_currency")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_settlement_history_by_currency");




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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    return elementToReturn;
end:
    return NULL;

}

// Retrieves public settlement, delivery and bankruptcy events filtered by instrument name
//
object_t*
PrivateAPI_privateGetSettlementHistoryByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,type_e type ,int count)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_settlement_history_by_instrument")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_settlement_history_by_instrument");




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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    return elementToReturn;
end:
    return NULL;

}

// Get information about subaccounts
//
object_t*
PrivateAPI_privateGetSubaccountsGet(apiClient_t *apiClient ,int with_portfolio)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_subaccounts")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_subaccounts");




    // query parameters
    char *keyQuery_with_portfolio;
    int valueQuery_with_portfolio;
    keyValuePair_t *keyPairQuery_with_portfolio = 0;
    if (with_portfolio)
    {
        keyQuery_with_portfolio = strdup("with_portfolio");
        valueQuery_with_portfolio = (with_portfolio);
        keyPairQuery_with_portfolio = keyValuePair_create(keyQuery_with_portfolio, &valueQuery_with_portfolio);
        list_addElement(localVarQueryParameters,keyPairQuery_with_portfolio);
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
    if (apiClient->response_code == 401) {
        printf("%s\n","not authorised");
    }
    //nonprimitive not container
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_with_portfolio);
    keyValuePair_free(keyPairQuery_with_portfolio);
    return elementToReturn;
end:
    return NULL;

}

// Adds new entry to address book of given type
//
object_t*
PrivateAPI_privateGetTransfersGet(apiClient_t *apiClient ,currency_e currency ,int count ,int offset)
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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

// Retrieve the latest user trades that have occurred for instruments in a specific currency symbol and within given time range.
//
object_t*
PrivateAPI_privateGetUserTradesByCurrencyAndTimeGet(apiClient_t *apiClient ,currency_e currency ,int start_timestamp ,int end_timestamp ,kind_e kind ,int count ,int include_old ,sorting_e sorting)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_user_trades_by_currency_and_time")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_user_trades_by_currency_and_time");




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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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

// Retrieve the latest user trades that have occurred for instruments in a specific currency symbol.
//
object_t*
PrivateAPI_privateGetUserTradesByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind ,char * start_id ,char * end_id ,int count ,int include_old ,sorting_e sorting)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_user_trades_by_currency")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_user_trades_by_currency");




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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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

// Retrieve the latest user trades that have occurred for a specific instrument and within given time range.
//
object_t*
PrivateAPI_privateGetUserTradesByInstrumentAndTimeGet(apiClient_t *apiClient ,char * instrument_name ,int start_timestamp ,int end_timestamp ,int count ,int include_old ,sorting_e sorting)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_user_trades_by_instrument_and_time")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_user_trades_by_instrument_and_time");




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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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

// Retrieve the latest user trades that have occurred for a specific instrument.
//
object_t*
PrivateAPI_privateGetUserTradesByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,int start_seq ,int end_seq ,int count ,int include_old ,sorting_e sorting)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_user_trades_by_instrument")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_user_trades_by_instrument");




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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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

// Retrieve the list of user trades that was created for given order
//
object_t*
PrivateAPI_privateGetUserTradesByOrderGet(apiClient_t *apiClient ,char * order_id ,sorting_e sorting)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/get_user_trades_by_order")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/get_user_trades_by_order");




    // query parameters
    char *keyQuery_order_id;
    char * valueQuery_order_id;
    keyValuePair_t *keyPairQuery_order_id = 0;
    if (order_id)
    {
        keyQuery_order_id = strdup("order_id");
        valueQuery_order_id = strdup((order_id));
        keyPairQuery_order_id = keyValuePair_create(keyQuery_order_id, valueQuery_order_id);
        list_addElement(localVarQueryParameters,keyPairQuery_order_id);
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_order_id);
    free(valueQuery_order_id);
    keyValuePair_free(keyPairQuery_order_id);
    free(keyQuery_sorting);
    free(valueQuery_sorting);
    keyValuePair_free(keyPairQuery_sorting);
    return elementToReturn;
end:
    return NULL;

}

// Retrieve the latest users withdrawals
//
object_t*
PrivateAPI_privateGetWithdrawalsGet(apiClient_t *apiClient ,currency_e currency ,int count ,int offset)
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
PrivateAPI_privateRemoveFromAddressBookGet(apiClient_t *apiClient ,currency_e currency ,type_e type ,char * address ,char * tfa)
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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

// Places a sell order for an instrument.
//
object_t*
PrivateAPI_privateSellGet(apiClient_t *apiClient ,char * instrument_name ,double amount ,type_e type ,char * label ,double price ,time_in_force_e time_in_force ,double max_show ,int post_only ,int reduce_only ,double stop_price ,trigger_e trigger ,advanced_e advanced)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/sell")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/sell");




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
    char *keyQuery_label;
    char * valueQuery_label;
    keyValuePair_t *keyPairQuery_label = 0;
    if (label)
    {
        keyQuery_label = strdup("label");
        valueQuery_label = strdup((label));
        keyPairQuery_label = keyValuePair_create(keyQuery_label, valueQuery_label);
        list_addElement(localVarQueryParameters,keyPairQuery_label);
    }

    // query parameters
    char *keyQuery_price;
    double valueQuery_price;
    keyValuePair_t *keyPairQuery_price = 0;
    if (price)
    {
        keyQuery_price = strdup("price");
        valueQuery_price = (price);
        keyPairQuery_price = keyValuePair_create(keyQuery_price, &valueQuery_price);
        list_addElement(localVarQueryParameters,keyPairQuery_price);
    }

    // query parameters
    char *keyQuery_time_in_force;
    time_in_force_e valueQuery_time_in_force;
    keyValuePair_t *keyPairQuery_time_in_force = 0;
    if (time_in_force)
    {
        keyQuery_time_in_force = strdup("time_in_force");
        valueQuery_time_in_force = (time_in_force);
        keyPairQuery_time_in_force = keyValuePair_create(keyQuery_time_in_force, (void *)valueQuery_time_in_force);
        list_addElement(localVarQueryParameters,keyPairQuery_time_in_force);
    }

    // query parameters
    char *keyQuery_max_show;
    double valueQuery_max_show;
    keyValuePair_t *keyPairQuery_max_show = 0;
    if (max_show)
    {
        keyQuery_max_show = strdup("max_show");
        valueQuery_max_show = (max_show);
        keyPairQuery_max_show = keyValuePair_create(keyQuery_max_show, &valueQuery_max_show);
        list_addElement(localVarQueryParameters,keyPairQuery_max_show);
    }

    // query parameters
    char *keyQuery_post_only;
    int valueQuery_post_only;
    keyValuePair_t *keyPairQuery_post_only = 0;
    if (post_only)
    {
        keyQuery_post_only = strdup("post_only");
        valueQuery_post_only = (post_only);
        keyPairQuery_post_only = keyValuePair_create(keyQuery_post_only, &valueQuery_post_only);
        list_addElement(localVarQueryParameters,keyPairQuery_post_only);
    }

    // query parameters
    char *keyQuery_reduce_only;
    int valueQuery_reduce_only;
    keyValuePair_t *keyPairQuery_reduce_only = 0;
    if (reduce_only)
    {
        keyQuery_reduce_only = strdup("reduce_only");
        valueQuery_reduce_only = (reduce_only);
        keyPairQuery_reduce_only = keyValuePair_create(keyQuery_reduce_only, &valueQuery_reduce_only);
        list_addElement(localVarQueryParameters,keyPairQuery_reduce_only);
    }

    // query parameters
    char *keyQuery_stop_price;
    double valueQuery_stop_price;
    keyValuePair_t *keyPairQuery_stop_price = 0;
    if (stop_price)
    {
        keyQuery_stop_price = strdup("stop_price");
        valueQuery_stop_price = (stop_price);
        keyPairQuery_stop_price = keyValuePair_create(keyQuery_stop_price, &valueQuery_stop_price);
        list_addElement(localVarQueryParameters,keyPairQuery_stop_price);
    }

    // query parameters
    char *keyQuery_trigger;
    trigger_e valueQuery_trigger;
    keyValuePair_t *keyPairQuery_trigger = 0;
    if (trigger)
    {
        keyQuery_trigger = strdup("trigger");
        valueQuery_trigger = (trigger);
        keyPairQuery_trigger = keyValuePair_create(keyQuery_trigger, (void *)valueQuery_trigger);
        list_addElement(localVarQueryParameters,keyPairQuery_trigger);
    }

    // query parameters
    char *keyQuery_advanced;
    advanced_e valueQuery_advanced;
    keyValuePair_t *keyPairQuery_advanced = 0;
    if (advanced)
    {
        keyQuery_advanced = strdup("advanced");
        valueQuery_advanced = (advanced);
        keyPairQuery_advanced = keyValuePair_create(keyQuery_advanced, (void *)valueQuery_advanced);
        list_addElement(localVarQueryParameters,keyPairQuery_advanced);
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_amount);
    keyValuePair_free(keyPairQuery_amount);
    free(keyQuery_type);
    free(valueQuery_type);
    keyValuePair_free(keyPairQuery_type);
    free(keyQuery_label);
    free(valueQuery_label);
    keyValuePair_free(keyPairQuery_label);
    free(keyQuery_price);
    keyValuePair_free(keyPairQuery_price);
    free(keyQuery_time_in_force);
    free(valueQuery_time_in_force);
    keyValuePair_free(keyPairQuery_time_in_force);
    free(keyQuery_max_show);
    keyValuePair_free(keyPairQuery_max_show);
    free(keyQuery_post_only);
    keyValuePair_free(keyPairQuery_post_only);
    free(keyQuery_reduce_only);
    keyValuePair_free(keyPairQuery_reduce_only);
    free(keyQuery_stop_price);
    keyValuePair_free(keyPairQuery_stop_price);
    free(keyQuery_trigger);
    free(valueQuery_trigger);
    keyValuePair_free(keyPairQuery_trigger);
    free(keyQuery_advanced);
    free(valueQuery_advanced);
    keyValuePair_free(keyPairQuery_advanced);
    return elementToReturn;
end:
    return NULL;

}

// Marks an announcement as read, so it will not be shown in `get_new_announcements`.
//
object_t*
PrivateAPI_privateSetAnnouncementAsReadGet(apiClient_t *apiClient ,double announcement_id)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/set_announcement_as_read")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/set_announcement_as_read");




    // query parameters
    char *keyQuery_announcement_id;
    double valueQuery_announcement_id;
    keyValuePair_t *keyPairQuery_announcement_id = 0;
    if (announcement_id)
    {
        keyQuery_announcement_id = strdup("announcement_id");
        valueQuery_announcement_id = (announcement_id);
        keyPairQuery_announcement_id = keyValuePair_create(keyQuery_announcement_id, &valueQuery_announcement_id);
        list_addElement(localVarQueryParameters,keyPairQuery_announcement_id);
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_announcement_id);
    keyValuePair_free(keyPairQuery_announcement_id);
    return elementToReturn;
end:
    return NULL;

}

// Assign an email address to a subaccount. User will receive an email with confirmation link.
//
object_t*
PrivateAPI_privateSetEmailForSubaccountGet(apiClient_t *apiClient ,int sid ,char * email)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/set_email_for_subaccount")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/set_email_for_subaccount");




    // query parameters
    char *keyQuery_sid;
    int valueQuery_sid;
    keyValuePair_t *keyPairQuery_sid = 0;
    if (sid)
    {
        keyQuery_sid = strdup("sid");
        valueQuery_sid = (sid);
        keyPairQuery_sid = keyValuePair_create(keyQuery_sid, &valueQuery_sid);
        list_addElement(localVarQueryParameters,keyPairQuery_sid);
    }

    // query parameters
    char *keyQuery_email;
    char * valueQuery_email;
    keyValuePair_t *keyPairQuery_email = 0;
    if (email)
    {
        keyQuery_email = strdup("email");
        valueQuery_email = strdup((email));
        keyPairQuery_email = keyValuePair_create(keyQuery_email, valueQuery_email);
        list_addElement(localVarQueryParameters,keyPairQuery_email);
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_sid);
    keyValuePair_free(keyPairQuery_sid);
    free(keyQuery_email);
    free(valueQuery_email);
    keyValuePair_free(keyPairQuery_email);
    return elementToReturn;
end:
    return NULL;

}

// Changes the language to be used for emails.
//
object_t*
PrivateAPI_privateSetEmailLanguageGet(apiClient_t *apiClient ,char * language)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/set_email_language")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/set_email_language");




    // query parameters
    char *keyQuery_language;
    char * valueQuery_language;
    keyValuePair_t *keyPairQuery_language = 0;
    if (language)
    {
        keyQuery_language = strdup("language");
        valueQuery_language = strdup((language));
        keyPairQuery_language = keyValuePair_create(keyQuery_language, valueQuery_language);
        list_addElement(localVarQueryParameters,keyPairQuery_language);
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_language);
    free(valueQuery_language);
    keyValuePair_free(keyPairQuery_language);
    return elementToReturn;
end:
    return NULL;

}

// Set the password for the subaccount
//
object_t*
PrivateAPI_privateSetPasswordForSubaccountGet(apiClient_t *apiClient ,int sid ,char * password)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/set_password_for_subaccount")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/set_password_for_subaccount");




    // query parameters
    char *keyQuery_sid;
    int valueQuery_sid;
    keyValuePair_t *keyPairQuery_sid = 0;
    if (sid)
    {
        keyQuery_sid = strdup("sid");
        valueQuery_sid = (sid);
        keyPairQuery_sid = keyValuePair_create(keyQuery_sid, &valueQuery_sid);
        list_addElement(localVarQueryParameters,keyPairQuery_sid);
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_sid);
    keyValuePair_free(keyPairQuery_sid);
    free(keyQuery_password);
    free(valueQuery_password);
    keyValuePair_free(keyPairQuery_password);
    return elementToReturn;
end:
    return NULL;

}

// Transfer funds to a subaccount.
//
object_t*
PrivateAPI_privateSubmitTransferToSubaccountGet(apiClient_t *apiClient ,currency_e currency ,double amount ,int destination)
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
PrivateAPI_privateSubmitTransferToUserGet(apiClient_t *apiClient ,currency_e currency ,double amount ,char * destination ,char * tfa)
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
PrivateAPI_privateToggleDepositAddressCreationGet(apiClient_t *apiClient ,currency_e currency ,int state)
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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

// Enable or disable sending of notifications for the subaccount.
//
object_t*
PrivateAPI_privateToggleNotificationsFromSubaccountGet(apiClient_t *apiClient ,int sid ,int state)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/toggle_notifications_from_subaccount")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/toggle_notifications_from_subaccount");




    // query parameters
    char *keyQuery_sid;
    int valueQuery_sid;
    keyValuePair_t *keyPairQuery_sid = 0;
    if (sid)
    {
        keyQuery_sid = strdup("sid");
        valueQuery_sid = (sid);
        keyPairQuery_sid = keyValuePair_create(keyQuery_sid, &valueQuery_sid);
        list_addElement(localVarQueryParameters,keyPairQuery_sid);
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
        printf("%s\n","ok response");
    }
    //nonprimitive not container
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_sid);
    keyValuePair_free(keyPairQuery_sid);
    free(keyQuery_state);
    keyValuePair_free(keyPairQuery_state);
    return elementToReturn;
end:
    return NULL;

}

// Enable or disable login for a subaccount. If login is disabled and a session for the subaccount exists, this session will be terminated.
//
object_t*
PrivateAPI_privateToggleSubaccountLoginGet(apiClient_t *apiClient ,int sid ,state_e state)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/private/toggle_subaccount_login")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/private/toggle_subaccount_login");




    // query parameters
    char *keyQuery_sid;
    int valueQuery_sid;
    keyValuePair_t *keyPairQuery_sid = 0;
    if (sid)
    {
        keyQuery_sid = strdup("sid");
        valueQuery_sid = (sid);
        keyPairQuery_sid = keyValuePair_create(keyQuery_sid, &valueQuery_sid);
        list_addElement(localVarQueryParameters,keyPairQuery_sid);
    }

    // query parameters
    char *keyQuery_state;
    state_e valueQuery_state;
    keyValuePair_t *keyPairQuery_state = 0;
    if (state)
    {
        keyQuery_state = strdup("state");
        valueQuery_state = (state);
        keyPairQuery_state = keyValuePair_create(keyQuery_state, (void *)valueQuery_state);
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
        printf("%s\n","ok response");
    }
    //nonprimitive not container
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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
    free(keyQuery_sid);
    keyValuePair_free(keyPairQuery_sid);
    free(keyQuery_state);
    free(valueQuery_state);
    keyValuePair_free(keyPairQuery_state);
    return elementToReturn;
end:
    return NULL;

}

// Creates a new withdrawal request
//
object_t*
PrivateAPI_privateWithdrawGet(apiClient_t *apiClient ,currency_e currency ,char * address ,double amount ,priority_e priority ,char * tfa)
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
    cJSON *PrivateAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(PrivateAPIlocalVarJSON);
    cJSON_Delete(PrivateAPIlocalVarJSON);
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

