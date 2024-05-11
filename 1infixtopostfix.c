#include<stdio.h>

struct stack{
    int top;
    char a[10];
}s;

void push(int ele){
        s.a[++s.top]=ele;
}

char pop(){
        return s.a[s.top--];
}

int prcd(char op1,char op2){
        switch(op1){
                case '$':
                    if((op2=='+')||(op2=='-')||(op2=='/')||(op2=='*'))
                        return 1;
                case '/':
                case '*':
                    if((op2=='+')||(op2=='-')||(op2=='/')||(op2=='*'))
                        return 1;
                case '+':
                case '-':
                    if((op2=='+')||(op2=='-'))
                        return 1;
        }
        return 0;
}

int main(){
    s.top=-1;
        char infix[10],postfix[10],sym,p;
        int k=0;

        printf("Enter the infix expression:");
        scanf("%s",infix);

        for(int i=0;infix[i]!='\0';i++){
                sym=infix[i];
                if(((sym>='A')&&(sym<='Z'))||((sym>='a')&&(sym<='z'))||((sym>='0')&&(sym<='9'))){
                    postfix[k++]=sym;
                }
                else{
                    while((s.top!=-1)&&prcd(s.a[s.top],sym)){
                            p=pop();
                            postfix[k++]=p;

                    }
                    push(sym);
                }
        }

        while(s.top!=-1){
            postfix[k++]=pop();
        }

        postfix[k]='\0';

        printf("Postfix %s\n",postfix);
        

        return 0;
}