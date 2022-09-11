#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/object.h"


// Places a buy order for an instrument.
//
object_t*
TradingAPI_privateBuyGet(apiClient_t *apiClient ,char * instrument_name ,double amount ,type_e type ,char * label ,double price ,time_in_force_e time_in_force ,double max_show ,int post_only ,int reduce_only ,double stop_price ,trigger_e trigger ,advanced_e advanced);


// Cancels all orders by currency, optionally filtered by instrument kind and/or order type.
//
object_t*
TradingAPI_privateCancelAllByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind ,type_e type);


// Cancels all orders by instrument, optionally filtered by order type.
//
object_t*
TradingAPI_privateCancelAllByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,type_e type);


// This method cancels all users orders and stop orders within all currencies and instrument kinds.
//
object_t*
TradingAPI_privateCancelAllGet(apiClient_t *apiClient);


// Cancel an order, specified by order id
//
object_t*
TradingAPI_privateCancelGet(apiClient_t *apiClient ,char * order_id);


// Makes closing position reduce only order .
//
object_t*
TradingAPI_privateClosePositionGet(apiClient_t *apiClient ,char * instrument_name ,type_e type ,double price);


// Change price, amount and/or other properties of an order.
//
object_t*
TradingAPI_privateEditGet(apiClient_t *apiClient ,char * order_id ,double amount ,double price ,int post_only ,advanced_e advanced ,double stop_price);


// Get margins for given instrument, amount and price.
//
object_t*
TradingAPI_privateGetMarginsGet(apiClient_t *apiClient ,char * instrument_name ,double amount ,double price);


// Retrieves list of user's open orders.
//
object_t*
TradingAPI_privateGetOpenOrdersByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind ,type_e type);


// Retrieves list of user's open orders within given Instrument.
//
object_t*
TradingAPI_privateGetOpenOrdersByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,type_e type);


// Retrieves history of orders that have been partially or fully filled.
//
object_t*
TradingAPI_privateGetOrderHistoryByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind ,int count ,int offset ,int include_old ,int include_unfilled);


// Retrieves history of orders that have been partially or fully filled.
//
object_t*
TradingAPI_privateGetOrderHistoryByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,int count ,int offset ,int include_old ,int include_unfilled);


// Retrieves initial margins of given orders
//
object_t*
TradingAPI_privateGetOrderMarginByIdsGet(apiClient_t *apiClient ,list_t * ids);


// Retrieve the current state of an order.
//
object_t*
TradingAPI_privateGetOrderStateGet(apiClient_t *apiClient ,char * order_id);


// Retrieves settlement, delivery and bankruptcy events that have affected your account.
//
object_t*
TradingAPI_privateGetSettlementHistoryByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,type_e type ,int count);


// Retrieves public settlement, delivery and bankruptcy events filtered by instrument name
//
object_t*
TradingAPI_privateGetSettlementHistoryByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,type_e type ,int count);


// Retrieve the latest user trades that have occurred for instruments in a specific currency symbol and within given time range.
//
object_t*
TradingAPI_privateGetUserTradesByCurrencyAndTimeGet(apiClient_t *apiClient ,currency_e currency ,int start_timestamp ,int end_timestamp ,kind_e kind ,int count ,int include_old ,sorting_e sorting);


// Retrieve the latest user trades that have occurred for instruments in a specific currency symbol.
//
object_t*
TradingAPI_privateGetUserTradesByCurrencyGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind ,char * start_id ,char * end_id ,int count ,int include_old ,sorting_e sorting);


// Retrieve the latest user trades that have occurred for a specific instrument and within given time range.
//
object_t*
TradingAPI_privateGetUserTradesByInstrumentAndTimeGet(apiClient_t *apiClient ,char * instrument_name ,int start_timestamp ,int end_timestamp ,int count ,int include_old ,sorting_e sorting);


// Retrieve the latest user trades that have occurred for a specific instrument.
//
object_t*
TradingAPI_privateGetUserTradesByInstrumentGet(apiClient_t *apiClient ,char * instrument_name ,int start_seq ,int end_seq ,int count ,int include_old ,sorting_e sorting);


// Retrieve the list of user trades that was created for given order
//
object_t*
TradingAPI_privateGetUserTradesByOrderGet(apiClient_t *apiClient ,char * order_id ,sorting_e sorting);


// Places a sell order for an instrument.
//
object_t*
TradingAPI_privateSellGet(apiClient_t *apiClient ,char * instrument_name ,double amount ,type_e type ,char * label ,double price ,time_in_force_e time_in_force ,double max_show ,int post_only ,int reduce_only ,double stop_price ,trigger_e trigger ,advanced_e advanced);


