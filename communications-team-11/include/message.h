#ifndef MESSAGE_H
#define MESSAGE_H

/**
 * Enumerates the different types of messages that can be sent.
 *
 */
enum MessageType
{
    TEXT,
    LOCATION,
    ALERT,
    STATUS
};

/**
 * Represents a message that can be sent.
 */
typedef struct
{
    int id;
    int type;
    float location[2];
    char alert;
    char status;
    char text[];
} Message;

Message* create_text_message(int id, const char* text);

Message* create_location_message(int id, float latitude, float longitude);

Message* create_alert_message(int id, int alert);

Message* create_status_message(int id, char status);

#endif // MESSAGE_H
