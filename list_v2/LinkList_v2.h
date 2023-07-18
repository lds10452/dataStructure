#pragma once
#include<stdlib.h>
#include<stdio.h>
#ifdef __cplusplus
extern "C" {
#endif
	typedef struct LinkNode
	{
		struct LinkNode* next;
	}LinkNode;
	typedef struct LList
	{
		LinkNode header;
		int size;
	}LList;
	typedef void* LinkList;
	LinkList InitLinkList();
	void InsertLinkList(LinkList list, int pos, void* data);
	void ForechLinkList(LinkList list, void (*MyForech)(void*));
	void RemoveByPosLinkList(LinkList list, int pos);
	void DestroyLinkList(LinkList* list);
#ifdef __cplusplus
}
#endif // __cplusplus

