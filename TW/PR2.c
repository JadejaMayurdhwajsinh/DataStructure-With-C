#include "Stack_LL.c"
#include <string.h>

void reverseExpresion(char *expr)
{
    Stack *stack = createStack();
    int idx = 0;
    while (expr[idx] != '\0')
    {
        push(stack, expr[idx++]);
    }
    idx = 0;
    while (!isEmptyStack(stack))
    {
        expr[idx++] = pop(stack);
    }
}

int precidence(char sign)
{
    if (sign == '^')
        return 3;
    else if (sign == '*' || sign == '/' || sign == '%')
        return 2;
    else if (sign == '+' || sign == '-')
        return 1;
    else
        return 0;
}
int isValideExpresion(char *exp)
{
    Stack *stack = createStack();
    int count = 0;
    int idx = 0;
    while (exp[idx] != '\0')
    {
        char ch = exp[idx++];
        if (ch == '+' || ch == '-' || ch == '/' || ch == '%' || ch == '^' || ch == '(' || ch == ')')
        {
            if (ch == '(')
                push(stack, ch);
            else if (ch == ')')
            {
                if (isEmptyStack(stack) || peak(stack) != '(')
                    return 0;
                pop(stack);
            }
            count++;
        }
    }
    return isEmptyStack(stack) && count;
}
void postFix(char *expr)
{
    int n = strlen(expr);
    char *postfix = (char *)calloc(n, sizeof(char));
    Stack *stack = createStack();
    int idx = 0;
    int i = 0;
    while (expr[idx] != '\0')
    {
        char ch = expr[idx++];
        if (ch == ' ')
            continue;
        else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            postfix[i++] = ch;
        else if (ch == ')')
            push(stack, ch);
        else if (ch == '(')
        {
            while (!isEmptyStack(stack) && peak(stack) != ')')
            {
                postfix[i++] = pop(stack);
            }
            pop(stack);
        }
        else
        {
            while (!isEmptyStack(stack) && precidence(ch) < precidence(peak(stack)))
            {
                postfix[i++] = pop(stack);
            }
            push(stack, ch);
        }
    }
    while (!isEmptyStack(stack))
    {
        postfix[i++] = pop(stack);
    }
    postfix[i] = '\0';
    i = 0;
    while (postfix[i] != '\0')
    {
        expr[i] = postfix[i];
        i++;
    }
    expr[i] = '\0';
}

int preFix(char *expr)
{
    if (!isValideExpresion(expr))
    {
        return 0;
    }
    reverseExpresion(expr);
    postFix(expr);
    reverseExpresion(expr);
    return 1;
}

int main()
{
    char *infix = (char *)calloc(20, sizeof(char));

    printf("\nEnter String 1 : ");
    scanf(" %[^\n]", infix);

    if (preFix(infix))
    {
        printf("%s", infix);
    }
    else
    {
        printf("\nInvalid Expresion !!");
    }
    return 0;
}