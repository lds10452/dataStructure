#include "seqStack.h"

typedef struct SStack
{
	void* m_pData[MAX];
	int m_nSize;
}SStack;

SeqStack InitSeqStack()
{
	SStack* stack = (SStack*)malloc(sizeof(SStack));
	if (!stack)return NULL;
	memset(stack->m_pData, 0, sizeof(void*) * MAX);
	stack->m_nSize = 0;
	return stack;
}
void PushSeqStack(SeqStack stack, void* data)
{
	if (!stack||!data)return;
	SStack* myStack = (SStack*)stack;
	if (myStack->m_nSize == MAX)return;
	myStack->m_pData[myStack->m_nSize] = data;
	myStack->m_nSize++;
}
void PopSeqStack(SeqStack stack)
{
	if (!stack)return;
	SStack* myStack = (SStack*)stack;
	if (myStack->m_nSize <= 0)return;
	myStack->m_pData[myStack->m_nSize - 1] = NULL;
	myStack->m_nSize--;
}
void* TopSeqStack(SeqStack stack)
{
	if (!stack)return NULL;
	SStack* myStack = (SStack*)stack;
	if (myStack->m_nSize <= 0)return NULL;
	return myStack->m_pData[myStack->m_nSize - 1];
}
int SizeSeqStack(SeqStack stack)
{
	if (!stack)return -1;
	SStack* myStack = (SStack*)stack;
	return myStack->m_nSize;
}
int EmptySeqStack(SeqStack stack)
{
	if (!stack)return -1;
	SStack* myStack = (SStack*)stack;
	if (myStack->m_nSize <=0)
	{
		return 1;
	}
	return 0;
}
void DestroySeqStack(SeqStack stack)
{
	if (!stack)return NULL;
	free(stack);
}