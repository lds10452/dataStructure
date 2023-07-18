#include"LinkList_v2.h"
typedef struct
{
	LinkNode node;//或者void* addr;//
	char name[64];
	int age;
}Person;
void PrintPerson(void* data)
{
	Person* person = (Person*)data;
	printf("%s,%d\n", person->name, person->age);
}
void test()
{
	LinkList list = InitLinkList();
	Person p1 = { {NULL},"张飞",18 };
	Person p2 = { NULL,"诸葛",13 };
	Person p3 = { NULL,"刘备",23 };
	Person p4 = { NULL,"关羽",42 };
	Person p5 = { NULL,"刘禅",12 };
	Person p6 = { NULL,"貂蝉",53 };
	//LinkNode* pp1 = (LinkNode*)&p1.node;
	//printf("%p,%p\n", &p1, &p1.node);
	InsertLinkList(list, 0, &p1);
	InsertLinkList(list, 1, &p2);
	InsertLinkList(list, 0, &p3);
	InsertLinkList(list, 3, &p4);
	InsertLinkList(list, 10, &p5);
	InsertLinkList(list, -1, &p6);
	ForechLinkList(list, PrintPerson);
	printf("--------------\n");
	RemoveByPosLinkList(list, 2);
	ForechLinkList(list, PrintPerson);
	printf("--------------\n");
	DestroyLinkList(&list);
	ForechLinkList(list, PrintPerson);
}
int main()
{
	test();
	system("pause");
	return 0;
}