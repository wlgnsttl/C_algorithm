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
    int arr[] = {1,2,3,4,5,5,6,7,8,8,9}; //�迭�� ���� 11

    int key = 0;
    int* ptr = NULL;

    printf("key�� : "); scanf("%d",&key);
    ptr = bsearch(&key, arr, 11, sizeof(int), 
    (int(*)(const void* , const void* )) compare
    );

    if(ptr == NULL)
    {
        puts("�˻��� �����߽��ϴ�.");
    }
    else
    {
        printf("%d\n",*ptr);
    }

    return 0;
}