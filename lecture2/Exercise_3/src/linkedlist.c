#include <stdio.h>
#include <stdlib.h>
#include "../inc/linkedlist.h"

node *createnode(int data)
{
        node *newNode = malloc(sizeof(node));
        if (!newNode) {
                return NULL;
        }
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
}

linkedlist *createlist(void)
{
        linkedlist *linkedlist = malloc(sizeof(linkedlist));
        if (!linkedlist) {
                return NULL;
        }
        linkedlist->head = NULL;
        return linkedlist;
}

node *ListAdd(int data, linkedlist *linkedlist)
{
        node * current = NULL;
        if(linkedlist->head == NULL) {
                return linkedlist->head = createnode(data);
        } else {
                current = linkedlist->head;

                while (current->next!=NULL) {
                        current = current->next;
                }
                return current->next = createnode(data);
        }
}

void ListIs(linkedlist *linkedlist)
{
        node *current = linkedlist->head;
        int num = 0;
        while (current != NULL)
        {
                printf("Node[%d] 0x%x\tvalue = %d\tnext node 0x%x\n",
                       num,
                       current,
                       current->data,
                       current->next);
                ++num;
                current = current->next;
        }

        printf("\n");
}

void ListRemove(linkedlist *linkedlist)
{
        node *current = linkedlist->head;
        node *next = current;
        while(current != NULL) {
                next = current->next;
                free(current);
                current = next;
        }
        free(linkedlist);
}

int delete(int data, linkedlist *linkedlist)
{
        node *current = linkedlist->head;
        node *previous = current;
        while(current != NULL) {
                if(current->data == data) {
                        previous->next = current->next;
                        if(current == linkedlist->head)
                                linkedlist->head = current->next;
                        free(current);
                        return 0;
                }
                previous = current;
                current = current->next;
        }
        return 1;
}
