/*

һ����ʽ:
a + b * c
5 - (6 + 7) * 8 + 9 / 4

�沨�����ʽ:
a b c * -
5 6 7 + 8 * - 9 4 / +

*/


#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10
#define MAXBUFFER       10

typedef double ElemType;
typedef struct Stack
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}Stack;

void InitStack(Stack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if( !s->base )
    {
        exit(0);
    }

    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

void Push(Stack *s, ElemType e)
{
    //ջ����׷�ӿռ䣬���ͱ��붮!
    if( s->top - s->base >= s->stackSize )
    {
        s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
        if( !s->base )
        {
            exit(0);
        }

        s->top = s->base + s->stackSize;
        s->stackSize = s->stackSize + STACKINCREMENT;
    }

    *(s->top) = e;  //�������
    s->top++;
}

void Pop(Stack *s, ElemType *e)
{
    if( s->top == s->base)
    {
        return;
    }

    *e = *--(s->top);   //��ջ��Ԫ�ص������޸�ջ��ָ��
}

int StackLen(Stack s)
{
    return (s.top - s.base);
}

int main()
{
    Stack s;
    InitStack(&s);

    printf("�밴�沨�����ʽ�������������,�����������֮���ÿո����,��#��Ϊ������־:\n");
    
    char ch;
    double d,e;
    char str[MAXBUFFER];//���建����
    int i = 0;

    scanf("%c",&ch);
    while(ch != '#')
    {
        while(isdigit(ch) || ch == '.') //�ж�����ַ���ACILL���Ƿ���48-57(����Ӧ0-9)
        {
            str[i++] = ch;
            str[i] = '\0';
            if(i >=  10)
            {
                printf("����:����ĵ������ݹ���!\n");
                return -1;
            }

            scanf("%c",&ch); 

            if(ch == ' ')
            {
                d = atof(str);//���ַ���ת��Ϊ������
                Push(&s,d);
                i = 0;
                break;
            }
        }

        switch(ch)
        {
            case '+':   
            {
                Pop(&s,&e);
                Pop(&s,&d);
                Push(&s,d+e);
                break;
            }
            case '-':
            {
                Pop(&s,&e);
                Pop(&s,&d);
                Push(&s,d-e);
                break;
            }
            case '*':
            {
                Pop(&s,&e);
                Pop(&s,&d);
                Push(&s,d*e);
                break;
            }
            case '/':
            {
                Pop(&s,&e);
                Pop(&s,&d);
                if(e != 0)
                {
                    Push(&s,d/e);
                }
                else
                {
                    printf("\n����:����Ϊ0!\n");
                    return -1;
                }
                break;
            }

        }
        scanf("%c",&ch);
    }
    
    Pop(&s,&d);
    printf("���յļ�����Ϊ:%lf\n",d);

    return 0;
}