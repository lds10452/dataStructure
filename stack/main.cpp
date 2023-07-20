#include"seqStack.h"
#if 1
struct Person
{
	char m_cName[64];
	int m_nAge;
};
void test()
{
	SeqStack stack = InitSeqStack();
	struct Person p1 = { "ÕÅ·É",18 };
	struct Person p2 = { "Öî¸ð",13 };
	struct Person p3 = { "Áõ±¸",23 };
	struct Person p4 = { "¹ØÓð",42 };
	struct Person p5 = { "Áõìø",12 };
	struct Person p6 = { "õõ²õ",53 };
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
#else
int isLeft(char c)
{
	return c == '(';
}
int isRight(char c)
{
	return c == ')';
}
void printError(char* str,const char* err, char* p)
{
	printf("%s\n", err);
	printf("%s\n", str);
	int pos = p - str;
	for (int i = 0; i < pos; i++)
	{
		printf(" ");
	}
	printf("A\n");
}
void test()
{
	char str[] = "1+3*(2-)-)99+(";
	char* p = str;
	SeqStack stack = InitSeqStack();
	while (*p!='\0')
	{
		if (isLeft(*p))
		{
			PushSeqStack(stack, p);
		}
		else if (isRight(*p))
		{
			if (!EmptySeqStack(stack))
			{
				PopSeqStack(stack);
			}
			else
			{
				printError(str, "Ã»ÓÐÆ¥Åäµ½×óÀ¨ºÅ", p);
				break;
			}
		}
		p++;
	}
	while (!EmptySeqStack(stack))
	{
		printError(str, "Ã»ÓÐÆ¥Åäµ½ÓÒÀ¨ºÅ", (char*)TopSeqStack(stack));
		PopSeqStack(stack);
	}
	DestroySeqStack(stack);
}
#endif
int main()
{
	test();
	system("pause");
	return 0;
}