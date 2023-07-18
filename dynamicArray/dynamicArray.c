#include"dynamicArray.h"

struct dynamicArray* initDynamicArray(int capacity)
{
	if (capacity <= 0)
		return NULL;
	struct dynamicArray* array = (struct dynamicArray*)malloc(sizeof(struct dynamicArray));
	if (!array)
		return array;
	array->m_nCapacity = capacity;
	array->m_nSize = 0;
	array->m_pAddr = (void**)malloc(sizeof(void*) * array->m_nCapacity);
	return array;
}
void insertDynamicArray(struct dynamicArray* array, int pos, void* data)
{
	if (!array || !data) return;
	if (pos<0 || pos>array->m_nSize)
		pos = array->m_nSize;
	if (array->m_nSize >= array->m_nCapacity)
	{
		int newCapacity = array->m_nCapacity * 2;
		void** newSpace = (void**)malloc(sizeof(void*) * newCapacity);
		if (!newSpace) return;
		memcpy(newSpace, array->m_pAddr, sizeof(void*) * array->m_nCapacity);
		free(array->m_pAddr);
		array->m_pAddr = newSpace;
		array->m_nCapacity = newCapacity;
	}
	for (int i = array->m_nSize - 1; i >= pos; i--)
	{
		array->m_pAddr[i + 1] = array->m_pAddr[i];
	}
	array->m_pAddr[pos] = data;
	array->m_nSize++;
}
void foreachDynamicArray(struct dynamicArray* array, void(*myForech)(void*))
{
	if (!array || !myForech) return;
	for (int i = 0; i < array->m_nSize; i++)
	{
		myForech(array->m_pAddr[i]);
	}
}

void removeByPosDynamicArray(struct dynamicArray* array, int pos)
{
	if (!array || pos<0 || pos>array->m_nSize - 1) return;
	//free((struct Person*)array->m_pAddr[pos]);
	for (int i = pos + 1; i < array->m_nSize; i++)
	{
		array->m_pAddr[i - 1] = array->m_pAddr[i];
	}
	array->m_nSize--;
}
void removeByValueDynamicArray(struct dynamicArray* array, void* data, int(*myCompare)(void*, void*))
{
	if (!array || !data)return;
	for (int i = 0; i < array->m_nSize; i++)
	{
		if (myCompare(array->m_pAddr[i], data))
		{
			removeByPosDynamicArray(array, i);
			break;
		}
	}
}
void destroyDynamicArray(struct dynamicArray* array)
{
	if (!array || !array->m_pAddr)return;
	free(array->m_pAddr);
	array->m_pAddr = NULL;
	free(array);
	array = NULL;
}