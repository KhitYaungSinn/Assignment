#include <stdio.h>
#include <stdlib.h>

#define MAXOFSTACK 10
int tocount = 0;
struct stack
{
    int data[MAXOFSTACK];
    int top;
};
typedef struct stack st;

void create_EmptyStack(st *myStack)
{
    myStack->top = -1;
}

int isStackIsFull(st *myStack)
{
    if (myStack->top == MAXOFSTACK - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int pushToStack(st *myStack, int value)
{
    if (isStackIsFull(myStack))
    {
        printf("Stack is Full");
    }
    else
    {
        myStack->top++;
        myStack->data[myStack->top] = value;
    }
    tocount++;
}
int isStackIsEmpty(st *mySatck)
{
    if (mySatck->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int popFromStack(st *myStack)
{
    if (isStackIsEmpty(myStack))
    {
        printf("Stack is Empty");
    }
    else
    {
        printf("data from stack : %d \n", myStack->data[myStack->top]);
        myStack->top--;
    }
    // tocount--;
}
int printFromStack(st *myStack)
{
    if (isStackIsEmpty(myStack))
    {
        printf("Stack is Empty");
    }
    else
    {
        printf("There are %d data in Stack. They are ", tocount);
        for (int i = myStack->top; i >= 0; i--)
        {
            printf("%d ,", myStack->data[i]);
        }
    }
}
int main()
{
    st *myStack = malloc(sizeof(st));
    create_EmptyStack(myStack);

    pushToStack(myStack, 10);
    pushToStack(myStack, 11);
    pushToStack(myStack, 12);
    pushToStack(myStack, 13);
    pushToStack(myStack, 14);
    pushToStack(myStack, 15);
    pushToStack(myStack, 16);

    printFromStack(myStack);

    return 0;
}