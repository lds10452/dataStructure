#include"LinkList.h"
struct Person
{
	char name[64];
	int age;
};
void myPrint(void *data)
{
	struct Person* person = (struct Person*)data;
	printf("name:%s    age:%d\n", person->name, person->age);
}
int myCompare(void* data1, void* data2)
{
	struct Person* p1 = (struct Person*)data1;
	struct Person* p2 = (struct Person*)data2;
	return !strcmp(p1->name, p2->name) && (p1->age == p2->age);
}
void test()
{
	LinkList list = InitList();
	struct Person p1 = { "ÕÅ·É",18 };
	struct Person p2 = { "Öî¸ğ",13 };
	struct Person p3 = { "Áõ±¸",23 };
	struct Person p4 = { "¹ØÓğ",42 };
	struct Person p5 = { "Áõìø",12 };
	struct Person p6 = { "õõ²õ",53 };
	insertLinkList(list, 0, &p1);
	insertLinkList(list, 0, &p2);
	insertLinkList(list, 1, &p3);
	insertLinkList(list, 2, &p4);
	insertLinkList(list, 20, &p5);
	insertLinkList(list, -1, &p6);
	foreachLinkList(list, myPrint);
	printf("size:%d\n", sizeLinkList(list));
	removeByPosLinkList(list, 2);
	foreachLinkList(list, myPrint);
	printf("size:%d\n", sizeLinkList(list));
	struct Person p7 = { "Áõìø",12 };
	removeByValueLinkList(list, &p7, myCompare);
	foreachLinkList(list, myPrint);
	printf("size:%d\n", sizeLinkList(list));
	clearLinkList(list);
	printf("size:%d\n", sizeLinkList(list));
	destroyLinkList(list);
	//printf("size:%d\n", sizeLinkList(list));
}
int main()
{
	test();
	system("pause");
	return 0;
}