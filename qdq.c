#include <stdio.h>

int q[100],dq[100];
int qf=-1,qr=-1;
int dqf=-1,dqr=-1;
int max=10;

//queue
void enqueue(int val){
    if (qr==(max-1)){
        printf("queue overflow\n");
    }else{
        if (qf==-1){
            qf=0;
        }
        qr=qr+1;
        q[qr]=val;
        printf("inserted %d\n",q[qr]);
    }
}

void dequeue(){
    if (qf==-1){
        printf("queue underflow\n");
    }else{
        int item=q[qf];
        printf("deleted %d\n",item);
        if (qf==qr){
            qf=-1;
            qr=-1;
        }else{
            qf=qf+1;
        }
    }
}

void display_q(){
    if (qf==-1){
        printf("queue is empty\n");
    }else{
        printf("queue elements: ");
        for (int i=qf;i<=qr;i++) {
            printf("%d ",q[i]);
        }
        printf("\n");
    }
}

//d queue
void dq_insertRear(int val){
    if (dqr==(max-1)){
        printf("deque overflow at rear\n");
    }else{
        if (dqf==-1) {
            dqf=0;
        }
        dqr=dqr+1;
        dq[dqr]=val;
        printf("inserted %d at rear\n",dq[dqr]);
    }
}

void dq_insertFront(int val){
    if (dqf==0){
        printf("deque overflow at front\n");
    } else if (dqf==-1){
        dqf=0;
        dqr=0;
        dq[dqf]=val;
        printf("inserted %d at front\n",dq[dqf]);
    }else{
        dqf=dqf-1;
        dq[dqf]=val;
        printf("inserted %d at front\n",dq[dqf]);
    }
}

void dq_deleteFront(){
    if (dqf==-1){
        printf("deque underflow\n");
    }else{
        int item=dq[dqf];
        printf("deleted %d from front\n", item);
        if (dqf==dqr){
            dqf=-1;
            dqr=-1;
        }else{
            dqf=dqf+1;
        }
    }
}

void dq_deleteRear(){
    if (dqf==-1){
        printf("deque underflow\n");
    }else{
        int item=dq[dqr];
        printf("deleted %d from rear\n", item);
        if (dqf==dqr){
            dqf=-1;
            dqr=-1;
        }else{
            dqr=dqr-1;
        }
    }
}

void display_dq(){
    if (dqf == -1){
        printf("dque is empty\n");
    }else{
        printf("deque elements: ");
        for (int i=dqf;i<=dqr;i++) {
            printf("%d ",dq[i]);
        }
        printf("\n");
    }
}

//main
int main() {
    int s,op,itm;
    char ch;
    
    do {
        printf("\n-----------menu------------\n");
        printf("1.queue\n");
        printf("2.deque\n");
        printf("enter your choice: ");
        scanf("%d", &s);
        
        if (s==1){
            printf("\n---queue menu ---\n");
            printf("1. enqueue\n2. dequeue\n3. display\n");
            printf("enter option: ");
            scanf("%d", &op);
            
            switch(op){
                case 1:
                    printf("enter a value: ");
                    scanf("%d", &itm);
                    enqueue(itm);
                    break;
                case 2:
                    dequeue();
                    break;
                case 3:
                    display_q();
                    break;
                default:
                    printf("invalid option.\n");
            }
        } 
        else if (s == 2) {
            printf("\n---deque ---\n");
            printf("1. insert at rear\n2. insert at front\n3. delete from front\n4. delete from rear\n5. display\n");
            printf("enter option: ");
            scanf("%d", &op);
            
            switch(op) {
                case 1:
                    printf("enter a value: ");
                    scanf("%d", &itm);
                    dq_insertRear(itm);
                    break;
                case 2:
                    printf("enter a value: ");
                    scanf("%d", &itm);
                    dq_insertFront(itm);
                    break;
                case 3:
                    dq_deleteFront();
                    break;
                case 4:
                    dq_deleteRear();
                    break;
                case 5:
                    display_dq();
                    break;
                default:
                    printf("invalid option.\n");
            }
        } 
        else {
            printf("invalid option select 1 0r 2.\n");
        }
        printf("----------------------------");
        printf("\ncontinue (y/n)? ");
        scanf(" %c", &ch);
        
    } while (ch=='y');
    
    return 0;
}