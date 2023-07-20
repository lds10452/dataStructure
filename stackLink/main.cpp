#include"linkStack.h"
#include<stdio.h>
struct Person
{
	StackNode node;
	char m_cName[64];
	int m_nAge;
};
void test()
{
	LinkStack stack = InitStack();
	Person p1 = { {NULL},"�ŷ�",18 };
	Person p2 = { NULL,"���",13 };
	Person p3 = { NULL,"����",23 };
	Person p4 = { NULL,"����",42 };
	Person p5 = { NULL,"����",12 };
	Person p6 = { NULL,"����",53 };
	PushLinkStack(stack, &p1);
	PushLinkStack(stack, &p2);
	PushLinkStack(stack, &p3);
	PushLinkStack(stack, &p4);
	PushLinkStack(stack, &p5);
	PushLinkStack(stack, &p6);
	int size = SizeLinkStack(stack);
	printf("size:%d\n", size);
	while (!EmptyLinkStack(stack))
	{
		Person* p = (Person*)TopLinkStack(stack);
		printf("name:%s,age:%d\n", p->m_cName, p->m_nAge);
		PopLinkStack(stack);
	}
	size = SizeLinkStack(stack);
	printf("size:%d\n", size);
	DestroyLinkStack(stack);
}
int main()
{
	test();
	system("pause");
	return 0;
}