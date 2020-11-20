#include <stdio.h>
#include <stdlib.h>
#include "ring_buffer.h"

int init_que(IntRing* que, int max){
    que -> max = 0;
    que -> num = 0;
    que -> front = 0;
    que -> rear = 0;
    
    que -> queue_ptr = calloc(max, sizeof(int));
    if(que -> queue_ptr == NULL){
        return -1;
    }
    que -> max = max;
    return 0;
}    
int enque(IntRing* que, int x){
    if(que -> num >= que -> max){
        //Queue is full.
        return -1;
    }
    que -> queue_ptr[que -> rear++] = x;
    que -> num++;
    if(que -> rear == que -> max){
        //Rear is at the end of queue.
        que -> rear = 0;
    }
    return 0;
}    
int deque(IntRing* que){
    if(que -> num <= 0){
        return -1;
    }
    int x = que -> queue_ptr[que -> front];
    que -> queue_ptr[que -> front++] = 0;
    que -> num--;
    if(que -> front == que -> max){
        que -> front = 0;
    }
    return x;
}
int peek_que(const IntRing* que){
    if(que -> num <= 0){
        return -1;
    }
    return que -> queue_ptr[que -> front];
}  
void clear_que(IntRing* que){
    for (int i = 0; i < que -> max; i++)
    {
        que -> queue_ptr[i] = 0;
    }
    que -> num = 0;
    que -> front = 0;
    que -> rear = 0;
}
int capacity_que(const IntRing* que){
    return que -> max;
}
int size_que(const IntRing *que){
    return que -> num;
}
int check_que_empty(const IntRing* que){
    if(que -> num <= 0){
        return 1;
    }
    else{
        return 0;
    }
}
int check_que_full(const IntRing* que){
    if(que -> max == que -> num){
        return 1;
    }
    else{
        return 0;
    }
}
int search_que(const IntRing* que, int x){
    int idx;
    for(int i =0; i < que -> num; i++)
    {   
        if(que -> queue_ptr[idx = (que -> front + i) % (que -> max)] == x){
            return idx;
        }
        else{
            return -1;
        }
    }
}
void print_que(const IntRing* que){
    int idx;
    for(int i =0; i < que -> num; i++)
    {   
        idx = (que -> front + i) % (que -> max);
        printf("%4d",que -> queue_ptr[idx]);
    }
    printf("\n");
}
int del_que(IntRing* que){
    if (que -> queue_ptr == NULL){
        return -1;
    }
    free(que -> queue_ptr);
    que -> max = 0;
    que -> num = 0;
    que -> front = 0;
    que -> rear = 0;
    return 0;
}