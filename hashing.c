#include <stdio.h>
#define size 10

void initialise(int table[]){
    for (int i=0;i<size;i++){
        table[i]=-1;
    }
}

void insert(int table[],int key) {
    int index=key%size;
    int i=0;
    while(table[(index+i)%size]!=-1 && i<size){
        i++;
    }
    if(i == size){
        printf("hash table is full!");
    }else{
        table[(index+i)%size] = key;
        printf("Inserted %d at slot %d\n",key,(index+i)%size);
    }
}

void display(int table[]){
    printf("\nhash table contents:\n");
    for(int i=0;i<size;i++) {
        if(table[i]==-1) {
            printf("Slot %d: %d\n",i,table[i]);
        }
        else {
            printf("Slot %d: %d\n",i,table[i]);
    }}
}

int main(){
    int hash[size];
    int n,ch,key;
    initialise(hash);
    do{
        printf("\n--------menu--------\n");
        printf("1. Insert Integer\n");
        printf("2. Display Hash Table\n");
        printf("Enter an option(1/2): ");
        scanf("%d", &n);
        switch(n){
            case 1:
                printf("Enter integer to insert: ");
                scanf("%d", &key);
                insert(hash, key);
                break;
            case 2:
            display(hash);
                break;
            default:
                printf("Enter valid option\n");
                break;
        }
        printf("\nWant to continue (0/1): ");
        scanf("%d", &ch);
    }while (ch == 1);
    return 0;
}