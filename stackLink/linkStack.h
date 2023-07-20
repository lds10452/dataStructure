#pragma once
#include<stdlib.h>
#ifdef __cplusplus
extern "C" {
#endif
	typedef void* LinkStack;
	typedef struct StackNode
	{
		struct StackNode* next;
	}StackNode;
	LinkStack InitStack();
	void PushLinkStack(LinkStack stack, void* data);
	void PopLinkStack(LinkStack stack);
	void* TopLinkStack(LinkStack stack);
	int SizeLinkStack(LinkStack stack);
	int EmptyLinkStack(LinkStack stack);
	void DestroyLinkStack(LinkStack stack);
#ifdef __cplusplus
}
#endif // __cplusplus
