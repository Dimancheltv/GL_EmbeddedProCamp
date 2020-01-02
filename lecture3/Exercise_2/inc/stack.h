#ifndef STACK_H
#define STACK_H

/*!
   @brief structure that is the node of the linkedlist.
 */
typedef struct node {
        int data;
        struct node *next;
} node;

/*!
   @brief structure that is a linkedlist.
 */
typedef struct linkedlist {
        node *head;
} linkedlist;

/*!
   @brief const for size stack.
 */
#define STACKSIZE 10

/*!
   @brief function add element
   @param data is value for new element
   @param stack is pointer on stack
   @return int status
 */
int Push(int data, linkedlist *stack);

/*!
   @brief function read element and remove from stack
   @param data is pointer on data that getting
   @param stack is pointer on stack
   @return int status
 */
int Pop(int *data, linkedlist *stack);

/*!
   @brief function read element from stack
   @param data is pointer on data that getting
   @param stack is pointer on stack
   @return int status
 */
int Read(int *data, linkedlist *stack);

/*!
   @brief function creates a new list item.
   @param value is data for new item
   @return pointer to the created item
 */
node *createnode(int value);

/*!
   @brief function creates a new linkedlist.
   @return pointer to the created linkedlist
 */
linkedlist *createlist(void);

/*!
   @brief function checks stack overflow.
   @param stack is pointer on stack
   @return int status, 1 - stackoverflow.
 */
int stackoverflow(linkedlist *stack);

/*!
   @brief function checks stack underflow.
   @param stack is pointer on stack
   @return int status, 1 - stackunderflow.
 */
int stackunderflow(linkedlist *stack);

/*!
   @brief function deletes the all linkedlist from memory.
   @param *stack is a pointer to the linkedlist  to be deleted
 */
void ListRemove(linkedlist *stack);

/*!
   @brief functions to display all nodes in the linkedlist.
   @param *stack is a pointer to the linkedlist to be displayed
 */
void ListIs(linkedlist *stack);

#endif
