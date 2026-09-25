#include <stdio.h>
int main(){

    int target = 9;
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

    int index1 = 0;
    
    for(int i = 0; i<6; i++){
        int needed = target - arr[i];
        index1 = needed % 10;
        if(hash[index1]){
            printf("yes index %d + %d is %d(target)\n", arr[i], needed, target);
            break;
        }
    }
    
    return 0;
}