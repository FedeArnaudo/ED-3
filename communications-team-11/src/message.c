#include "../include/message.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief  Creates a new text message
 *
 * @param id  The id of the message
 * @param text  The text of the message
 * @return  A pointer to the newly created message
 */
Message* create_text_message(int id, const char* text)
{
    Message* new_message = (Message*)malloc(sizeof(Message));
    new_message->id = id;
    new_message->type = TEXT;
    strcpy(new_message->text, text);
    return new_message;
}

/**
 * @brief  Creates a new location message
 *
 * @param id  The id of the message
 * @param latitude  The latitude of the location
 * @param longitude  The longitude of the location
 * @return  A pointer to the newly created message
 */
Message* create_location_message(int id, float latitude, float longitude)
{
    Message* new_message = (Message*)malloc(sizeof(Message));
    new_message->id = id;
    new_message->type = LOCATION;
    new_message->location[0] = latitude;
    new_message->location[1] = longitude;
    return new_message;
}

/**
 * @brief  Creates a new alert message
 *
 * @param id  The id of the message
 * @param alert  The alert sent
 * @return  A pointer to the newly created message
 */
Message* create_alert_message(int id, int alert)
{
    Message* new_message = (Message*)malloc(sizeof(Message));
    new_message->id = id;
    new_message->type = ALERT;
    new_message->alert = alert;
    return new_message;
}

/**
 * @brief  Creates a new status message
 *
 * @param id  The id of the message
 * @param status  The status sent
 * @return  A pointer to the newly created message
 */
Message* create_status_message(int id, char status)
{
    Message* new_message = (Message*)malloc(sizeof(Message));
    new_message->id = id;
    new_message->type = STATUS;
    new_message->status = status;
    return new_message;
}