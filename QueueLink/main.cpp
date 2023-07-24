#include"linkQueue.h"
#include<stdio.h>
typedef struct Person
{
	void* node;//QueueNode node;
	char name[64];
	int age;
}Person;
void test()
{
	LinkQueue queue = InitQueue();
	Person p1 = { {NULL},"�ŷ�",18 };
	Person p2 = { NULL,"���",13 };
	Person p3 = { NULL,"����",23 };
	Person p4 = { NULL,"����",42 };
	Person p5 = { NULL,"����",12 };
	Person p6 = { NULL,"����",53 };
	pushLinkQueue(queue, &p1);
	pushLinkQueue(queue, &p2);
	pushLinkQueue(queue, &p3);
	pushLinkQueue(queue, &p4);
	pushLinkQueue(queue, &p5);
	pushLinkQueue(queue, &p6);
	Person* p = (Person*)backLinkQueue(queue);
	printf("back--->%s,%d\n", p->name, p->age);
	int num = sizeLinkQueue(queue);
	while (num > 0)
	{
		p = (Person*)frontLinkQueue(queue);
		printf("%d-->%s,%d\n", num, p->name, p->age);
		popLinkQueue(queue);
		num = sizeLinkQueue(queue);
	}
	destroyLinkQueue(queue);
}
int main()
{
	test();
	system("pause");
	return 0;
}