#pragma once
#include<stdlib.h>
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	typedef struct QueueNode
	{
		struct QueueNode* next;
	}QueueNode;
	typedef void* LinkQueue;
	LinkQueue InitQueue();
	void pushLinkQueue(LinkQueue queue, void* data);
	void popLinkQueue(LinkQueue queue);
	void* frontLinkQueue(LinkQueue queue);
	void* backLinkQueue(LinkQueue queue);
	int sizeLinkQueue(LinkQueue queue);
	void destroyLinkQueue(LinkQueue queue);
#ifdef __cplusplus
}
#endif // __cplusplus
