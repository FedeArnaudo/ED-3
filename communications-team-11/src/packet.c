#include "../include/packet.h"
#include <stdlib.h>

/**
 * @brief Calculate the parity bit for the given data
 *
 * @param data The data to calculate the parity bit for
 * @return The parity bit
 */
unsigned int calculate_parity(unsigned int data)
{
    unsigned int parity = 0;
    while (data)
    {
        parity ^= (data & 1);
        data >>= 1;
    }
    return parity;
}

/**
 * @brief Create an initial packet
 *
 * @note The initial packet is '&' in ASCII
 *
 * @return The initial packet
 */
Packet* create_initial_packet()
{
    Packet* packet = (Packet*)malloc(sizeof(Packet));
    packet->start_bit = 0;
    packet->data = 0b00100110; // ascii value for '&'
    packet->parity_bit = calculate_parity(packet->data);
    packet->stop_bit = 1;
    return packet;
}

/**
 * @brief Create a data packet
 *
 * @param data The data to create the packet for
 * @return The data packet
 */
Packet* create_data_packet(unsigned int data)
{
    Packet* packet = (Packet*)malloc(sizeof(Packet));
    packet->start_bit = 0;
    packet->data = data;
    packet->parity_bit = calculate_parity(packet->data);
    packet->stop_bit = 1;
    return packet;
}

/**
 * @brief Create a final packet
 *
 * @note The final packet is '%' in ASCII
 *
 * @return The final packet
 */
Packet* create_final_packet()
{
    Packet* packet = (Packet*)malloc(sizeof(Packet));
    packet->start_bit = 0;
    packet->data = 0b00100101; // ascii value for '%'
    packet->parity_bit = calculate_parity(packet->data);
    packet->stop_bit = 1;
    return packet;
}
