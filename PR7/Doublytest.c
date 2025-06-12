#include <stdio.h>
#include "Doubly.c"

int main()
{
    DLIST *dlst = createlist();

    insertfront(dlst, 20);
    insertfront(dlst, 10);
    displayforward(dlst);

    insertend(dlst, 30);
    insertend(dlst, 40);
    displayforward(dlst);
    displaybackward(dlst);

    // deletefirst(dlst);
    // displayforward(dlst);
    // displaybackward(dlst);

    // deleteend(dlst);
    // displayforward(dlst);
    // displaybackward(dlst);

    insertAtpos(dlst, 50, 2);
    displayforward(dlst);

    deleteAtpos(dlst, 2);
    displayforward(dlst);
    return 0;
}