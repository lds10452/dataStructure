#include"seqQueue.h"
typedef struct Person
{
	char name[64];
	int age;
}Person;
void test()
{
	SeqQueue queue = initQueue();
	struct Person p1 = { "�ŷ�",18 };
	struct Person p2 = { "���",13 };
	struct Person p3 = { "����",23 };
	struct Person p4 = { "����",42 };
	struct Person p5 = { "����",12 };
	struct Person p6 = { "����",53 };
	pushSeqQueue(queue, &p1);
	pushSeqQueue(queue, &p2);
	pushSeqQueue(queue, &p3);
	pushSeqQueue(queue, &p4);
	pushSeqQueue(queue, &p5);
	pushSeqQueue(queue, &p6);
	Person* p = (Person*)backSeqQueue(queue);
	printf("%s,%d\n", p->name, p->age);
	int num = sizeSeqQueue(queue);
	while (num>0)
	{
		p = (Person*)frontSeqQueue(queue);
		printf("%d-->%s,%d\n", num, p->name, p->age);
		popSeqQueue(queue);
		num = sizeSeqQueue(queue);
	}
	destroySeqQueue(queue);
}
int main()
{
	test();
	system("pause");
	return 0;
}