#include <stdio.h>

int q[100];
int df=-1,dr=-1;
#define max 10

int isempty(){
    if (df==(dr+1)%max){
        return 1;
    }
    return 0;
}

int isfull(){
    if (df==-1){
        return 1;
    }
    return 0;
}

void enqf(int item){
    if (isfull){
        printf("Overflow! queue full");
        return;
    }
    else if(isempty()){
        df=df=0;
    } else{
        df=df-1;
        q[df]=item;
}}

void enqr(int item){
    if (isempty){
        printf("overflow queue full");
    }
    else if (isempty()){
        df=dr=0;}
    else{
        dr=dr+1;
        q[dr]=item;
    }}


void deqf(){
    if (isempty()){
    printf("underflow queue empty");
} else {}
}

void deqend(){

}
