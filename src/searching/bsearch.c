#include <stdio.h>
#include <stdlib.h>

int compare (void *first, void *second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else 
        return 0;
}


int main(void){
    int arr[] = {1,2,3,4,5,5,6,7,8,8,9}; //배열의 길이 11

    int key = 0;
    int* ptr = NULL;

    printf("key값 : "); scanf("%d",&key);
    ptr = bsearch(&key, arr, 11, sizeof(int), 
    (int(*)(const void* , const void* )) compare
    );

    if(ptr == NULL)
    {
        puts("검색에 실패했습니다.");
    }
    else
    {
        printf("%d\n",*ptr);
    }

    return 0;
}