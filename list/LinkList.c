#include"LinkList.h"
struct LinkNode
{
	void* data;
	struct LinkNode* next;
};
struct LList
{
	struct LinkNode header;
	int size;
};

LinkList InitList()
{
	struct LList* list = (struct LList*)malloc(sizeof(struct LList));
	if (!list) return NULL;
	list->header.data = NULL;
	list->header.next = NULL;
	list->size = 0;
	return list;
}
void insertLinkList(LinkList list, int pos, void* data)
{
	if (!list || !data)return;
	struct LList* myList = (struct LList*)list;
	if (pos<0 || pos>myList->size)
	{
		pos = myList->size;
	}
	struct LinkNode* pCurrent = &(myList->header);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	struct LinkNode* newNode = (struct LinkNode*)malloc(sizeof(struct LinkNode));
	newNode->data = data;
	newNode->next = NULL;

	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	myList->size++;
}
void foreachLinkList(LinkList list, FOREACH myForeach)
{
	if (!list || !myForeach)return;
	struct LList* myList = (struct LList*)list;
	struct LinkNode*pCurrent= myList->header.next;
	while (pCurrent)
	{
		myForeach(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}
void removeByPosLinkList(LinkList list, int pos)
{
	struct LList* myList = (struct LList*)list;
	if (!list || pos<0 || pos>myList->size - 1)return;
	struct LinkNode* pCurrent = &(myList->header);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	struct LinkNode* pDel = pCurrent->next;
	pCurrent->next = pDel->next;
	free(pDel);
	pDel = NULL;
	myList->size--;
}
void removeByValueLinkList(LinkList list, void* data, COMPARE compare)
{
	if (!list || !data || !compare)return;
	struct LList* myList = (struct LList*)list;
	struct LinkNode* pPrev = &(myList->header);
	struct LinkNode* pCurrent = pPrev->next;
	while (pCurrent)
	{
		if (compare(pCurrent->data, data))
		{
			pPrev->next = pCurrent->next;
			free(pCurrent);
			myList->size--;
			break;
		}
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
}
void clearLinkList(LinkList list)
{
	if (!list)return;
	struct LList* myList = (struct LList*)list;
	struct LinkNode* pCurrent = myList->header.next;
	while (pCurrent)
	{
		struct LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}
	myList->header.next = NULL;
	myList->size = 0;
}
int sizeLinkList(LinkList list)
{
	if (!list)return -1;
	struct LList* myList = (struct LList*)list;
	return myList->size;
}
void destroyLinkList(LinkList list)
{
	if (!list)return;
	clearLinkList(list);
	free(list);
}