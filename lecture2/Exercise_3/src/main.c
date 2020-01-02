/*!
   @brief Exercise_3 - Program for demonstration linked list library.
   @details Task: Create linked list library  with functions (ListAdd(), ListIs(), ListRemove()).
   New elements in list should be dynamically allocated.
   @author Dmytro Lytvyniuk
   @date December
   @warning This program was created for educational purposes.
 */

#include <string.h>
#include <ctype.h>
#include "linkedlist.c"

#define ADD "add" /*!< command to add node */
#define DELETE "delete" /*!< command to remove node */
#define EXIT "exit" /*!<  command to remove linkedlist from memory */

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

int main(void)
{
        linkedlist * list = createlist();
        char command[100];

        if(list != NULL) {

                /*! default values for demo */
                ListAdd(22, list);
                ListAdd(10, list);
                ListAdd(90, list);
                /*! demonstration display function */
                ListIs(list);

                printf("FOR ADD NODE USE COMMAND: %s [integer value]\n", ADD);
                printf("FOR DELETE NODE USE COMMAND: %s [integer value]\n", DELETE);
                printf("FOR DELETE LINKEDLIST AND EXIT USE COMMAND: %s\n\n", EXIT);

                while(strstr(command, EXIT) == NULL) {
                        printf("Enter command for linkedlist: ");
                        gets(command);
                        if(strstr(command, ADD)) {
                                /*! demonstration add function */
                                (ListAdd(getvalue(command), list) == NULL) ? (puts("Error add\n")) : (puts("Add success\n"));
                                ListIs(list);
                        } else if(strstr(command, DELETE)) {
                                /*! demonstration delete node function */
                                (delete(getvalue(command), list) == 0) ? (puts("Delete success\n")) : (puts("Error delete\n"));
                                ListIs(list);
                        }

                }
                /*! delete linkedlist */
                ListRemove(list);
                puts("Linkedlist has been deleted.");
        } else {
                puts("Memory allocation error");
        }
        /*! for demo test, pause in console */
        system("pause");
        return 0;
}
