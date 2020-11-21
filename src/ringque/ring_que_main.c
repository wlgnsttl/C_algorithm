#include <stdio.h>
#include "ring_buffer.h"

int main(void){
    IntRing ringque;
    
    if(init_que(&ringque, 60) == -1){
        printf("Error!\n");
    }
    else{
        printf("Success!\n");
    }

    while(1)
    {
        int branch_num = 0;
        int num = 0;
        printf("(1)��ť (2)��ť (3)��ũ (4)��� (0)����\n");
        printf("���� ������ �� : %d / %d\n\n",size_que(&ringque),capacity_que(&ringque));
       
        scanf("%d",&branch_num);
        if(branch_num == 0){
            break;
        }

        switch (branch_num)
        {
        case 1:
            //enque
            printf("���� : ");
            scanf("%d",&num);
            if(enque(&ringque, num) == -1){
                printf("Fail!\n");
            }
            break;
        case 2:
            //deque
            num = deque(&ringque);
            if(num == -1){
                printf("Fail!\n");
            }
            else{
                printf("deque number : %d\n",num);
            }
            break; 
        case 3:
            //peek
            num = peek_que(&ringque);
            if(num == -1){
                printf("Fail!\n");
            }
            else{
                printf("peek number : %d\n",num);
            }
            break;
        case 4:
            //print
            print_que(&ringque);
            break;
        default:
            break;
        }
    }

    return 0;
}