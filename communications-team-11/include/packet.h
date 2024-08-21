#ifndef PACKET_H
#define PACKET_H

/**
 * Packet structure
 */
typedef struct
{
    unsigned int start_bit : 1;
    unsigned int data : 8;
    unsigned int parity_bit : 1;
    unsigned int stop_bit : 1;
} Packet;

unsigned int calculate_parity(unsigned int data);

Packet* create_initial_packet();

Packet* create_data_packet(unsigned int data);

Packet* create_final_packet();

#endif // PACKET_H
