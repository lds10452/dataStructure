#include"LinkList_v2.h"

LinkList InitLinkList()
{
	LList* list = (LList*)malloc(sizeof(LList));
	if (!list)return NULL;
	list->header.next = NULL;
	list->size = 0;
	return list;
}
void InsertLinkList(LinkList list, int pos, void* data)
{
	if (!list || !data)return;
	LList* myList = (LList*)list;
	if (pos<0 || pos>myList->size)
	{
		pos = myList->size;
	}
	LinkNode* pCur = &myList->header;
	for (int i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}
	LinkNode* pInsert = (LinkNode*)data;
	pInsert->next = pCur->next;
	pCur->next = pInsert;
	myList->size++;
}
void ForechLinkList(LinkList list, void (*MyForech)(void*))
{
	if (!list||!MyForech)
		return;
	LList* myList = (LList*)list;
	LinkNode* pCur = myList->header.next;
	while (pCur)
	{
		MyForech(pCur);
		pCur = pCur->next;
	}
}
void RemoveByPosLinkList(LinkList list, int pos)
{
	if (!list)return;
	LList* myList = (LList*)list;
	if (pos<0 || pos>myList->size - 1)
	{
		return;
	}
	LinkNode* pCur = &myList->header;
	for (int i = 0; i < pos; i++)
	{
		pCur = pCur->next;
	}
	LinkNode* pDel = pCur->next;
	pCur->next = pDel->next;
	myList->size--;
}
void DestroyLinkList(LinkList* list)
{
	if (!*list)return;
	free(*list);
	*list = NULL;
}