#include"dynamicArray.h"

struct Person
{
	char name[64];
	int age;
};
void myPrintPerson(void* data)
{
	struct Person* p = (struct Person*)data;
	printf("ÐÕÃû:%s   ÄêÁä:%d\n", p->name, p->age);
}
int myComparePerson(void* data1, void* data2)
{
	struct Person* p1 = (struct Person*)data1;
	struct Person* p2 = (struct Person*)data2;
	return (p1->age == p2->age) && (!strcmp(p1->name, p2->name));
}
void test01()
{
	struct dynamicArray* arr = initDynamicArray(5);
	struct Person p1 = { "ÕÅ·É",18 };
	struct Person p2 = { "Öî¸ð",13 };
	struct Person p3 = { "Áõ±¸",23 };
	struct Person p4 = { "¹ØÓð",42 };
	struct Person p5 = { "Áõìø",12 };
	struct Person p6 = { "õõ²õ",53 };
	printf("Capacity:%d\n", arr->m_nCapacity);
	insertDynamicArray(arr, 0, &p1);
	insertDynamicArray(arr, 0, &p2);
	insertDynamicArray(arr, 0, &p3);
	insertDynamicArray(arr, 1, &p4);
	insertDynamicArray(arr, 12, &p5);
	insertDynamicArray(arr, 2, &p6);
	printf("Capacity:%d\n", arr->m_nCapacity);
	foreachDynamicArray(arr, myPrintPerson);
	printf("after remove--------\n");
	removeByPosDynamicArray(arr, 1);
	foreachDynamicArray(arr, myPrintPerson);
	printf("after remove--------\n");
	struct Person p7 = { "Áõ±¸",23 };
	removeByValueDynamicArray(arr, &p7, myComparePerson);
	foreachDynamicArray(arr, myPrintPerson);
	destroyDynamicArray(arr);
	//printf("Capacity:%d\n", arr->m_nCapacity);
	//foreachDynamicArray(arr, myPrintPerson);
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}