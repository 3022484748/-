/*

����׺���ʽת��Ϊ��׺���ʽ
���磺
(1 - 2) * (4 + 5) ת��Ϊ 1 2 - 4 5 + *

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 20
#define STACKINCRIMENT  10
#define MAXBUFFER       10

typedef char ElemType;
typedef struct Stack
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}Stack;

void initStack(Stack *s);
void Push(Stack *s, ElemType e);
void Pop(Stack *s, ElemType *e);
int StackLen(Stack s);

int main()
{
    Stack s;
    initStack(&s);

    printf("���������������,�����������֮���ÿո����,��#��Ϊ������־:\n");

    char ch;
    char e;
    scanf("%c",&ch);
    while(ch != '#')
    {
        if(ch >= '0' && ch <= '9')
        {
            printf("%c",ch);
        }
        else if(')' == ch)
        {
            Pop(&s,&e);
            while('(' != e)
            {
                printf("%c",e);
                Pop(&s,&e);
            }
        }
        else if('+' == ch || '-' == ch )
        {
            if( !StackLen(s))
            {
                Push(&s,ch);
            }
            else
            {
                do
                {
                    Pop(&s,&e);
                    if('(' == e)
                    {
                        Push(&s,e);
                    }
                    else
                    {
                        printf("%c",e);
                    }
                } while (StackLen(s) && '(' != e);
                Push(&s,ch);
            }
        }
        else if('*' == ch || '/' == ch || '(' == ch)
        {
            Push(&s,ch);
        }
        else
        {
            printf("\n����!�����ʽ����\n");
            return -1;
        }

        scanf("%c",&ch);
    }
    

    return 0;
}

void initStack(Stack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * (sizeof(ElemType)));
    if(!s->base)
    {
        exit(0);
    }
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

void Push(Stack *s, ElemType e)
{
    if(s->top - s->base >= STACK_INIT_SIZE)
    {
        s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCRIMENT) * sizeof(ElemType));
        if(!s->base)
        {
            exit(0);
        }

        s->top = s->base + s->stackSize;
        s->stackSize = s->stackSize + STACKINCRIMENT;
    }

    *(s->top) = e;
    s->top ++;
}

void Pop(Stack *s, ElemType *e)
{
    if(s->top == s->base)
    {
        return;
    }

    *e = *--(s->top);
}

int StackLen(Stack s)
{
    return (s.top - s.base);
}