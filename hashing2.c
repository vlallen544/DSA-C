#include <stdio.h>

bool containsDuplicate(int* nums, int numsSize) {

    int size = 10;
    int hash[1000000] = {0};
    int index;

    for(int i = 0; i<numsSize; i++){
        index = index % 1000000;
        if(hash[index] > 0){
            hash[index] += 1;
        }
        else{
            hash[index] = 1;
        }
    }

    for(int i = 0; i<numsSize; i++){
        if(hash[i] > 0){
            return 1;
        }
    }

}

int main(){
    int arr[6];
    int hash[10] = {0};
    printf("Filling the array....\n");
    for(int i = 0; i<6; i++){
        scanf("%d", &arr[i]);
    }
    int index;
    for(int i = 0; i<6; i++){
        index = arr[i]%10;
        if(hash[index] == 1){
            hash[index] += 1;
        }
        else{
            hash[index] = 1;
        }
    }

    for(int i = 0; i<10; i++){
        if(hash[i] > 0){
            printf("%d is repeated %d times\n", i, hash[i]);
        }
    }

    if(hash[7%10] > 0){
        printf("7 exists\n");
    }
    else{
        printf("7 does not exist\n");
    }

    return 0;
}