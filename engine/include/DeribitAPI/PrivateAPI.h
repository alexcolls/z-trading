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
PrivateAPI_privateAddToAddressBookGet(apiClient_t *apiClient ,currency_e currency ,type_e type ,char * address ,char * name ,char * tfa);


// Places a buy order for an instrument.
//
object_t*
PrivateAPI_privateBuyGet(apiClient_t *apiClient ,char * instrument_name ,double amount ,type_e type ,char * label ,double price ,time_in_force_e time_in_force ,double max_show ,int post_only ,int reduce_only ,double stop_price ,trigger_e trigger ,advanced_e advanced);


// Cancels all orders by currency, optionally filtered by instrument kind and/or order type.
//
object_t*
PrivateAPI_privateCancelAllByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind ,type_e type);


// Cancels all orders by instrument, optionally filtered by order type.
//
object_t*
PrivateAPI_privateCancelAllByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,type_e type);


// This method cancels all users orders and stop orders within all currencies and instrument kinds.
//
object_t*
PrivateAPI_privateCancelAllGet(apiClient_t *apiClient);


// Cancel an order, specified by order id
//
object_t*
PrivateAPI_privateCancelGet(apiClient_t *apiClient ,char * order_id);


// Cancel transfer
//
object_t*
PrivateAPI_privateCancelTransferByIdGet(apiClient_t *apiClient ,currency_e currency ,int id ,char * tfa);


// Cancels withdrawal request
//
object_t*
PrivateAPI_privateCancelWithdrawalGet(apiClient_t *apiClient ,currency_e currency ,double id);


// Change the user name for a subaccount
//
object_t*
PrivateAPI_privateChangeSubaccountNameGet(apiClient_t *apiClient ,int sid ,char * name);


// Makes closing position reduce only order .
//
object_t*
PrivateAPI_privateClosePositionGet(apiClient_t *apiClient ,char * instrument_name ,type_e type ,double price);


// Creates deposit address in currency
//
object_t*
PrivateAPI_privateCreateDepositAddressGet(apiClient_t *apiClient ,currency_e currency);


// Create a new subaccount
//
object_t*
PrivateAPI_privateCreateSubaccountGet(apiClient_t *apiClient);


// Disable two factor authentication for a subaccount.
//
object_t*
PrivateAPI_privateDisableTfaForSubaccountGet(apiClient_t *apiClient ,int sid);


// Disables TFA with one time recovery code
//
object_t*
PrivateAPI_privateDisableTfaWithRecoveryCodeGet(apiClient_t *apiClient ,char * password ,char * code);


// Change price, amount and/or other properties of an order.
//
object_t*
PrivateAPI_privateEditGet(apiClient_t *apiClient ,char * order_id ,double amount ,double price ,int post_only ,advanced_e advanced ,double stop_price);


// Retrieves user account summary.
//
object_t*
PrivateAPI_privateGetAccountSummaryGet(apiClient_t *apiClient ,currency_e currency ,int extended);


// Retrieves address book of given type
//
object_t*
PrivateAPI_privateGetAddressBookGet(apiClient_t *apiClient ,currency_e currency ,type_e type);


// Retrieve deposit address for currency
//
object_t*
PrivateAPI_privateGetCurrentDepositAddressGet(apiClient_t *apiClient ,currency_e currency);


// Retrieve the latest users deposits
//
object_t*
PrivateAPI_privateGetDepositsGet(apiClient_t *apiClient ,currency_e currency ,int count ,int offset);


// Retrieves the language to be used for emails.
//
object_t*
PrivateAPI_privateGetEmailLanguageGet(apiClient_t *apiClient);


// Get margins for given instrument, amount and price.
//
object_t*
PrivateAPI_privateGetMarginsGet(apiClient_t *apiClient ,char * instrument_name ,double amount ,double price);


// Retrieves announcements that have not been marked read by the user.
//
object_t*
PrivateAPI_privateGetNewAnnouncementsGet(apiClient_t *apiClient);


// Retrieves list of user's open orders.
//
object_t*
PrivateAPI_privateGetOpenOrdersByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind ,type_e type);


// Retrieves list of user's open orders within given Instrument.
//
object_t*
PrivateAPI_privateGetOpenOrdersByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,type_e type);


// Retrieves history of orders that have been partially or fully filled.
//
object_t*
PrivateAPI_privateGetOrderHistoryByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind ,int count ,int offset ,int include_old ,int include_unfilled);


// Retrieves history of orders that have been partially or fully filled.
//
object_t*
PrivateAPI_privateGetOrderHistoryByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,int count ,int offset ,int include_old ,int include_unfilled);


// Retrieves initial margins of given orders
//
object_t*
PrivateAPI_privateGetOrderMarginByIdsGet(apiClient_t *apiClient ,list_t * ids);


// Retrieve the current state of an order.
//
object_t*
PrivateAPI_privateGetOrderStateGet(apiClient_t *apiClient ,char * order_id);


// Retrieve user position.
//
object_t*
PrivateAPI_privateGetPositionGet(apiClient_t *apiClient ,char * instrument_name);


// Retrieve user positions.
//
object_t*
PrivateAPI_privateGetPositionsGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind);


// Retrieves settlement, delivery and bankruptcy events that have affected your account.
//
object_t*
PrivateAPI_privateGetSettlementHistoryByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,type_e type ,int count);


// Retrieves public settlement, delivery and bankruptcy events filtered by instrument name
//
object_t*
PrivateAPI_privateGetSettlementHistoryByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,type_e type ,int count);


// Get information about subaccounts
//
object_t*
PrivateAPI_privateGetSubaccountsGet(apiClient_t *apiClient ,int with_portfolio);


// Adds new entry to address book of given type
//
object_t*
PrivateAPI_privateGetTransfersGet(apiClient_t *apiClient ,currency_e currency ,int count ,int offset);


// Retrieve the latest user trades that have occurred for instruments in a specific currency symbol and within given time range.
//
object_t*
PrivateAPI_privateGetUserTradesByCurrencyAndTimeGet(apiClient_t *apiClient ,currency_e currency ,int start_timestamp ,int end_timestamp ,kind_e kind ,int count ,int include_old ,sorting_e sorting);


// Retrieve the latest user trades that have occurred for instruments in a specific currency symbol.
//
object_t*
PrivateAPI_privateGetUserTradesByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind ,char * start_id ,char * end_id ,int count ,int include_old ,sorting_e sorting);


// Retrieve the latest user trades that have occurred for a specific instrument and within given time range.
//
object_t*
PrivateAPI_privateGetUserTradesByInstrumentAndTimeGet(apiClient_t *apiClient ,char * instrument_name ,int start_timestamp ,int end_timestamp ,int count ,int include_old ,sorting_e sorting);


// Retrieve the latest user trades that have occurred for a specific instrument.
//
object_t*
PrivateAPI_privateGetUserTradesByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,int start_seq ,int end_seq ,int count ,int include_old ,sorting_e sorting);


// Retrieve the list of user trades that was created for given order
//
object_t*
PrivateAPI_privateGetUserTradesByOrderGet(apiClient_t *apiClient ,char * order_id ,sorting_e sorting);


// Retrieve the latest users withdrawals
//
object_t*
PrivateAPI_privateGetWithdrawalsGet(apiClient_t *apiClient ,currency_e currency ,int count ,int offset);


// Adds new entry to address book of given type
//
object_t*
PrivateAPI_privateRemoveFromAddressBookGet(apiClient_t *apiClient ,currency_e currency ,type_e type ,char * address ,char * tfa);


// Places a sell order for an instrument.
//
object_t*
PrivateAPI_privateSellGet(apiClient_t *apiClient ,char * instrument_name ,double amount ,type_e type ,char * label ,double price ,time_in_force_e time_in_force ,double max_show ,int post_only ,int reduce_only ,double stop_price ,trigger_e trigger ,advanced_e advanced);


// Marks an announcement as read, so it will not be shown in `get_new_announcements`.
//
object_t*
PrivateAPI_privateSetAnnouncementAsReadGet(apiClient_t *apiClient ,double announcement_id);


// Assign an email address to a subaccount. User will receive an email with confirmation link.
//
object_t*
PrivateAPI_privateSetEmailForSubaccountGet(apiClient_t *apiClient ,int sid ,char * email);


// Changes the language to be used for emails.
//
object_t*
PrivateAPI_privateSetEmailLanguageGet(apiClient_t *apiClient ,char * language);


// Set the password for the subaccount
//
object_t*
PrivateAPI_privateSetPasswordForSubaccountGet(apiClient_t *apiClient ,int sid ,char * password);


// Transfer funds to a subaccount.
//
object_t*
PrivateAPI_privateSubmitTransferToSubaccountGet(apiClient_t *apiClient ,currency_e currency ,double amount ,int destination);


// Transfer funds to a another user.
//
object_t*
PrivateAPI_privateSubmitTransferToUserGet(apiClient_t *apiClient ,currency_e currency ,double amount ,char * destination ,char * tfa);


// Enable or disable deposit address creation
//
object_t*
PrivateAPI_privateToggleDepositAddressCreationGet(apiClient_t *apiClient ,currency_e currency ,int state);


// Enable or disable sending of notifications for the subaccount.
//
object_t*
PrivateAPI_privateToggleNotificationsFromSubaccountGet(apiClient_t *apiClient ,int sid ,int state);


// Enable or disable login for a subaccount. If login is disabled and a session for the subaccount exists, this session will be terminated.
//
object_t*
PrivateAPI_privateToggleSubaccountLoginGet(apiClient_t *apiClient ,int sid ,state_e state);


// Creates a new withdrawal request
//
object_t*
PrivateAPI_privateWithdrawGet(apiClient_t *apiClient ,currency_e currency ,char * address ,double amount ,priority_e priority ,char * tfa);


