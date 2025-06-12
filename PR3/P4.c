#include "stdio.h"
#include "stdlib.h"
typedef struct
{
    int id;
    char *name;
    /* data */
} Employee;
void putData(Employee *e)
{
    printf("\nId: ");
    scanf("%d", &e->id);

    printf("\nName: ");
    e->name = (char *)calloc(20, sizeof(char));
    scanf("%s", e->name);
}

void display(Employee *e, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nId : %d", e->id);
        printf("\nname : %s", e->name);
        e++;
    }
}

void main()
{
    int n = 0;
    char op;
    Employee *e = (Employee *)calloc(1, sizeof(Employee));
    do
    {
        int ch = 0;
        printf("\n\n1.Add\t2.Display\t0.Exit");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            putData(&e[n]);
            n++;
            e = (Employee *)realloc(e, (n + 1) * sizeof(Employee));
            break;
        case 2:
            display(e, n);
            break;
        case 0:
            return;
        }
        printf("\n do you want to repeat?(y/n)");
        scanf(" %c", &op);
    } while (op == 'y');
}