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
	Person p1 = { {NULL},"ÕÅ·É",18 };
	Person p2 = { NULL,"Öî¸ð",13 };
	Person p3 = { NULL,"Áõ±¸",23 };
	Person p4 = { NULL,"¹ØÓð",42 };
	Person p5 = { NULL,"Áõìø",12 };
	Person p6 = { NULL,"õõ²õ",53 };
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