#include "../include/transmitter.h"

/**
 * @brief Sends the initial packet
 *
 */
void send_initial_packet()
{
    Packet* packet = create_initial_packet();
    // Send packet
}

/**
 * @brief Sends the final packet
 *
 */
void send_final_packet()
{
    Packet* packet = create_final_packet();
    // Send packet
}

/**
 * @brief Sends an integer packet
 *
 * @param data  The data to be sent
 */
void send_int_packet(int data)
{
    for (int i = 0; i < sizeof(data); i++)
    {
        unsigned int chunk = data & 0xFF;
        Packet* packet = create_data_packet(chunk);
        // Send packet
        data >>= 8;
    }
}

/**
 * @brief Sends the id packets
 *
 * @param id The id to be sent
 */
void send_id_packets(int id)
{
    send_int_packet(id);
}

/**
 * @brief Sends the message type packet
 *
 * @param type The message type to be sent
 */
void send_type_packets(int type)
{
    send_int_packet(type);
}

/**
 * @brief Sends a text message
 *
 * @param message The message to be sent
 */
void send_text_message(Message* message)
{
    for (int i = 0; i < strlen(message->text); i++)
    {
        unsigned int character = message->text[i];
        Packet* packet = create_data_packet(character);
        // Send packet
    }
}

/**
 * @brief Sends a location message
 *
 * @param message The message to be sent
 */
void send_location_message(Message* message)
{
    int lat = (int)(message->location[0] * 100);
    int lon = (int)(message->location[1] * 100);

    send_int_packet(lat);
    send_int_packet(lon);
}

/**
 * @brief Sends an alert message
 *
 * @param message The message to be sent
 */
void send_alert_message(Message* message)
{
    Packet* packet = create_data_packet(message->alert);
    // Send packet
}

/**
 * @brief Sends a status message
 *
 * @param message The message to be sent
 */
void send_status_message(Message* message)
{
    Packet* packet = create_data_packet(message->status);
    // Send packet
}

/**
 * @brief Transmits a message
 *
 * @param message The message to be transmitted
 */
void transmit(Message* message)
{
    if (message->type >= 0 && message->type < sizeof(send_functions) / sizeof(send_function))
    {
        send_initial_packet();
        send_id_packets(message->id);
        send_type_packets(message->type);
        send_functions[message->type](message);
        send_final_packet();
        // log message
    }
    else
    {
        // Handle invalid MessageType
    }
}