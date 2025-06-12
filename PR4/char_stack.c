#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
// #define n 10
typedef struct
{
    int top;
    char *name;
    int size;
} CHAR_STACK;

CHAR_STACK *createStack(int n)
{
    CHAR_STACK *s = (CHAR_STACK *)malloc(sizeof(CHAR_STACK));
    s->top = -1;
    s->size = n;
    s->name = (char *)calloc(s->size, sizeof(char));
    return s;
}

int isEmpty(CHAR_STACK *s)
{
    return s->top == -1;
}

int isFull(CHAR_STACK *s)
{
    return s->top >= s->size - 1;
}

void push(CHAR_STACK *s, char el)
{
    if (isFull(s))
    {
        printf("\n stack is full");
        return;
    }
    s->top += 1;
    s->name[s->top] = el;
}

char pop(CHAR_STACK *s)
{
    char x;
    if (isEmpty(s))
    {
        printf("\n stack is empty");
        return '\0';
    }
    x = s->name[s->top];
    s->top -= 1;
    return x;
}

char peak(CHAR_STACK *s)
{
    if (isEmpty(s))
    {
        printf("\n stack is empty");
        return '\0';
    }
    return s->name[s->top];
}

void display(CHAR_STACK *s)
{
    for (int i = s->top; i >= 0; i--)
    {
        printf("%c", s->name[i]);
    }
}
int chechprecedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/' || ch == '%')
    {
        return 2;
    }
    else if (ch == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

void stackDestroy(CHAR_STACK *s)
{
    free(s);
    s = NULL;
}

void eval(CHAR_STACK *s)
{
    int num1, num2, ans = 0;
    char *e;
    e = s->name;
    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            push(s, *e);
        }
        else if (*e == '+' || *e == '-' || *e == '*' || *e == '/' || *e == '^' || *e == '%')
        {
            num1 = pop(s) - '0';
            num2 = pop(s) - '0';
            switch (*e)
            {
            case '+':
                ans = num2 + num1;
                break;
            case '-':
                ans = num2 - num1;
                break;
            case '*':
                ans = num2 * num1;
                break;
            case '/':
                ans = num2 / num1;
                break;
            case '%':
                ans = num2 % num1;
                break;
            case '^':
                ans = num2 ^ num1;
                break;
            }
            push(s, ans + '0');
        }
        e++;
    }
    printf("\n ans = %d ", ans);
}

void itop(CHAR_STACK *s)
{
    printf("\n enter infix expression");
    scanf("%s", s->name);
    char postfix[strlen(s->name)];
    char *e;
    e = s->name;
    int index = 0;
    while (*e != '\0')
    {
        if (isalpha(*e))
        {
            postfix[index++] = *e;
        }
        else if (*e == '(')
        {
            push(s, *e);
        }
        else if (*e == ')')
        {
            while ((!isEmpty(s)) && peak(s) != '(')
            {
                postfix[index++] = pop(s);
            }
            pop(s);
        }
        else
        {
            while (!isEmpty(s) && chechprecedence(peak(s)) >= chechprecedence(*e))
            {
                postfix[index++] = pop(s);
            }
            push(s, *e);
        }
        e++;
    }
    while (!isEmpty(s))
    {
        postfix[index++] = pop(s);
    }
    printf("\n infix to postfix %s", postfix);
}

void reverseString(CHAR_STACK *s)
{
    printf("Enter a string: ");
    scanf(" %[^\n]", s->name);
    char *ptr = s->name;

    char reversed[strlen(s->name)];
    char *revPtr = reversed;

    while (*ptr != '\0')
    {
        push(s, *ptr);
        ptr++;
    }

    while (!isEmpty(s))
    {
        *revPtr = pop(s);
        revPtr++;
    }
    *revPtr = '\0';

    printf("Reversed string: %s\n", reversed);
}

void sortStack(CHAR_STACK *input)
{
    CHAR_STACK *temp = createStack(input->size);

    while (!isEmpty(input))
    {
        int tmp = pop(input);

        while (!isEmpty(temp) && peek(temp) > tmp)
        {
            push(input, pop(temp));
        }

        push(temp, tmp);
    }

    while (!isEmpty(temp))
    {
        push(input, pop(temp));
    }

    free(temp->name);
    free(temp);
}

int isMatchingPair(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

void checkBalancedParentheses(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("File cannot be opened.\n");
        return;
    }

    CHAR_STACK *stack = createStack(1000);
    char ch;
    int balanced = 1;

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            push(stack, ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (isEmpty(stack) || !isMatchingPair(pop(stack), ch))
            {
                balanced = 0;
                break;
            }
        }
    }

    if (!isEmpty(stack))
    {
        balanced = 0;
    }

    fclose(fp);
    free(stack->name);
    free(stack);

    if (balanced)
        printf("Parentheses are balanced.\n");
    else
        printf("Parentheses are NOT balanced.\n");
}
