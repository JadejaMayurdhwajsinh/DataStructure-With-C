// Create a function in C to accept an integer and function pointer as argument. Write a C
// program with two functions, one which increments the int argument by 2 and the other
// which decrements the int argument by 2. Demonstrate the use of passing pointer to
// function argument using these three functions. User will enter an integer number and
// select if he wants to add or subtract the number.

#include <stdio.h>
void increment(int *num);
void decrement(int *num);
void modifyNumber(int num, void (*operation)(int *));

int main()
{
    int number;
    int choice;

    printf("Enter an integer number: ");
    scanf("%d", &number);

    printf("Select an operation:\n");
    printf("1. Add 2\n");
    printf("2. Subtract 2\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

       if (choice == 1)
    {
        modifyNumber(number, increment);
    }
    else if (choice == 2)
    {
        modifyNumber(number, decrement);
    }
    else
    {
        printf("Invalid choice!\n");
    }

    return 0;
}

void increment(int *num)
{
    *num += 2;
    printf("Result after incrementing: %d\n", *num);
}

void decrement(int *num)
{
    *num -= 2;
    printf("Result after decrementing: %d\n", *num);
}

void modifyNumber(int num, void (*operation)(int *))
{
    operation(&num);
}
