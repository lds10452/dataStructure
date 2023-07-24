#pragma once
#include"../dynamicArray/dynamicArray.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	typedef void* SeqQueue;
	SeqQueue initQueue();
	void pushSeqQueue(SeqQueue queue, void* data);
	void popSeqQueue(SeqQueue queue);
	void* frontSeqQueue(SeqQueue queue);
	void* backSeqQueue(SeqQueue queue);
	int sizeSeqQueue(SeqQueue queue);
	void destroySeqQueue(SeqQueue queue);
#ifdef __cplusplus
}
#endif // __cplusplus
