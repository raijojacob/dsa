#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node* next;
};
struct node *h1=NULL,*h2=NULL,*h3=NULL,*temp,*t1, *t2,*nnode;

void insert(struct node **head,int coeff,int exp){
    struct node* nnode=(struct node*)malloc(sizeof(struct node));
    nnode->coeff=coeff;
    nnode->exp=exp;
    nnode->next=NULL;
    if (*head==NULL){
        *head=nnode;
    }
    else{
        struct node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nnode;
        temp=nnode;
    }
    }

void display(struct node* head){
    temp=head;
    while(temp!=NULL){
        printf("%dx^%d",temp->coeff,temp->exp);
        if (temp->next!=NULL){
        printf(" + ");}
        temp=temp->next;
    }
    printf("\n");
    
}

void add(struct node *h1, struct node *h2, struct node **h3){
    t1=h1;
    t2=h2;
     while(t1!=NULL && t2!=NULL){
        if(t1->exp==t2->exp){
            insert(h3,t1->coeff+t2->coeff,t1->exp);
            t1=t1->next;
            t2=t2->next;
        }
        else if(t1->exp > t2->exp){
            insert(h3,t1->coeff,t1->exp);
            t1=t1->next;
        }
        else{
            insert(h3,t2->coeff,t2->exp);
            t2=t2->next;
        }}

    while(t1!=NULL){
        insert(h3,t1->coeff,t1->exp);
        t1=t1->next;
    }
    while(t2!=NULL){
        insert(h3,t2->coeff,t2->exp);
        t2=t2->next;
    }}

int main(){
    int coeff,exp,n;
    char ch;
    do{
        printf("1.enter polynomials.\n");
        printf("2.display the polynomial\n");
        printf("3.add polynomial\n");
        printf("enter your choice:\n");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("enter no. of terms for 1st polynomial: ");
                int t1;
                scanf("%d",&t1);
                for(int i=0;i<t1;i++){
                    printf("enter %d coefficient and exponet: ",i+1);
                    scanf("%d %d",&coeff,&exp);
                    insert(&h1,coeff,exp);
                }
                printf("enter no. of terms for 2nd polynomial: ");
                int t2;
                scanf("%d",&t2);
                for(int i=0;i<t2;i++){
                    printf("enter %d coefficient and exponent : ",i+1);
                    scanf("%d %d",&coeff,&exp);
                    insert(&h2,coeff,exp);
                }
                break;
            case 2:
                printf("polynomial 1: ");
                display(h1);
                printf("\npolynomial 2: ");
                display(h2);
                break;
            case 3:
                add(h1,h2,&h3);
                printf("reuslt: ");
                display(h3);
                break;
            default:
                printf("enter valid choice\n");
            }
            printf("want to continue?(y/n):");
            scanf(" %c",&ch);
        } while (ch=='y'||ch=='Y');
    return 0;  

}