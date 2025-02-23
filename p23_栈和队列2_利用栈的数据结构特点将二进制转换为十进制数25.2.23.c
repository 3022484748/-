/*
��Ŀ:����ջ�����ݽṹ�ص㣬��������ת��Ϊʮ������

����:�����˶�֪�������������Ǽ�������ݵĴ洢��ʽ��������һ��0��1��ɵģ�ÿ����������ת������Ӧ��ʮ��������������:
(XnXn-1...X3X2X1)2= X1*2^0+X*2^1+...+Xn*2^(n-1)
һ����������Ҫת��Ϊ��Ӧ��ʮ�����������Ǵ����λ����ÿһλȥ���Զ�Ӧλ�Ļ���Ҳ����˵�õ�nλȥ����2^(n-1)��Ȼ��ȫ��������
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SIZE 100
typedef int ElemType;

typedef struct Stack
{
    ElemType *base;
    ElemType *top;
    ElemType stackSize;
}Stack;

Stack initStack(Stack *s);
void push(Stack *s, ElemType a);
void pop(Stack *s);

int main()
{
    Stack s;
    initStack(&s);
    printf("��������Ҫת���Ķ�������:\n");

    while(1)
    {
        char ch = getchar();
        if (ch == '\n' && ch == EOF) { // ���»س���ʱ����ջ��������˳�ѭ��
            while ((ch = getchar()) != '\n' && ch != EOF);
            break;
        }
        
        int num = ch - '0'; // ���ַ�ת��Ϊ����
        
        if (num == 0 || num == 1)
        {
            push(&s, num);
            printf("%d��ջ\n", num);
        }
        else
        {
            // �����0��1�������˳�ѭ��
            break;
        }
    }
    
    ElemType output = 0;
    ElemType n = 0;
    while(s.top != s.base)
    {
        output += *(s.top) * pow(2,n);
        pop(&s);
        n++;
    }

    printf("\n\nת����Ľ����:%d\n",output);


    return 0;
}

Stack initStack(Stack *s)
{
    s->base = (ElemType *)malloc(MAX_SIZE * sizeof(ElemType));
    if(!s->base)
    {
        exit(0);
    }

    s->top = s->base;
    s->stackSize = MAX_SIZE;

    return *s;
}

void push(Stack *s, ElemType a)
{
    s->top++;
    if(s->top - s->base == s->stackSize)
    {
        printf("ջ����!\n");
        return;
    }
    *(s->top) = a;
}

void pop(Stack *s)
{
    if(s->top == s->base)
    {
        printf("ջ�ѿտ���Ҳ\n");
        return;
    }
    printf("����%d\n",*(s->top));
    s->top--;
}
