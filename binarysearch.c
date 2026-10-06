#include <stdio.h>

int tc=0;
int st=0;
int bst=0;
int bss=0; 

int search(int arr[],int low,int high,int item) {
    tc++;
    bst++;
    bss=4*3;
    if (low>high) {
        tc++,bst++;
        return -1;
    }
    int mid=(low+high)/2;
    bss = bss + 4;
    tc++,bst++;
    if (arr[mid]==item){
        tc++,bst++;
        return mid;
    }
    if (arr[mid]>item){
        tc++,bst++;
        return search(arr,low,mid-1,item);
    }
    if (arr[mid]<item){
        tc++,bst++;
        return search(arr,mid+1,high,item);
    }
    return -1;
}

void display(int arr[],int n){
    for (int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[100];
    int n,ch;
    int num = 0;
    int item, result;

    do {
        printf("\n--------menu--------\n");
        printf("1. Enter sorted array elements\n");
        printf("2. Search element (Binary Search)\n");
        printf("3. Display array\n");
        printf("Enter an option(1/2/3): ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &num);
                printf("Enter %d sorted elements:\n", num);
                for (int i=0;i<num;i++){
                    scanf("%d",&arr[i]);
                }
                break;
            case 2:
                if (num>0) {
                    printf("Enter item to search: ");
                    scanf("%d", &item);
                    tc=0;
                    bst=0;
                    bss=0;
                    st=4*4;   
                    tc++;
                    result=search(arr,0,num-1,item);
                    if (result==-1){
                        printf("Item %d not found in the array.\n", item);
                    } else {
                        printf("Item %d found at index %d.\n", item, result);
                    }
                    
                    printf("Total Time Steps (tc): %d\n", tc);
                    printf("Binary Search Steps (bst): %d\n", bst);
                    printf("Binary Search Space (bss): %d bytes\n", bss);
                } else {
                    printf("Array is empty. Please enter elements first.\n");
                }
                break;

            case 3:
                if (num > 0) {
                    printf("Array contents: ");
                    display(arr, num);
                } else {
                    printf("Array is empty.\n");
                }
                break;

            default:
                printf("Enter valid option\n");
                break;
        }

        printf("\nWant to continue (0/1): ");
        scanf("%d", &ch);
    } while (ch == 1);

    return 0;
}