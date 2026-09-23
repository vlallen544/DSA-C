#include <stdio.h>

int main(){

    int arr[6];
    int hash[10];
    printf("Filling the array....\n");
    for(int i = 0; i<6; i++){
        scanf("%d", &arr[i]);
    }
    int index;
    for(int i = 0; i<6; i++){
        index = arr[i]%10;
        if(hash[index] == 1){
            printf("%d is a duplicate found \n",  arr[i]);
            
        }
        else{
            hash[index] = 1;
        }
    }
}