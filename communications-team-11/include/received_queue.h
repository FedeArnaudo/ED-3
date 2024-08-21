#ifndef RECEIVED_QUEUE_H
#define RECEIVED_QUEUE_H

#include "../include/packet.h"

/**
 * Node structure
 */
typedef struct Node
{
    Packet* packet;
    struct Node* next;
} Node;

/**
 * Queue structure
 */
typedef struct
{
    Node* front;
    Node* rear;
} Queue;

Queue* create_queue();
void enqueue(Queue* queue, Packet* packet);
Packet* dequeue(Queue* queue);
int is_queue_empty(Queue* queue);
void free_queue(Queue* queue);

#endif // RECEIVED_QUEUE_H
