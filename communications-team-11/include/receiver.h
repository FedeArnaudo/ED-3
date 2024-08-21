#ifndef RECEIVER_H
#define RECEIVER_H

#include <stdio.h>

#include "packet.h"
#include "received_queue.h"

Queue* received_queue;

int detect_initial_packet();
void decode_id_packet();
void decode_type_packet();
void decode_location_packet();
void decode_alert_packet();
void decode_status_packet();
void decode_text_packet();
int detect_final_packet();

void receive(Queue* message_received);

#endif // RECEIVER_H
