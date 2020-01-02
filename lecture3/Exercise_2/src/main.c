/*!
   @brief Exercise_2 - Program for demonstration stack library based on linked list.
   @details Task: Create stack library based on linked list:
   -	int Push(int);    // add element
   -	int Pop(*int);    // read element and remove from stack
   -	int Read(*int);  // read element without removing it from stack
   @author Dmytro Lytvyniuk
   @date December
   @warning This program was created for educational purposes.
 */

#include <string.h>
#include <ctype.h>
#include "stack.c"

#define PUSH "push"    /*!< command to add element */
#define POP "pop"      /*!< command to read element and remove from stack */
#define READ "read"    /*!< command to read element */
#define EXIT "exit"    /*!< command to exit */

/*!
   @brief function gets numbers from string.
   @param *input is a input string
   @return int number
 */
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
        /*! init stack */
        linkedlist *stack = createlist();
        char command[100];
        int data;

        if(stack != NULL) {
                /*! default values for demo */
                printf("Max stack size: %i elements\nDefault values for demo:\n", STACKSIZE);
                Push(22, stack);
                Push(10, stack);
                Push(90, stack);
                /*! display all stack */
                ListIs(stack);
                /*! user command manual */
                printf("FOR ADD ELEMENT USE COMMAND: %s [integer value]\n", PUSH);
                printf("FOR READ AND REMOVE ELEMENT USE COMMAND: %s\n", POP);
                printf("FOR READ ELEMENT USE COMMAND: %s\n", READ);
                printf("FOR EXIT USE COMMAND: %s\n\n", EXIT);

                while(strstr(command, EXIT) == NULL) {
                        printf("Enter command for stack: ");
                        gets(command);
                        if(strstr(command, PUSH)) {
                                /*! add element */
                                (Push(getvalue(command), stack) != 0) ? (puts("Push error\n")) : (puts("Push success\n"));
                                ListIs(stack);
                        } else if(strstr(command, POP)) {
                                /*! read element and remove from stack */
                                (Pop(&data, stack) != 0) ? (puts("Pop error\n")) : (printf("value: %i\n", data));
                                ListIs(stack);
                        } else if(strstr(command, READ)) {
                                /*! read element without removing it from stack */
                                (Read(&data, stack) != 0) ? (puts("Read error\n")) : (printf("value: %i\n", data));
                                ListIs(stack);
                        }
                }
                /*! delete stack from memory */
                ListRemove(stack);

                /*! for demo test, pause in console */
                system("pause");
        }
}
