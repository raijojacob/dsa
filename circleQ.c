#include<stdio.h>
#include<stdlib.h>

#define max 5
int queue[max],r=-1,f=-1;

void enqueue(){
	int item;
	if(f==((r+1)%max)){
		printf("Queue is Full"); }
    else{
		printf("enter item:");
		scanf("%d", &item);
		if(r==-1&&f==-1){
			r=0;
			f=0;
		}
		else{
			r=(r+1)%max;	
		}
		queue[r]=item;
	}

}

void dequeue(){
	int item;
	if(r==-1 && f==-1){
		printf("UNderflow,queue is empty");
	}
	else{
		if(r==f){
			item = queue[f];
			printf("item deleted is %d", item);
			f=-1;r=-1;
		}
        else{
			item = queue[f];
			printf("item deleted is %d", item);
			f=(f+1)%max;
		}
	}
}

void display(){
	if(f==-1 && r==-1){
     		printf("underflow queue is empty"); }
   	else if (f<=r){
 		for(int i=f;i<=r;i++){
    			printf("%d\t",queue[i]);
		}
	}
	else{
        for (int i = f; i < max; i++)
            		printf("%d\t", queue[i]);
                for (int i = 0; i <= r; i++){
    			printf("%d\t", queue[i]);}
            }
}

int main(){
    char ch='y';
	do{
	int n;
    printf("-------menu--------");
	printf("\n1. enqueue\n2. dequeue\n3. display\n");
	printf("enter your choice:");
	scanf("%d", &n);
	switch(n){
		case 1: 
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;
		default:
			printf("Enter a valid choice");
	
	}
    printf("\ncontinue(y/n)?:");
    scanf(" %c", &ch);
    printf("--------------------");
    }while (ch=='y');
return 0;
}