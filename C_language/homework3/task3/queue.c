#include "queue.h"

#define CAPACITY 100
int queue[CAPACITY];
unsigned int size  = 0;
unsigned int back  = CAPACITY - 1;   // Initally assumed that back is at end
unsigned int front = 0;


/**
 * Enqueue/Insert an element to the queue. 
 */
int enqueue(int data)
{
    // Queue is full throw Queue out of capacity error.
    if (isFull()) 
    {
        return 1;
    }

    // Ensure back never crosses array bounds
    back = (back + 1) % CAPACITY;

    // Increment queue size
    size++;

    // Enqueue new element to queue
    queue[back] = data;

    // Successfully enqueued element to queue
    return 0;
}


/**
 * Dequeue/Remove an element from the queue. 
 */
int dequeue()
{
    int data = -1;

    // Queue is empty, throw Queue underflow error
    if (isEmpty())
    {
        return 1;
    }

    // Dequeue element from queue
    data = queue[front];

    // Ensure front never crosses array bounds
    front = (front + 1) % CAPACITY;

    // Decrease queue size
    size--;

    return data;
}

int isFull()
{
    return (size == CAPACITY);
}

int isEmpty()
{
    return (size == 0);
}


/**
 * Gets, front of the queue. If queue is empty return -1 otherwise
 * returns front of queue.
 */
int getFront()
{
    return (isEmpty()) ? -1 : queue[front];
}


/**
 * Gets, back of the queue. If queue is empty return 0 otherwise
 * returns back of queue.
 */
int getBack()
{
    return (isEmpty()) ? 0 : queue[back];
}