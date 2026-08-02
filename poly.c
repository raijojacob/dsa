#include <stdio.h>

struct poly {
    int coeff;
    int exp;
} p1[20],p2[20],r[20];

int t1=0,t2=0,t=0;

void read() {
    printf("enter no. of terms in 1st polynomial: ");
    scanf("%d",&t1);
    printf("enter no. of terms in 2nd polynomial: ");
    scanf("%d",&t2);

    printf("\nenter the terms in 1st polynomial\n");
    for (int i=0;i<t1;i++){
        printf("coeff: ");
        scanf("%d",&p1[i].coeff);
        printf("exp: ");
        scanf("%d",&p1[i].exp);
    }
    printf("\nenter the terms in 2nd polynomial\n");
    for (int j=0;j<t2;j++){
        printf("coeff: ");
        scanf("%d",&p2[j].coeff);
        printf("exp: ");
        scanf("%d",&p2[j].exp);
    }
}

void display(struct poly p[], int trm){
    for (int i=0;i<trm;i++) {
        printf("%dx^%d",p[i].coeff,p[i].exp);
        if (i<trm-1){
            printf(" + ");
        }
    }
    printf("\n");
}

int add(struct poly p1[], struct poly p2[], struct poly r[], int t1, int t2) {
    int i=0,j=0,k=0;
    
    while (i<t1&&j<t2){
        if (p1[i].exp==p2[j].exp) {
            r[k].coeff=p1[i].coeff+p2[j].coeff;
            r[k].exp=p1[i].exp;
            i++;
            j++;
            k++;
        } 
        else if (p1[i].exp>p2[j].exp){
            r[k]=p1[i];
            i++; 
            k++;
        } 
        else{
            r[k]=p2[j];
            j++; 
            k++;
        }
    }

    while (i<t1){
        r[k]=p1[i];
        i++;
        k++;
    }

    while (j<t2){
        r[k]=p2[j];
        j++;
        k++;
    }

    return k; 
}

int main() {
    int n;
    char ch='y';

    while (ch=='y' || ch=='Y'){
        printf("\n----------menu ----------\n");
        printf(" 1. read");
        printf(" 2. display");
        printf(" 3. add\n");
        printf("enter option (1/2/3): ");
        scanf("%d", &n);

        if (n==1) {
            read(); } 
        else if (n==2){
            printf("\n1st polynomial: ");
            display(p1,t1);
            printf("2nd polynomial: ");
            display(p2,t2);
        } else if (n==3) {
            t = add(p1,p2,r,t1,t2);
            printf("\npolynomials are added !!\n");
            printf("Result: ");
            display(r,t);
        } else {
            printf("enter a valid option!\n");
        }

        printf("\nwant to continue? [y/n]: ");
        scanf(" %c", &ch); 
    }
    return 0;
}