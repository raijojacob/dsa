#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
};
struct node *root=NULL;

void insert(int item){
    struct node *nnode=(struct node*)malloc(sizeof(struct node));
    nnode->data=item;
    nnode->lchild=NULL;
    nnode->rchild=NULL;

    if (root==NULL){
        root=nnode;
    } else {
        struct node *ptr=NULL, *parent=NULL;
        while(ptr!=NULL){
            parent=ptr;
            if(item<ptr->data){
                ptr=ptr->lchild;
            } else if (item>ptr->data){
                ptr=ptr->rchild;
            } else{
                printf("item already exists in the tree");
                free(nnode);
                return;
            }
        }
    if (item<parent->data){
        parent->lchild=nnode;
    }else{
        parent->rchild=nnode;
    }
}    
}

void search(int item){
    if (root==NULL){
        printf("underflow,tree empty");
    } else {
        struct node *ptr=root;
        int f=0;
        while (ptr!=NULL && f==0){
            if (ptr->data>item){
                ptr=ptr->lchild;
            } else if(ptr->data < item){
                ptr=ptr->rchild;
            } else{
                f=1;
            }
        }
        if (f==1){
            printf("Item found in the tree.\n");
        } else{
            printf("item not found in the tree.\n");
        }
    }
}

int delnode(int item){
    if (root==NULL){
        printf("tree is empty");
        return 0;
    } else {
        struct node *ptr=root,*parent=NULL;
        int f=0;
        while (ptr!=NULL&&f==0){
            if(ptr->data>item){
                parent=ptr;
                ptr=ptr->lchild;
            } else if (ptr->data<item){
            parent=ptr;
            ptr=ptr->rchild;
            } else{
                f=1;
            }
        }
    }
}