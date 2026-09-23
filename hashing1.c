#include <stdio.h>
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