# include <stdio.h>
# include <stdlib.h>

void traversal(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("The element number is %d and value is %d\n", i, arr[i]);
    }
}

int insertion (int pos, int size, int *arr, int value){

    for(int i = size-1; i>=pos; i--){
        arr[i+1] = arr[i];
    }

    arr[pos] = value;
    printf("----New array size is %d----\n", size + 1);
    return size + 1;

}

int deletion (int pos, int *arr, int size){

    for(int i = pos; i<size; i++){
        arr[i] = arr[i+1];
    }

    printf("----New array size is %d----\n", size - 1);
    return size - 1;

}

void lsearch(int value, int size, int *arr) {
    for(int i = 0; i<size; i++){
        if(arr[i] == value){
            printf("The value %d found at %d index\n", arr[i], i);
        }
    }
}

int binarysearch(int value, int size, int *arr) {
    
    int low = 0;
    int high = size - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == value){
            printf("The value %d\n", value);
            return mid;
        }
        else if(arr[mid] < value) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    printf("The value is not found");
    return -1;

}

int removeElement(int* nums, int numsSize, int val) {

    int j = 0;

    for(int i = 0; i < numsSize; i++){
        if(nums[i] != val){
            nums[j] = nums[i];
            j++;
        }
    }

    return j;

}

int main() {
    int total_size = 100;
    int size = 5;
    int *arr = malloc(total_size*sizeof(int));

    arr[0] = 0;
    arr[1] = 2;
    arr[2] = 2;
    arr[3] = 2;
    arr[4] = 2;

    printf("The traversal of array : \n");
    traversal(arr, size);

    size = insertion(4, size, arr, 5);
    printf("The traversal of array : \n");
    traversal(arr, size);

    size = deletion(4, arr, size);
    printf("The traversal of array : \n");
    traversal(arr, size);

    printf("----Linear search----\n");
    printf("Checking if 4 value exist in the above array\n");
    lsearch(4, size, arr);

    printf("----Binary search----\n");
    printf("Checking if 4 value exist in the above array\n");
    binarysearch(67, size, arr);

    size = removeElement(arr, size, 2);
    printf("\nThe new size is %d", size);
    
    free(arr);
    return 0;

}