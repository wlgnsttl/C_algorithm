#include <stdio.h>

int factorial(int x){
    if(x == 1){
        return 1;
    }
    return  x * factorial(x-1);
}
int get_GCD(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return get_GCD(b, a%b);
    }
}
int get_GCD_array(const int arr[], int len){
    if(len == 1){
        return arr[0];
    }
    else if(len == 2){
        return get_GCD(arr[0],arr[1]);
    }
    else{
        return get_GCD(arr[0], get_GCD_array(&arr[1], len-1));
    }
}
int main(void){
    int num = get_GCD(5,10);
    printf("%d\n",num);
    return 0;
}