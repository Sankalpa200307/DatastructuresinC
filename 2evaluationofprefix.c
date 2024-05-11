#include<stdio.h>
#include<math.h>

struct stack{
    int top;
    int a[10];
}s;

void push(int ele){
        s.a[++s.top]=ele;
}

int pop(){
    return s.a[s.top--];
}

int compute(int op1,char sym,int op2){
    switch(sym){
        case '$':
            return pow(op1,op2);
        case '*':
            return op1*op2;
        case '/':
            return op1/op2;
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
    }
}

int main(){
    s.top=-1;
    char prefix[10],sym;
    int i,op1,op2,res=0;

    printf("Enter the prefix expression\n");
    scanf("%s",prefix);

    for(i=0;prefix[i]!='\0';i++);

    for(--i;i>=0;i--){
        sym=prefix[i];
        if((sym>='0')&&(sym<='9')){
            push(sym-'0');
        }
        else{
            op1=pop();
            op2=pop();
            res=compute(op1,sym,op2);
            //printf("%d ",res);
            push(res);
        }
    }

    printf("The answer is %d\n",pop());
    return 0;
    
}