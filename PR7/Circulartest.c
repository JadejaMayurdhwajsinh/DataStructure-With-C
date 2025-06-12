#include <stdio.h>
#include "Circular.c"

int main()
{
    LIST *lst = createList();
    insertfront(lst, 50);
    insertfront(lst, 40);
    insertfront(lst, 30);
    insertfront(lst, 20);
    insertfront(lst, 10);
    display(lst);

    insertend(lst, 70);
    insertend(lst, 80);
    insertend(lst, 90);
    insertend(lst, 100);
    display(lst);

    deletefront(lst);
    deletefront(lst);
    deletefront(lst);
    display(lst);

    deleteend(lst);
    deleteend(lst);
    display(lst);

    deletemiddle(lst);
    display(lst);

    insertafter(lst, 120, 3);
    display(lst);

    insertBeforevalue(lst, 120, 150);
    display(lst);

    insertAftervalue(lst, 120, 170);
    display(lst);
    return 0;
}