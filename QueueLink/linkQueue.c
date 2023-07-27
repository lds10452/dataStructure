#include"linkQueue.h"

typedef struct LQueue
{
	QueueNode header;
	int size;
	QueueNode* pTail;
}LQueue;
LinkQueue InitQueue()
{
	LQueue* queue = (LQueue*)malloc(sizeof(LQueue));
	if (!queue)return NULL;
	queue->header.next = NULL;
	queue->size = 0;
	queue->pTail = &queue->header;
	return queue;
}
void pushLinkQueue(LinkQueue queue, void* data)
{
	if (!queue || !data)return;
	LQueue* myQueue = (LQueue*)queue;
	QueueNode* myNode = (QueueNode*)data;
	myNode->next = NULL;
	myQueue->pTail->next = myNode;
	myQueue->pTail = myNode;
	myQueue->size++;
}
void popLinkQueue(LinkQueue queue)
{
	if (!queue)return;
	LQueue* myQueue = (LQueue*)queue;
	if (myQueue->size <= 0)return;
	QueueNode* pFront = myQueue->header.next;
	myQueue->header.next = pFront->next;
	myQueue->size--;
	if (myQueue->size == 0)
	{
		myQueue->pTail = &myQueue->header;
	}
}
void* frontLinkQueue(LinkQueue queue)
{
	if (!queue)return NULL;
	LQueue* myQueue = (LQueue*)queue;
	return myQueue->header.next;
}
void* backLinkQueue(LinkQueue queue)
{
	if (!queue)return NULL;
	LQueue* myQueue = (LQueue*)queue;
	return myQueue->pTail;
}
int sizeLinkQueue(LinkQueue queue)
{
	if (!queue)return -1;
	LQueue* myQueue = (LQueue*)queue;
	return myQueue->size;
}
void destroyLinkQueue(LinkQueue queue)
{
	if (!queue)return;
	free(queue);
}