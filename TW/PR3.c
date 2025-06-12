#include <stdio.h>
#include "int_LL.c"

SNODE *findknode(SNODE *head, int k)
{
    while (head->next != NULL && k != 1)
    {
        head = head->next;
        k--;
    }
    printf("\n%d\n", head->data);
    return head;
}

SNODE *reverselists(SNODE *head)
{
    SNODE *prev = NULL;
    SNODE *cur = head;
    SNODE *next = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    printf("\n%d\n", prev->data);
    return prev;
}

void bygroup(int k, LIST *li)
{
    SNODE *prev = NULL;
    SNODE *temp = li->head;
    while (temp != NULL && k)
    {
        SNODE *kth = findknode(temp, k);
        SNODE *next = kth->next;
        kth->next = NULL;
        SNODE *last = reverselists(temp);
        if (temp == li->head)
        {
            li->head = last;
        }
        else
        {
            prev->next = last;
        }
        temp->next = next;
        prev = temp;
        temp = next;
    }
}

int main()
{
    int n, k;
    printf("\n enter n : ");
    scanf("%d", &n);
    LIST *li = createList();
    for (int i = 1; i <= n; i++)
    {
        insertend(li, i);
    }
    printf("\n enter k : ");
    scanf("%d", &k);
    bygroup(k, li);
    display(li);
    free(li);
}