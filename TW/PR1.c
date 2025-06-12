#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "char_LL.c"

int compareString(LIST *list1, LIST *list2)
{
    SNODE *temp1 = list1->head;
    SNODE *temp2 = list2->head; 
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            return (temp1->data > temp2->data ? 1 : -1); 
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (temp1 == NULL && temp2 == NULL)
    {
        return 0;
    }
    else if (temp1 == NULL)
    {
        return -1;
    }
    else
    {
       return 1;  
    }
}

int main()
{
    char str1[10];
    char str2[10];

    printf("Enter string 1 : ");
    scanf("%s", &str1);

    printf("Enter string 2 : ");
    scanf("%s", &str2);

    LIST *list1 = createList();
    LIST *list2 = createList();

    for (int i = 0; i < strlen(str1); i++)
    {
        insertend(list1, str1[i]);
    }

    for (int i = 0; i < strlen(str2); i++)
    {
        insertend(list2, str2[i]);
    }
    printf("%d",compareString(list1, list2));
    free(list1);
    free(list2);
    return 0;
}