#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int orderno; 
    char dish[100];
    struct node *next;
};

struct node *nnode,*f=NULL,*r=NULL,*temp;

void enq(int item,char dish[]){
    nnode=(struct node *)malloc(sizeof(struct node));
    nnode->orderno=item;
    strcpy(nnode->dish, dish);
    nnode->next=NULL;
    if(f==NULL){
        f=r=nnode;
    }
    else{
        r->next=nnode;
        r=nnode;
}}

void deq(){
    if(f==NULL){
        printf("queue empty no order left"); }
    else{
        temp=f;
        printf("\nCompleted order: %d\n",temp->orderno);
        printf("Dish name: %s\n", temp->dish);
        if(f==r){
            f=r=NULL;   }
        else{
            f=f->next;   }
        free(temp);
      
    }}

void peek() {
    if (f == NULL) {
        printf("\nNo orders left");
    } else {
        printf("\nCurrent Order no.: %d\n", f->orderno);
        printf("Dish name: %s\n", f->dish);
    }
}

void display(){
    temp=f;
    if(f==NULL){
        printf("\nQueue empthy no order left");   }
    else{
        while(temp!=NULL){
            printf("Order no.:%d\n",temp->orderno);
            printf("Dish name: %s\n", temp->dish);
            temp=temp->next;}
    }
}

int main(){
    int n, value;
    char ch;
    char dish[100];
    do{
        printf("-----------Menu-----------\n");
        printf("1. Add order \n2. Remove completed order\n3. View currect order \n4. View all orders \n");
        printf("Enter your choice :");
        scanf("%d",&n);
        switch(n)
        {
            case 1 : printf("\nEnter order no.:");
                     scanf("%d",&value);
                     printf("Enter dish name:");
                     scanf("%s", dish);
                     enq(value, dish);
                     break;
            case 2 : deq();
                     break;
            case 3 : peek();
                     break;
            case 4 : display();
                     break;
            default: printf("\nInvalid option!!");
        }
        printf("-------------------------------\n");
        printf("\nwant to continue (y/n) :");
        scanf(" %c",&ch);
    }while(ch=='y' || ch=='Y');
    return 0;
}