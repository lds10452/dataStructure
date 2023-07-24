#include"seqQueue.h"
#define MAX 1024

SeqQueue initQueue()
{
	dynamicArray* queue = initDynamicArray(MAX);
	return queue;
}
void pushSeqQueue(SeqQueue queue, void* data)
{
	if (!queue || !data)return;
	dynamicArray* arr = (dynamicArray*)queue;
	if (arr->m_nSize >= MAX)return;
	insertDynamicArray(arr, arr->m_nSize, data);
}
void popSeqQueue(SeqQueue queue)
{
	if (!queue)return;
	dynamicArray* arr = (dynamicArray*)queue;
	if (arr->m_nSize <= 0)return;
	removeByPosDynamicArray(arr, 0);
}
void* frontSeqQueue(SeqQueue queue)
{
	if (!queue)return NULL;
	dynamicArray* arr = (dynamicArray*)queue;
	if (arr->m_nSize <= 0)return NULL;
	return arr->m_pAddr[0];
}
void* backSeqQueue(SeqQueue queue)
{
	if (!queue)return NULL;
	dynamicArray* arr = (dynamicArray*)queue;
	if (arr->m_nSize <= 0)return NULL;
	return arr->m_pAddr[arr->m_nSize - 1];
}
int sizeSeqQueue(SeqQueue queue)
{
	if (!queue)return -1;
	dynamicArray* arr = (dynamicArray*)queue;
	return arr->m_nSize;
}
void destroySeqQueue(SeqQueue queue)
{
	if (!queue)return;
	destroyDynamicArray(queue);
}