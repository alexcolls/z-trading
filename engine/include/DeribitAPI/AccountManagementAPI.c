#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "AccountManagementAPI.h"


#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)

// Change the user name for a subaccount
//
object_t*
AccountManagementAPI_privateChangeSubaccountNameGet(apiClient_t *apiClient ,int sid ,char * name)
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
    cJSON *AccountManagementAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(AccountManagementAPIlocalVarJSON);
    cJSON_Delete(AccountManagementAPIlocalVarJSON);
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

// Create a new subaccount
//
object_t*
AccountManagementAPI_privateCreateSubaccountGet(apiClient_t *apiClient)
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
    cJSON *AccountManagementAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(AccountManagementAPIlocalVarJSON);
    cJSON_Delete(AccountManagementAPIlocalVarJSON);
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
AccountManagementAPI_privateDisableTfaForSubaccountGet(apiClient_t *apiClient ,int sid)
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
    cJSON *AccountManagementAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(AccountManagementAPIlocalVarJSON);
    cJSON_Delete(AccountManagementAPIlocalVarJSON);
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

// Retrieves user account summary.
//
object_t*
AccountManagementAPI_privateGetAccountSummaryGet(apiClient_t *apiClient ,currency_e currency ,int extended)
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
    cJSON *AccountManagementAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(AccountManagementAPIlocalVarJSON);
    cJSON_Delete(AccountManagementAPIlocalVarJSON);
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

// Retrieves the language to be used for emails.
//
object_t*
AccountManagementAPI_privateGetEmailLanguageGet(apiClient_t *apiClient)
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
    cJSON *AccountManagementAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(AccountManagementAPIlocalVarJSON);
    cJSON_Delete(AccountManagementAPIlocalVarJSON);
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

// Retrieves announcements that have not been marked read by the user.
//
object_t*
AccountManagementAPI_privateGetNewAnnouncementsGet(apiClient_t *apiClient)
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
    cJSON *AccountManagementAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(AccountManagementAPIlocalVarJSON);
    cJSON_Delete(AccountManagementAPIlocalVarJSON);
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

// Retrieve user position.
//
object_t*
AccountManagementAPI_privateGetPositionGet(apiClient_t *apiClient ,char * instrument_name)
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
    cJSON *AccountManagementAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(AccountManagementAPIlocalVarJSON);
    cJSON_Delete(AccountManagementAPIlocalVarJSON);
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
AccountManagementAPI_privateGetPositionsGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind)
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
    cJSON *AccountManagementAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(AccountManagementAPIlocalVarJSON);
    cJSON_Delete(AccountManagementAPIlocalVarJSON);
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

// Get information about subaccounts
//
object_t*
AccountManagementAPI_privateGetSubaccountsGet(apiClient_t *apiClient ,int with_portfolio)
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
    cJSON *AccountManagementAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(AccountManagementAPIlocalVarJSON);
    cJSON_Delete(AccountManagementAPIlocalVarJSON);
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

// Marks an announcement as read, so it will not be shown in `get_new_announcements`.
//
object_t*
AccountManagementAPI_privateSetAnnouncementAsReadGet(apiClient_t *apiClient ,double announcement_id)
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
    cJSON *AccountManagementAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(AccountManagementAPIlocalVarJSON);
    cJSON_Delete(AccountManagementAPIlocalVarJSON);
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
AccountManagementAPI_privateSetEmailForSubaccountGet(apiClient_t *apiClient ,int sid ,char * email)
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
    cJSON *AccountManagementAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(AccountManagementAPIlocalVarJSON);
    cJSON_Delete(AccountManagementAPIlocalVarJSON);
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
AccountManagementAPI_privateSetEmailLanguageGet(apiClient_t *apiClient ,char * language)
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
    cJSON *AccountManagementAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(AccountManagementAPIlocalVarJSON);
    cJSON_Delete(AccountManagementAPIlocalVarJSON);
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
AccountManagementAPI_privateSetPasswordForSubaccountGet(apiClient_t *apiClient ,int sid ,char * password)
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
    cJSON *AccountManagementAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(AccountManagementAPIlocalVarJSON);
    cJSON_Delete(AccountManagementAPIlocalVarJSON);
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

// Enable or disable sending of notifications for the subaccount.
//
object_t*
AccountManagementAPI_privateToggleNotificationsFromSubaccountGet(apiClient_t *apiClient ,int sid ,int state)
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
    cJSON *AccountManagementAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(AccountManagementAPIlocalVarJSON);
    cJSON_Delete(AccountManagementAPIlocalVarJSON);
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
AccountManagementAPI_privateToggleSubaccountLoginGet(apiClient_t *apiClient ,int sid ,state_e state)
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
    cJSON *AccountManagementAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(AccountManagementAPIlocalVarJSON);
    cJSON_Delete(AccountManagementAPIlocalVarJSON);
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

// Retrieves announcements from the last 30 days.
//
object_t*
AccountManagementAPI_publicGetAnnouncementsGet(apiClient_t *apiClient)
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
    cJSON *AccountManagementAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(AccountManagementAPIlocalVarJSON);
    cJSON_Delete(AccountManagementAPIlocalVarJSON);
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

