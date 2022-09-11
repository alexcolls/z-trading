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
WalletAPI_privateAddToAddressBookGet(apiClient_t *apiClient ,currency_e currency ,type_e type ,char * address ,char * name ,char * tfa);


// Cancel transfer
//
object_t*
WalletAPI_privateCancelTransferByIdGet(apiClient_t *apiClient ,currency_e currency ,int id ,char * tfa);


// Cancels withdrawal request
//
object_t*
WalletAPI_privateCancelWithdrawalGet(apiClient_t *apiClient ,currency_e currency ,double id);


// Creates deposit address in currency
//
object_t*
WalletAPI_privateCreateDepositAddressGet(apiClient_t *apiClient ,currency_e currency);


// Retrieves address book of given type
//
object_t*
WalletAPI_privateGetAddressBookGet(apiClient_t *apiClient ,currency_e currency ,type_e type);


// Retrieve deposit address for currency
//
object_t*
WalletAPI_privateGetCurrentDepositAddressGet(apiClient_t *apiClient ,currency_e currency);


// Retrieve the latest users deposits
//
object_t*
WalletAPI_privateGetDepositsGet(apiClient_t *apiClient ,currency_e currency ,int count ,int offset);


// Adds new entry to address book of given type
//
object_t*
WalletAPI_privateGetTransfersGet(apiClient_t *apiClient ,currency_e currency ,int count ,int offset);


// Retrieve the latest users withdrawals
//
object_t*
WalletAPI_privateGetWithdrawalsGet(apiClient_t *apiClient ,currency_e currency ,int count ,int offset);


// Adds new entry to address book of given type
//
object_t*
WalletAPI_privateRemoveFromAddressBookGet(apiClient_t *apiClient ,currency_e currency ,type_e type ,char * address ,char * tfa);


// Transfer funds to a subaccount.
//
object_t*
WalletAPI_privateSubmitTransferToSubaccountGet(apiClient_t *apiClient ,currency_e currency ,double amount ,int destination);


// Transfer funds to a another user.
//
object_t*
WalletAPI_privateSubmitTransferToUserGet(apiClient_t *apiClient ,currency_e currency ,double amount ,char * destination ,char * tfa);


// Enable or disable deposit address creation
//
object_t*
WalletAPI_privateToggleDepositAddressCreationGet(apiClient_t *apiClient ,currency_e currency ,int state);


// Creates a new withdrawal request
//
object_t*
WalletAPI_privateWithdrawGet(apiClient_t *apiClient ,currency_e currency ,char * address ,double amount ,priority_e priority ,char * tfa);


