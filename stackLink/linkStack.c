#include"linkStack.h"

typedef struct LStack
{
	StackNode header;
	int size;
}LStack;
LinkStack InitStack()
{
	LStack* stack = (LStack*)malloc(sizeof(LStack));
	if (!stack)return NULL;
	stack->header.next = NULL;
	stack->size = 0;
	return stack;
}
void PushLinkStack(LinkStack stack, void* data)
{
	if (!stack || !data)return;
	LStack* myStack = (LStack*)stack;
	StackNode* myNode = (StackNode*)data;
	myNode->next = myStack->header.next;
	myStack->header.next = myNode;
	myStack->size++;
}
void PopLinkStack(LinkStack stack)
{
	if (!stack)return;
	LStack* myStack = (LStack*)stack;
	if (myStack->size <= 0)return;
	StackNode* myNode = myStack->header.next;
	myStack->header.next = myNode->next;
	myStack->size--;
}
void* TopLinkStack(LinkStack stack)
{
	if (!stack)return NULL;
	LStack* myStack = (LStack*)stack;
	if (myStack->size <= 0)return NULL;
	return myStack->header.next;
}
int SizeLinkStack(LinkStack stack)
{
	if (!stack)return -1;
	LStack* myStack = (LStack*)stack;
	return myStack->size;
}
int EmptyLinkStack(LinkStack stack)
{
	if (!stack)return -1;
	LStack* myStack = (LStack*)stack;
	if (myStack->size <= 0)
	{
		return 1;
	}
	return 0;
}
void DestroyLinkStack(LinkStack stack)
{
	if (!stack)return;
	free(stack);
}