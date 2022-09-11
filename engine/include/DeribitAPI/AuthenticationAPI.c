#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "AuthenticationAPI.h"


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
AuthenticationAPI_publicAuthGet(apiClient_t *apiClient ,grant_type_e grant_type ,char * username ,char * password ,char * client_id ,char * client_secret ,char * refresh_token ,char * timestamp ,char * signature ,char * nonce ,char * state ,char * scope)
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
    cJSON *AuthenticationAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(AuthenticationAPIlocalVarJSON);
    cJSON_Delete(AuthenticationAPIlocalVarJSON);
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

