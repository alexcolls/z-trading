#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/object.h"


// Adds new entry to address book of given type
//
object_t*
InternalAPI_privateAddToAddressBookGet(apiClient_t *apiClient ,currency_e currency ,type_e type ,char * address ,char * name ,char * tfa);


// Disables TFA with one time recovery code
//
object_t*
InternalAPI_privateDisableTfaWithRecoveryCodeGet(apiClient_t *apiClient ,char * password ,char * code);


// Retrieves address book of given type
//
object_t*
InternalAPI_privateGetAddressBookGet(apiClient_t *apiClient ,currency_e currency ,type_e type);


// Adds new entry to address book of given type
//
object_t*
InternalAPI_privateRemoveFromAddressBookGet(apiClient_t *apiClient ,currency_e currency ,type_e type ,char * address ,char * tfa);


// Transfer funds to a subaccount.
//
object_t*
InternalAPI_privateSubmitTransferToSubaccountGet(apiClient_t *apiClient ,currency_e currency ,double amount ,int destination);


// Transfer funds to a another user.
//
object_t*
InternalAPI_privateSubmitTransferToUserGet(apiClient_t *apiClient ,currency_e currency ,double amount ,char * destination ,char * tfa);


// Enable or disable deposit address creation
//
object_t*
InternalAPI_privateToggleDepositAddressCreationGet(apiClient_t *apiClient ,currency_e currency ,int state);


// Get information to be displayed in the footer of the website.
//
object_t*
InternalAPI_publicGetFooterGet(apiClient_t *apiClient);


// Retrives market prices and its implied volatility of options instruments
//
object_t*
InternalAPI_publicGetOptionMarkPricesGet(apiClient_t *apiClient ,currency_e currency);


// Method used to introduce the client software connected to Deribit platform over websocket. Provided data may have an impact on the maintained connection and will be collected for internal statistical purposes. In response, Deribit will also introduce itself.
//
object_t*
InternalAPI_publicValidateFieldGet(apiClient_t *apiClient ,char * field ,char * value ,char * value2);


