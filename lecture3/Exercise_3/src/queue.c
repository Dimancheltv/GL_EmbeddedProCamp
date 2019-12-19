#include <stdio.h>
#include <stdlib.h>
#include "../inc/queue.h"

queue *create_queue(void)
{
        queue *newqueue = malloc(sizeof(queue));
        newqueue->front = 1;
        newqueue->rear = 0;
        return newqueue;
}

int isempty(queue *queue) {
        if(queue->rear < queue->front) return(1);
        else return(0);
}

int Put(queue *queue, int value) {
        if(queue->rear < QUEUESIZE-1) {
                queue->rear++;
                queue->qu[queue->rear]=value;
                return 0;
        } else {
                return -1;
        }
}

int Read(int *data, queue *queue)
{
        if(isempty(queue)==1) {
                return -1;
        } else {
                *data = queue->qu[queue->front];
                return 0;
        }
}

int Get(int *data, queue *queue) {
        int value, h;
        if (Read(data, queue) == 0) {

                for(h = queue->front; h < queue->rear; h++) {
                        queue->qu[h] = queue->qu[h+1];
                }
                queue->rear--;

                return 0;
        } else {
                return -1;
        }
}

int print(queue *queue) {
        int h;
        if(isempty(queue)==1) {
                return -1;
        }
        for(h = queue->front; h<= queue->rear; h++) {
                puts("___________");
                puts("|          |");
                printf("|    %d    |\n", queue->qu[h]);
                puts("|          |");
                puts("___________");
        }
        printf("\n");
        return 0;
}
