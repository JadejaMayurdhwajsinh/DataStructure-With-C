// Define a structure which has members that include book_name(50
// characters), id_no(10 characters) and price(float value). Write a C program
// to read the information about N books. Program should provide an option to
// print the name and id_no of the books having price less than M. Create
// separate functions for collecting data, displaying data, and Filtering Data.
// Collect N and M from the user via command line arguments.

#include <stdio.h>
#include <stdlib.h>

struct book
{
    char name[50];
    char id_no[10];
    float price;
};

void collectdata(struct book b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n enter the name of book %d ", i + 1);
        scanf("%s", b[i].name);
        printf("\n enter the id_no of book %d ", i + 1);
        scanf("%s", b[i].id_no);
        printf("\n enter the price of book %d ", i + 1);
        scanf("%f", &b[i].price);
    }
}

void displaydata(struct book b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n the name of book %d is %s", i + 1, b[i].name);
        printf("\n the id_no of book %d is %s", i + 1, b[i].id_no);
        printf("\n the price of book %d is %.2f", i + 1, b[i].price);
    }
}

void filterdata(struct book b[], int n, float price)
{
    printf("\n book with price less than %.2f ", price);
    for (int i = 0; i < n; i++)
    {
        if (b[i].price < price)
        {
            printf("\n book name is %s book id is %s book price is %.2f \n", b[i].name, b[i].id_no, b[i].price);
        }
    }
}

void separator(int a)
{
    if (a == 1)
    {
        printf("\n--------------------------------------\n");
    }
    else
    {
        printf("\n''''''''''''''''''''''''''''''''''''''''''\n");
    }
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    float price = atof(argv[2]);
    struct book b[n];
    collectdata(b, n);
    separator(1);
    displaydata(b, n);
    separator(0);
    filterdata(b, n, price);
    return 0;
}