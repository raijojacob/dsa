#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct node{
        char data[100];
        struct node * next;
        struct node * prev;
};

struct node *head = NULL;
struct node *tail= NULL;
struct node *cur=NULL;

void insert(){
        char item[100];
        struct node *nnode;
        printf("Enter url: ");
        scanf("%s",item);
        nnode=(struct node *)malloc(sizeof(struct node));
        strcpy(nnode->data, item);
        nnode->next=NULL;
        nnode->prev=NULL;
        if (head==NULL) {
                head=nnode;
                tail=nnode;
                cur=nnode;
        }else{
                tail->next=nnode;
                nnode->prev=tail;
                tail=nnode;
                cur=nnode;
        }
}

void dispcur(){
        if (cur==NULL) {
                printf("No url\n");
        }else{
                printf("Going back..\n");
                printf("Url: %s\n",cur->data);
        }
}

void back(){
        if (cur==NULL) {
                printf("No urls....\n");
        }else if (cur->prev==NULL){
                printf("No urls behind.\n");
        }else{
                cur=cur->prev;
                printf("moved back to url: %s\n",cur->data);
        }
}

void forward(){
        if (cur!=NULL && cur->next!=NULL) {
                cur=cur->next;
                printf("moved forward to wrl: %s\n",cur->data);
        }else{
                printf("no url infront...\n");
        }
}

void clear(){
        struct node *temp;
        if (head==NULL) {
                printf("No urls to clear...\n");
        }else{
                while (head!=NULL) {
                        temp=head;
                        head=head->next;
                        free(temp);
                }
                tail=NULL;
                cur=NULL;
                printf("all history has been cleared.\n");
        }
}

void display(){
        struct node *temp;
        if(head==NULL){
                printf("no urls.....");
        }else{
                temp = head;
                while(temp->next != NULL){
                        printf("%s \n", temp->data);
                        temp = temp->next;
                }
                printf("%s\n",temp->data);
        }
}

int main(){
        char ch;
        do{
        int n;
        printf("-------menu--------");
        printf("\n 1.Enter an url. \n 2. View current url\n 3. Go back \n 4.Go forward \n 5.View all \n 6. Clear history");
        printf("\nEnter your choice:");
        scanf("%d", &n);
        switch(n){
                case 1:
                        insert();
                        break;
                case 2:
                        dispcur();
                        break;
                case 3:
                        back();
                        break;
                case 4:
                        forward();
                        break;
                case 5:
                        display();
                        break;
                case 6:
                        clear();
                        break;
                default:
                        printf("enter a vaild option");
                        break;

        }
        printf("-------------------\n");
        while (getchar() != '\n');
        printf("continue (y/n)?: ");
        ch=getchar();
        }while (ch=='y');
}