#include <stdio.h>
#define max 15

struct stack
{
    char a[max];
    int top;
};

struct stack s;

void push(char ele)
{
    s.a[++s.top] = ele;
}

void pop()
{
    s.top--;
}

int main()
{
    s.top = -1;
    char exp[max], sym;
    int flag = 0;
    printf("Enter expression\t:");
    scanf("%s", exp);

    for (int i = 0; exp[i] != '\0' && flag != 1; i++)
    {
        sym = exp[i];
        if (sym == '(' || sym=='{' || sym=='[')
            push(sym);
        
        else if(sym==')' || sym=='}' ||sym==']'){
            if(s.top==-1)
                flag=1;
            if(sym==')'&&s.a[s.top]=='(' || sym==']'&&s.a[s.top]=='[' || sym=='}'&&s.a[s.top]=='{'){
                pop();
    
            }
        }
        else
        {
            if (s.top == -1)
                flag = 1;
            else
                pop();
        }
    }
    if (flag != 1 && s.top == -1)
    {
        printf("Valid expression\n");
    }
    else
    {
        printf("Invalid expression\n");
    }

    return 0;
}
