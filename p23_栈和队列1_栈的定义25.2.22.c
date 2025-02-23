/*

����һ��ջ

��ջ

��ջ

*/


#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100

typedef struct
{
    int *base;
    int *top;
    int stackSize;
    int data[256];
}Stack;

//��ʼ��ջ
void initStack(Stack *s);

//��ջ
void push(Stack *s, int a);

//��ջ
void pop(Stack *s);

int main()
{
    Stack s;
    initStack(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    
    return 0;
}

void initStack(Stack *s)
{
    s->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    if(!s->base)
    {
        exit(0);
    }
    s->top = s->base;//�ʼջ������ջ��
    s->stackSize = STACK_INIT_SIZE;
}

void push(Stack *s, int a)
{
    if(*(s->top) == STACK_INIT_SIZE - 1)
    {
        printf("ջ����!\n");
        return;
    }
    else
    {
        printf("ѹ��%d\n",a);
        *(s->top) = a;
        s->top++;
    }
}

void pop(Stack *s)
{
    if(s->top == s->base)
    {
        printf("ջ�ѿտ���Ҳ\n");
        return;
    }
    else
    {
        s->top--;
        printf("����%d\n",*(s->top));
    }
}
