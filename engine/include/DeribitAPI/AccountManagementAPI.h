#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/object.h"


// Change the user name for a subaccount
//
object_t*
AccountManagementAPI_privateChangeSubaccountNameGet(apiClient_t *apiClient ,int sid ,char * name);


// Create a new subaccount
//
object_t*
AccountManagementAPI_privateCreateSubaccountGet(apiClient_t *apiClient);


// Disable two factor authentication for a subaccount.
//
object_t*
AccountManagementAPI_privateDisableTfaForSubaccountGet(apiClient_t *apiClient ,int sid);


// Retrieves user account summary.
//
object_t*
AccountManagementAPI_privateGetAccountSummaryGet(apiClient_t *apiClient ,currency_e currency ,int extended);


// Retrieves the language to be used for emails.
//
object_t*
AccountManagementAPI_privateGetEmailLanguageGet(apiClient_t *apiClient);


// Retrieves announcements that have not been marked read by the user.
//
object_t*
AccountManagementAPI_privateGetNewAnnouncementsGet(apiClient_t *apiClient);


// Retrieve user position.
//
object_t*
AccountManagementAPI_privateGetPositionGet(apiClient_t *apiClient ,char * instrument_name);


// Retrieve user positions.
//
object_t*
AccountManagementAPI_privateGetPositionsGet(apiClient_t *apiClient ,currency_e currency ,kind_e kind);


// Get information about subaccounts
//
object_t*
AccountManagementAPI_privateGetSubaccountsGet(apiClient_t *apiClient ,int with_portfolio);


// Marks an announcement as read, so it will not be shown in `get_new_announcements`.
//
object_t*
AccountManagementAPI_privateSetAnnouncementAsReadGet(apiClient_t *apiClient ,double announcement_id);


// Assign an email address to a subaccount. User will receive an email with confirmation link.
//
object_t*
AccountManagementAPI_privateSetEmailForSubaccountGet(apiClient_t *apiClient ,int sid ,char * email);


// Changes the language to be used for emails.
//
object_t*
AccountManagementAPI_privateSetEmailLanguageGet(apiClient_t *apiClient ,char * language);


// Set the password for the subaccount
//
object_t*
AccountManagementAPI_privateSetPasswordForSubaccountGet(apiClient_t *apiClient ,int sid ,char * password);


// Enable or disable sending of notifications for the subaccount.
//
object_t*
AccountManagementAPI_privateToggleNotificationsFromSubaccountGet(apiClient_t *apiClient ,int sid ,int state);


// Enable or disable login for a subaccount. If login is disabled and a session for the subaccount exists, this session will be terminated.
//
object_t*
AccountManagementAPI_privateToggleSubaccountLoginGet(apiClient_t *apiClient ,int sid ,state_e state);


// Retrieves announcements from the last 30 days.
//
object_t*
AccountManagementAPI_publicGetAnnouncementsGet(apiClient_t *apiClient);


