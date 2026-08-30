#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max 100
char stk[100];
char post[max];
int top=-1;

void push(char item){
    if (top==max-1){
        printf("overflow stack full");
    }
    else{
        top=top+1;
        stk[top]=item;
    }
}

char pop(){
    if (top==-1){
        return '\0';
    }
    else{
        char item=stk[top];
        top=top-1;
        return item;
    }
}

int precedence(char n){
    switch (n){
        case '^':
        return 3;
        case '*':
        case '/':
        return 2;
        case '-':
        case '+':
        return 1;
        default:
        return 0;
    }
}

void conversion(char inf[100],char post[100]){
    push('(');
    int j=0;
    for (int i=0;i<strlen(inf);i++){
        switch (inf[i]){
            case '(':
            push(inf[i]);
            break;
            case ')':
            while (top!=-1 && stk[top]!='('){
                post[j++]=pop();
            }
            pop();
            break;
            case '+':case '-':case '/':case '*':case '^':
            while (top!=-1 && precedence(inf[i])<=precedence(stk[top])){
                post[j++]=pop();

            }
            push(inf[i]);
            break;
            default:
            post[j++] = inf[i];
        }
    }
    while (top!=-1){
        char item= pop();
        if (item!='(') post[j++]=item;
    }
    post[j] = '\0';
}
int evaluate(char post[]){
    int eval[100];
    int etop=-1;
    int var[26]={0};
    int val[26]={0};
    int i=0;
    while (post[i]!='\0'){
        if (post[i]>='A'&&post[i]<='Z'){
            int index=post[i]-'A';
            if (val[index]==0){
                printf("Enter a value for %c :", post[i]);
                scanf("%d",&var[index]);
                val[index]=1;
            }
            eval[++etop]=var[index];
        }
        else if (post[i]>='0'&&post[i]<='9'){
            eval[++etop]=post[i]-'0';
        } 
        else {
            int A=eval[etop--]; 
            int B=eval[etop--]; 
            int result;
            switch (post[i]) {
                case '+': result=B+A; 
                break;
                case '-': result=B-A;
                break;
                case '*': result=B*A; 
                break;
                case '/': result=B/A; 
                break;
                case '%': result=B%A;
                break;
                case '^': result=(int)pow(B,A); 
                break;
            }
            eval[++etop]=result;
        }
        i++; 
    }
    return eval[etop];
}

int main(){
    char infix[100];
    char postfix[100];
    printf("enter infix expression:");
    scanf("%s",infix);
    conversion(infix,postfix);
    printf("postfix expression: %s\n",postfix);
    int result = evaluate(postfix);
    printf("evaluated Result: %d\n",result);
    return 0;
}