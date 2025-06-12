#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *book_name;
    char *author_name;
    int price;
    int pages;
} book;

void collect(book *b, int n)
{
    for (int i = 0; i < n; i++)
    {
        b->book_name = (char *)malloc(20);
        b->author_name = (char *)malloc(30);
        printf("\n enter the details for book %d", i + 1);
        printf("\n enter book name");
        scanf(" %[^\n]", b->book_name);
        printf("\n enter author name");
        scanf(" %[^\n]", b->author_name);
        printf("\n enter book price");
        scanf("%d", &b->price);
        printf("\n enter book pages");
        scanf("%d", &b->pages);
        b++;
    }
}

void display(book *b, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n book%d name %s", i + 1, b->book_name);
        printf("\n book%d author %s", i + 1, b->author_name);
        printf("\n book%d price %d", i + 1, b->price);
        printf("\n book%d pages %d", i + 1, b->pages);
        b++;
    }
}

void filter(book *b, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (b->book_name[0] == 'D' || b->book_name[0] == 'd')
        {
            printf("\n---------book name starts with d------------------\n");
            printf("\n book%d name %s", i + 1, b->book_name);
            printf("\n book%d author %s", i + 1, b->author_name);
            printf("\n book%d price %d", i + 1, b->price);
            printf("\n book%d pages %d", i + 1, b->pages);
        }
        b++;
    }
}

void main()
{
    int n;
    printf("\n enter n");
    scanf("%d", &n);
    book *b = (book *)malloc(n * sizeof(book));
    collect(b, n);
    display(b, n);
    filter(b, n);
    // return 0;
}