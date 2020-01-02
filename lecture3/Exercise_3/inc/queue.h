#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*! queue size */
#define QUEUESIZE 10

/*!
   @brief structure of queue.
 */
typedef struct {
        int qu[QUEUESIZE];
        int rear;
        int front;
} queue;

/*!
   @brief function creates a new queue.
   @return pointer to the created queue
 */
queue *create_queue(void);

/*!
   @brief function add element
   @param value is value for new element
   @param queue is pointer on queue
   @return int status, 0 - success.
 */
int Put(queue *queue, int value);

/*!
   @brief function read element and remove from queue
   @param data is pointer on data that getting
   @param queue is pointer on queue
   @return int status, 0 - success.
 */
int Get(int *data, queue *queue);

/*!
   @brief function read element from queue
   @param data is pointer on data that getting
   @param queue is pointer on queue
   @return int status, 0 - success.
 */
int Read(int *data, queue *queue);

/*!
   @brief functions to display all elements from queue.
   @param *queue is a pointer to the queue to be displayed
   @return int status, 0 - success.
 */
int print(queue *queue);

/*!
   @brief functions to check queue underflow.
   @param queue is pointer on queue
   @return int status, 1 - is empty.
 */
int isempty(queue *queue);

#endif
