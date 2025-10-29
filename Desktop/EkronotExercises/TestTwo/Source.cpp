#include <iostream>
#include "Queue.h"
#include "smth.h"


void initQueue(Queue* q, unsigned int size)
{
	q->data = new unsigned int[size];
	q->front = 0;
	q->rear = 0;
	q->size = 0;
	q->capacity = size;

}