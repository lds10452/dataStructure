#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	typedef struct dynamicArray
	{
		void** m_pAddr;
		int m_nCapacity;
		int m_nSize;
	}dynamicArray;
	struct dynamicArray* initDynamicArray(int capacity);
	void insertDynamicArray(struct dynamicArray* array, int pos, void* data);
	void foreachDynamicArray(struct dynamicArray* array, void(*myForech)(void*));
	void removeByPosDynamicArray(struct dynamicArray* array, int pos);
	void removeByValueDynamicArray(struct dynamicArray* array, void* data, int(*myCompare)(void*, void*));
	void destroyDynamicArray(struct dynamicArray* array);

#ifdef __cplusplus
}
#endif // __cplusplus