#include <stdio.h>
#include <stdlib.h>
#include "../inc/stack.h"

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

void ListIs(linkedlist *linkedlist)
{
        if(linkedlist != NULL) {
                node *current = linkedlist->head;
                int num = 0;
                while (current != NULL)
                {
                        puts("___________");
                        puts("|          |");
                        printf("|    %d    |\n", current->data);
                        puts("|          |");
                        puts("___________");
                        ++num;
                        current = current->next;
                }
                printf("\n");
        } else {
                puts("Error, stack does not exist!");
        }
}

int stackoverflow(linkedlist *stack)
{
        node *current = stack->head;
        int count = 0;
        while (current != NULL)
        {
                count++;
                current = current->next;
        }
        return (count >= STACKSIZE) ? 1 : 0;
}

int stackunderflow(linkedlist *stack)
{
        return (stack->head != NULL) ? 0 : 1;
}

int Push(int data, linkedlist *stack)
{
        if(!stackoverflow(stack)) {
                node *current = NULL;
                if(stack->head == NULL) {
                        if ((stack->head = createnode(data)) == NULL) {
                                return 1;
                        }
                } else {
                        //todo add parametr next for createnode
                        node *newNode = createnode(data);
                        if (newNode == NULL) {
                                return 1;
                        }
                        newNode->next = stack->head;
                        stack->head = newNode;
                }
                return 0;
        } else {
                return -1;
        }
}

int Read(int *data, linkedlist *stack)
{
        if (stackunderflow(stack)) {
                return 1;
        }  else {
                node *current = stack->head;
                *data = current->data;
                return 0;
        }
}

int Pop(int *data, linkedlist *stack)
{
        if (Read(data, stack) == 0) {
                node *current = stack->head;
                stack->head = current->next;
                free(current);
                return 0;
        } else {
                return 1;
        }

}

void ListRemove(linkedlist *stack)
{
        node *current = stack->head;
        node *next = current;
        while(current != NULL) {
                next = current->next;
                free(current);
                current = next;
        }
        free(stack);
}
