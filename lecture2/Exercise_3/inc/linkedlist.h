#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
   @brief function adds a new node to the linkedlist.
   @param value is data for new node
   @param *linkedlist is a pointer to the inkedlist to which a new item is added
   @notice function adds a value at the end of the linkedlist
   @return pointer to an added item
 */
node *ListAdd(int value, linkedlist *linkedlist);

/*!
   @brief functions to display all nodes in the linkedlist.
   @param *linkedlist is a pointer to the linkedlist to be displayed
 */
void ListIs(linkedlist *linkedlist);

/*!
   @brief function deletes the all linkedlist from memory.
   @param *linkedlist is a pointer to the linkedlist  to be deleted
 */
void ListRemove(linkedlist *linkedlist);

/*!
   @brief function removes a node from the memory that contains the specified value.
   @param data is the value of the node to be deleted
   @param *linkedlist is a pointer to the linkedlist
   @notice function removes a node from the beginning of the linkedlist
   @return int status of the operation, 0 - successfully
 */
int delete(int data, linkedlist *linkedlist);

#endif
