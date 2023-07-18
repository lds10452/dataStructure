#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	typedef void* LinkList;
	typedef void (*FOREACH)(void*);
	typedef int (*COMPARE)(void*, void*);
	LinkList InitList();
	void insertLinkList(LinkList list, int pos, void* data);
	void foreachLinkList(LinkList list, FOREACH myForeach);
	void removeByPosLinkList(LinkList list, int pos);
	void removeByValueLinkList(LinkList list, void* data, COMPARE compare);
	void clearLinkList(LinkList list);
	int sizeLinkList(LinkList list);
	void destroyLinkList(LinkList list);
#ifdef __cplusplus
}
#endif // __cplusplus