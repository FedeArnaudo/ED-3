#include "../include/received_queue.h"
#include <stdlib.h>

/**
 *  @brief  Create a new queue
 *
 *  @return Queue *  The pointer to the new queue
 */
Queue* create_queue()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

/**
 * @brief Enqueue a packet to the queue
 *
 * @param queue The queue to enqueue the packet
 * @param packet The packet to enqueue
 */
void enqueue(Queue* queue, Packet* packet)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->packet = packet;
    new_node->next = NULL;
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = new_node;
        return;
    }
    queue->rear->next = new_node;
    queue->rear = new_node;
}

/**
 * @brief Dequeue a packet from the queue
 *
 * @param queue The queue to dequeue the packet
 * @return Packet* The dequeued packet
 */
Packet* dequeue(Queue* queue)
{
    if (queue->front == NULL)
        return NULL;
    Node* temp = queue->front;
    Packet* packet = temp->packet;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(temp);
    return packet;
}

/**
 * @brief Check if the queue is empty
 *
 * @param queue The queue to check
 * @return int 1 if the queue is empty, 0 otherwise
 */
int is_queue_empty(Queue* queue)
{
    return queue->front == NULL;
}

/**
 * @brief Free the queue and all its packets
 *
 * @param queue The queue to free
 */
void free_queue(Queue* queue)
{
    while (!is_queue_empty(queue))
    {
        free(dequeue(queue));
    }
    free(queue);
}