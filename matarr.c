#include <stdio.h>

int mat1[100][100],mat2[100][100];
int eff1[100][100],eff2[100][100],r[100][100],tr[100][100];

void readmat(int row,int col,int mat[100][100]){
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            printf("Matrix[%d][%d]:",i,j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void effmat(int row,int col,int mat[100][100],int eff[100][100]){
    int c=0,k=1;
    eff[0][0]=row;
    eff[0][1]=col;

    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            if (mat[i][j]!=0){
                c++;
                eff[k][0]=i;
                eff[k][1]=j;
                eff[k][2]=mat[i][j];
                k++;
            }
        }
    }
    eff[0][2]=c;
}
void dispmat(int mat[100][100]){
    int trow = mat[0][2] + 1;
    printf("\n");
    for (int t=0;t<trow;t++) {
        printf("[ %d %d %d ]\n",mat[t][0],mat[t][1],mat[t][2]);
    }
    printf("\n");
}  

void addmat(int mat1[100][100],int mat2[100][100],int r[100][100]){
    if (mat1[0][0]!=mat2[0][0]||mat1[0][1]!=mat2[0][1]){
        printf("dimensions do not match \n");
    }
    else{
        r[0][0]=mat1[0][0];
        r[0][1]=mat1[0][1];

        int i=1,j=1,k=1;
        int t1=mat1[0][2];
        int t2=mat2[0][2];

        while (i<=t1&&j<=t2){
            if (mat1[i][0]<mat2[j][0]||mat1[i][0]==mat2[j][0]&&mat1[i][1]<mat2[j][1]){
                r[k][0]=mat1[i][0];
                r[k][1]=mat1[i][1];
                r[k][2]=mat1[i][2];
                i++; k++;
            }
            else if (mat2[j][0]<mat1[i][0]||mat2[j][0]==mat1[i][0]&&mat2[j][1]<mat1[i][1]){
                r[k][0]=mat2[j][0];
                r[k][1]=mat2[j][1];
                r[k][2]=mat2[j][2];
                j++; k++;
            }
            else{
                r[k][0]=mat1[i][0];
                r[k][1]=mat1[i][1];
                r[k][2]=mat1[i][2]+mat2[j][2];
                i++; j++; k++;
            }
        }
        while (i<=t1){
            r[k][0]=mat1[i][0];
            r[k][1]=mat1[i][1];
            r[k][2]=mat1[i][2];
            i++; k++;
        }
        while (j<=t2){
            r[k][0]=mat2[j][0];
            r[k][1]=mat2[j][1];
            r[k][2]=mat2[j][2];
            j++; k++;
        }
        r[0][2]=k-1;

    }
}

void transpose(int mat[100][100],int tr[100][100]){
    int trow=mat[0][2]+1;
    tr[0][0]=mat[0][1];
    tr[0][1]=mat[0][0];
    tr[0][2]=mat[0][2];

    for (int i=1;i<trow;i++){
        tr[i][0]=mat[i][1];
        tr[i][1]=mat[i][0];
        tr[i][2]=mat[i][2];
    }
}

int main(){
    int n,r1,r2,c1,c2;
    char ch;

    do{
        printf("------------menu-----------");
        printf("\n1.enter matrix\n2.display the efficient matrix form\n3.add and display the result\n4.transpose of martix");
        printf("\nchoose an option:");
        scanf("%d",&n);
        switch (n){
            case 1:
            printf("enter no. of rows and columns for matrix 1:");
            scanf("%d %d", &r1, &c1);
            printf("Enter the number of rows and columns for the second matrix:\n");
            scanf("%d %d",&r2,&c2);
            printf("--enter elements for martix1--\n");
            readmat(r1, c1, mat1);
            printf("--enter elements for martix2--\n");
            readmat(r2, c2, mat2);
            break;
            case 2:
            printf("efficient form of matrix 1:");
            effmat(r1,c1,mat1,eff1);
            dispmat(eff1);
            printf("efficient form of matric 2:");
            effmat(r2,c2,mat2,eff2);
            dispmat(eff2);
            break;
            case 3:
            addmat(eff1,eff2,r);
            printf("resultant matrix:");
            dispmat(r);
            break;
            case 4:
            transpose(eff1,tr);
            printf("transpose of matrix 1:");
            dispmat(tr);
            transpose(eff2,tr);
            printf("transpose of matrix 2:");
            dispmat(tr);
            break;
            default:
            printf("invalid option\n");
            break;
    }
    printf("---------------------------\n");
    printf("want to continue(y/n): ");
    scanf(" %c",&ch);
    } while(ch=='y');

    return 0;}