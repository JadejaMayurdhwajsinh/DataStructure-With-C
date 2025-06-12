#include <stdio.h>
#include <stdlib.h>
#include "LinkList.c"
int main()
{
    SNODE *head = NULL;
    head = insertend(head, 10);
    head = insertend(head, 20);
    head = insertend(head, 30);
    head = insertfront(head, 40);
    head = insertfront(head, 50);
    head = insertfront(head, 60);

    // head = deletefront(head);
    // head = deleteend(head);
    // head = insertAfterpos(head, 2, 33);
    // head = insertAtpos(head, 3, 34);
    // head = insertAtpos(head, 3, 34);
    // head = insertAtBeforepos(head, 3, 44);
    // head = insertAfterpos(head, 1, 53);

    display(head);
    head = reverselist(head);
    display(head);

    head = findmiddle(head);

    // head = delteAfterpos(head, 2);
    // head = valueinsert(head, 11, 30);
    // display(head);
}