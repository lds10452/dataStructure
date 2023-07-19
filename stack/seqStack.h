#pragma once
#include<stdio.h>
#include <stdlib.h>
#define MAX 1024
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	typedef void* SeqStack;
	SeqStack InitSeqStack();
	void PushSeqStack(SeqStack stack, void* data);
	void PopSeqStack(SeqStack stack);
	void* TopSeqStack(SeqStack stack);
	int SizeSeqStack(SeqStack stack);
	int EmptySeqStack(SeqStack stack);
	void DestroySeqStack(SeqStack stack);
#ifdef __cplusplus
}
#endif // __cplusplus