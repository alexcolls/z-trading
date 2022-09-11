#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/object.h"


// Retrieves the current time (in milliseconds). This API endpoint can be used to check the clock skew between your software and Deribit's systems.
//
object_t*
SupportingAPI_publicGetTimeGet(apiClient_t *apiClient);


// Tests the connection to the API server, and returns its version. You can use this to make sure the API is reachable, and matches the expected version.
//
object_t*
SupportingAPI_publicTestGet(apiClient_t *apiClient ,expected_result_e expected_result);


