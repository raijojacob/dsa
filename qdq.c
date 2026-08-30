#include <stdio.h>

int q[100],dq[100];
int front=-1,rear=-1;
int max=6;

void enqueue(int val){
    if (rear==(max-1)){
        printf("Queue overflow\n");
    }
    else{
        rear=rear+1;
        q[rear]=val;
        printf("%d ",q[rear]);
        if (front==-1){
            front=0;
        }
    }
}

void dequeue(){
    if (front==-1){
        printf("queue underflow\n");
    }
    else{
        int item=q[front];
        printf("%d",item);
        front=front+1;
        if (front>rear){
            front=-1;
            rear=-1;
        }
    }

}
void display(){
    if (front==-1){
        printf("queue is empty\n");
    }
    else{
        for (int i=front;i<=rear;i++){
            printf("%d ",q[i]);
        }
    }
}

int main(){
    int n,itm;
    char ch;
    do{
        printf("----------menu----------");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n");

        printf("enter a option: ");
        scanf("%d",&n);
        switch(n){
            case 1:
            printf("enter a value:");
            scanf("%d",&itm);
            enqueue(itm);
            break;

            case 2:
            printf("deleting...\n");
            dequeue();
            break;

            case 3:
            printf("queue elements: ");
            display();
            break;

            default:
            printf("enter a valid option\n");
            break;

        }
        printf("want to continue (y/n): \n");
        scanf(" %c",&ch);
    }while (ch=='y');
    return 0;
}