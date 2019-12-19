/*!
   @brief Exercise_3 - Program for demonstration queue library based on array.
   @details Task: Create queue library based on array:
    -	int Put(int);      // add element
    -	int Get(*int);     // read element and remove from queue
    -	Int Read(*int);	   // read element without removing it from queue
   @author Dmytro Lytvyniuk
   @date December
   @warning This program was created for educational purposes.
 */

 #include <string.h>
 #include <ctype.h>
 #include "queue.c"

 #define PUT "put"      /*!< command to add element */
 #define GET "get"      /*!< command to read element and remove from queue */
 #define READ "read"    /*!< command to read element */
 #define EXIT "exit"    /*!< command to exit */

int getvalue(char *input)
{
        int i = 0;
        int j = 0;
        char output[strlen(input)];
        while(input[i]) {
                if(isdigit(input[i])) {
                        output[j++] = input[i];
                }
                i++;
        }
        output[j] = '\0';
        return atoi(output);
}

void main(void)
{
        /*! init queue */
        queue *myqueue = create_queue();
        char command[100];
        int data;

        if(myqueue != NULL) {
                /*! default values for demo */
                printf("Max queue size: %i elements\nDefault values for demo:\n", QUEUESIZE);
                Put(myqueue, 26);
                Put(myqueue, 28);
                Put(myqueue, 22);
                /*! display all queue */
                print(myqueue);

                /*! user command manual */
                printf("FOR ADD ELEMENT USE COMMAND: %s [integer value]\n", PUT);
                printf("FOR READ AND REMOVE ELEMENT USE COMMAND: %s\n", GET);
                printf("FOR READ ELEMENT USE COMMAND: %s\n", READ);
                printf("FOR EXIT USE COMMAND: %s\n\n", EXIT);

                while(strstr(command, EXIT) == NULL) {
                        printf("Enter command for queue: ");
                        gets(command);
                        if(strstr(command, PUT)) {
                                /*! add element */
                                (Put(myqueue, getvalue(command)) != 0) ? (puts("Error! Queue overflow.\n")) : (puts("Put success\n"));
                                print(myqueue);
                        } else if(strstr(command, GET)) {
                                /*! read element and remove from queue */
                                (Get(&data, myqueue) != 0) ? (puts("Error! Queue underflow.\n")) : (printf("value: %i\n", data));
                                print(myqueue);
                        } else if(strstr(command, READ)) {
                                /*! read element without removing it from queue */
                                (Read(&data, myqueue) != 0) ? (puts("Read error\n")) : (printf("value: %i\n", data));
                                print(myqueue);
                        }
                }
        } else {
                printf("Error memory malloc");
        }

}
