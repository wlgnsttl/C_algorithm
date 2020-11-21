#include <stdio.h>

#ifndef __RING_BUFFER_H__
#define __RING_BUFFER_H__
typedef struct {  
    int max;    //Max num of queue
    int num;    //Curent number of element
    int front;  //front
    int rear;   //rear
    int* queue_ptr; //Pointer to first elemnt of queue
}IntRing;

/* function */
int init_que(IntRing* que, int max);    
int enque(IntRing* que, int x);         
int deque(IntRing* que);        
int peek_que(const IntRing* que);      
void clear_que(IntRing* que);
int capacity_que(const IntRing* que);
int size_que(const IntRing *que);
int check_que_empty(const IntRing* que);
int check_que_full(const IntRing* que);
int search_que(const IntRing* que, int x);
void print_que(const IntRing* que);
int del_que(IntRing* que);

#endif 