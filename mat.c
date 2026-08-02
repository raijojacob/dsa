#include <stdio.h>

int mat1[100][100], mat2[100][100];
int c, k;
int dex1[100][100], dex2[100][100], r[100][100], tr[100][100];
int b[100][100];

void dispmat(int b[100][100]);

void inpmat(int rows, int cols, int a[100][100]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Matrix[%d][%d]:", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void effmat(int rows, int cols, int a[100][100], int b[100][100]) {
    int k = 1, c = 0;
    b[0][0] = rows;
    b[0][1] = cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (a[i][j] != 0) {
                c++;
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
    }
    b[0][2] = c;
}

int addmat(int b1[100][100], int b2[100][100], int r[100][100]) {
    if (b1[0][0] != b2[0][0] || b1[0][1] != b2[0][1]) {
        printf("Dimensions do not match\n");
        return 0;
    } else {
        r[0][0] = b1[0][0];
        r[0][1] = b1[0][1];
        int i = 1, j = 1, k = 1;

        int t1 = b1[0][2];
        int t2 = b2[0][2];

        while (i <= t1 && j <= t2) {
            if (b1[i][0] < b2[j][0] || (b1[i][0] == b2[j][0] && b1[i][1] < b2[j][1])) {
                r[k][0] = b1[i][0];
                r[k][1] = b1[i][1];
                r[k][2] = b1[i][2];
                i++; k++;
            } else if (b2[j][0] < b1[i][0] || (b2[j][0] == b1[i][0] && b2[j][1] < b1[i][1])) {
                r[k][0] = b2[j][0];
                r[k][1] = b2[j][1];
                r[k][2] = b2[j][2];
                j++; k++;
            } else {
                r[k][0] = b1[i][0];
                r[k][1] = b1[i][1];
                r[k][2] = b1[i][2] + b2[j][2];
                i++; j++; k++;
            }
        }
        while (i <= t1) {
            r[k][0] = b1[i][0];
            r[k][1] = b1[i][1];
            r[k][2] = b1[i][2];
            i++; k++;
        }
        while (j <= t2) {
            r[k][0] = b2[j][0];
            r[k][1] = b2[j][1];
            r[k][2] = b2[j][2];
            j++; k++;
        }
        r[0][2] = k - 1;
        return k - 1;
    }
}

void transpose(int b[100][100], int r[100][100]) {
    int trow = b[0][2] + 1;
    r[0][0] = b[0][1];
    r[0][1] = b[0][0];
    r[0][2] = b[0][2];

    for (int i = 1; i < trow; i++) {
        r[i][0] = b[i][1];
        r[i][1] = b[i][0];
        r[i][2] = b[i][2];
    }
}
void dispmat(int b[100][100]) {
    int trow = b[0][2] + 1;
    printf("\n");
    for (int t = 0; t < trow; t++) {
        printf("[ %d %d %d ]\n", b[t][0], b[t][1], b[t][2]);
    }
    printf("\n");
}

int main() {
    int row1, col1, row2, col2;
    
    
    char ch = 'y';
    while(ch=='y'){
    printf("1. Enter matrix\n");
    printf("2. Display efficient matrix form\n");
    printf("3. Add two sparse matrices\n");
    printf("4. Transpose a sparse matrix\n");
    printf("Enter your choice:\n");
    scanf("%d", &c);
    switch (c) {
        case 1:

            printf("Enter the number of rows and columns for the first matrix:\n");
            scanf("%d %d", &row1, &col1);
            printf("Enter the number of rows and columns for the second matrix:\n");
            scanf("%d %d", &row2, &col2);
            inpmat(row1, col1, mat1);
            inpmat(row2, col2, mat2);
            break;
        case 2:
            printf("Efficient matrix form of the first matrix:\n");
            effmat(row1, col1, mat1, dex1);
            dispmat(dex1);
            printf("Efficient matrix form of the second matrix:\n");
            effmat(row2, col2, mat2, dex2);
            dispmat(dex2);
            break;
        case 3:
            printf("Addition of two sparse matrices:\n");
            int t = addmat(dex1, dex2, r);
            dispmat(r);
            break;
        case 4:
            printf("Transpose of the first sparse matrix:\n");
            transpose(dex1, tr);
            dispmat(tr);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }
    printf("Do you want to continue? (y/n): ");
    scanf(" %c", &ch);
}
    return 0;
}