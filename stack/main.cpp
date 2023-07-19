#include"seqStack.h"

struct Person
{
	char m_cName[64];
	int m_nAge;
};
void test()
{
	SeqStack stack = InitSeqStack();
	struct Person p1 = { "�ŷ�",18 };
	struct Person p2 = { "���",13 };
	struct Person p3 = { "����",23 };
	struct Person p4 = { "����",42 };
	struct Person p5 = { "����",12 };
	struct Person p6 = { "����",53 };
	PushSeqStack(stack, &p1);
	PushSeqStack(stack, &p2);
	PushSeqStack(stack, &p3);
	PushSeqStack(stack, &p4);
	PushSeqStack(stack, &p5);
	PushSeqStack(stack, &p6);
	int size = SizeSeqStack(stack);
	printf("size:%d\n", size);
	while (!EmptySeqStack(stack))
	{
		Person* p = (Person*)TopSeqStack(stack);
		printf("%s,%d\n", p->m_cName, p->m_nAge);
		PopSeqStack(stack);
	}
	size = SizeSeqStack(stack);
	printf("size:%d\n", size);
	DestroySeqStack(stack);
}
int main()
{
	test();
	system("pause");
	return 0;
}