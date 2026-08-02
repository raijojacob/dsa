#include <stdio.h>

struct poly{
    int coeff;
    int exp;
} p1[20],p2[20],r[20];
int t1=0,t2=0,t=0;

void read(struct poly p[],int trm){

    for (int i=0;i<trm;i++){
        printf("--term %d--\n",i+1);
        printf("coeff:");
        scanf("%d",&p[i].coeff);
        printf("exp:");
        scanf("%d",&p[i].exp);
    }
}

void sort(struct poly p[],int trm){

    for (int i=0;i<trm;i++){
        for(int j=0;j<trm-i-1;j++){
            if (p[j].exp<p[j+1].exp){
                struct poly temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

}
void display(struct poly p[],int trm){
    for (int i=0; i<trm;i++){
      printf("%dx^%d",p[i].coeff,p[i].exp);
        if (i<trm-1){
            printf(" + ");
        }
    }
    printf("\n");
}  

int add(struct poly p1[],struct poly p2[],struct poly r[],int t1,int t2){
    int i=0,j=0,k=0;

    while(i<t1&&j<t2){
        if (p1[i].exp==p2[j].exp){
            r[k].coeff=p1[i].coeff+p2[j].coeff;
            r[k].exp=p1[i].exp;
            i++;j++;k++;
        }
        else if (p1[i].exp>p2[j].exp){
            r[k]=p1[i];
            i++;k++;
        }
        else{
            r[k]=p2[j];
            j++;k++;
        }}

        while(i<t1){
            r[k]=p1[i];
            i++;k++;
        }
        while (j<t2){
        r[k]=p2[j];
        j++;
        k++;
    }

    return k;
}
int main(){
    int n;
    char ch;
    do{
        printf("------------menu-----------");
        printf("\n1.enter polynomial\n2.display the entered polynomials\n3.add and display the result\n");
        printf("choose an option:");
        scanf("%d",&n);
        switch (n){
            case 1: 
            printf("enter no. of terms in 1st polynomial:\n");
            scanf("%d",&t1);
            printf("enter no. of terms for 2nd polynomial:\n");
            scanf("%d",&t2);
            printf("1st polynomial:\n");
            read(p1,t1);
            sort(p1,t1);
            printf("2nd polynomial:\n");
            read(p2,t2);
            sort(p2,t2);
            printf("polynomial successfully added\n");
            break;
            
            case 2:
            printf("1st polynomial:\n");
            display(p1,t1);
            printf("2nd polynomial:\n");
            display(p2,t2);
            break;

            case 3:
            printf("result:\n");
            int t=add(p1,p2,r,t1,t2);
            display(r,t);
            break;

            default:
            printf("invaild option\n");
            break;
        }
        printf("---------------------------\n");
        printf("want to continue(y/n): ");
        scanf(" %c",&ch);
    } while(ch=='y');
    return 0;
}