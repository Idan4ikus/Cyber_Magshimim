#include <iostream>
#include "Queue.h"


void initQueue(Queue* q, unsigned int size)
{
	q->data = new unsigned int[size];
	q->front = 0;
	q->rear = 0;
	q->size = 0;
	q->capacity = size;

}


void cleanQueue(Queue* q)
{
	q->data = nullptr;
	q->front = 0;
	q->rear = 0;
	q->size = 0;
	q->capacity = 0;
}


void enqueue(Queue* q, unsigned int newValue)
{
	q->data[q->rear] = newValue;
	q->rear = q->rear + 1;
	q->size++;
}

int dequeue(Queue* q)
{
	unsigned int num = q->data[q->front];
	q->front = (q->front + +1) % q->capacity;
	q->size--;

	return num;
}

bool isEmpty(Queue* s)
{
	if (s->size == 0)
		return true;
	return false;
}

bool isFull(Queue* s)
{
	if (s->size == s->capacity)
		return true;
	return false;
}