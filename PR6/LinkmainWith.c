#include <stdio.h>
#include "LinkWith.c"

int main()
{
    LIST *lst1 = createList();
    LIST *lst2 = createList();

    // insertend(lst1, 10);
    // insertend(lst1, 20);
    // insertend(lst1, 30);

    insertend(lst2, 40);
    insertend(lst2, 50);
    insertend(lst2, 80);
    insertend(lst2, 30);
    insertend(lst2, 10);

    insertend(lst1, 10);
    insertend(lst1, 20);
    insertend(lst1, 30);
    insertend(lst1, 40);
    display(lst1);
    display(lst2);

    // concateList(lst1, lst2);

    // display(lst1);
    // display(lst2);
    // printf("%d ", countnode(lst1));
    // printf("\n");
    // // findendnode(lst1, 2);
    // swap(lst1, 0, 1);
    // display(lst1);
    reverseList2(lst2);
    display(lst2);

    LIST *lst3 = createList();
    insertend(lst3, 10);
    insertend(lst3, 20);
    insertend(lst3, 30);
    insertend(lst3, 20);
    insertend(lst3, 10);
    display(lst3);
    printf("%d ", isPalindrome(lst3));

    // LIST *lst = createList();
    // insertend(lst, 10);
    // insertend(lst, 20);
    // insertend(lst, 30);
    // insertend(lst, 40);
    // insertend(lst, 50);
    // insertend(lst, 60);
    // display(lst);
    // swapNode(lst, 1, 2);
    // display(lst);
    // insertfront(lst, 30);
    // insertfront(lst, 20);
    // insertfront(lst, 10);
    // insertend(lst, 40);
    // insertend(lst, 60);
    // insertend(lst, 70);
    // insertend(lst, 50);
    // display(lst);
    // printf("Deleted from front %d \n ", deletefront(lst));
    // display(lst);
    // printf("Deleted from end %d \n ", deleteend(lst));
    // display(lst);
    // // reverselist(lst);
    // // display(lst);
    // printf("middle element is %d \n", findmiddle(lst));
    // insertAtposition(lst, 3, 80);
    // display(lst);
}