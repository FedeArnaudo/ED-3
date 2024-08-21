#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include "message.h"
#include "packet.h"
#include "receiver.h"
#include <stdio.h>
#include <string.h>

/**
 * function pointer to send functions
 */
typedef void (*send_function)(Message*);

void send_initial_packet();

void send_final_packet();

void send_id_packets(int id);

void send_type_packet(enum MessageType type);

void send_text_message(Message* message);

void send_location_message(Message* message);

void send_alert_message(Message* message);

void send_status_message(Message* message);

/**
 * Array of function pointers to send functions
 */
send_function send_functions[] = {
    send_text_message,     // TEXT
    send_location_message, // LOCATION
    send_alert_message,    // ALERT
    send_status_message    // STATUS
};

void transmit(Message* message);

#endif // TRANSMITTER_H
