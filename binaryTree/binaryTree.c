#include<stdio.h>
#include<stdlib.h>

//���к��������Կ����Ƕ�һ����������
//ҪôΪ�գ�Ҫô��Ӧ������һ�����֮ǰ����������������������
//�����пգ���������������������

typedef struct BinaryTreeNode
{
	char ch;
	struct BinaryTreeNode* lChild;
	struct BinaryTreeNode* rChild;
}BinaryTreeNode;
void recursion(BinaryTreeNode* root)
{
	if (!root)return;
	printf("%c ", root->ch);//���򣨸�������
	recursion(root->lChild);
//	printf("%c ", root->c);//�������
	recursion(root->rChild);
//	printf("%c ", root->c);//�������
}
void retLeafNum(BinaryTreeNode* root, int* num)
{
	if (!root)return;
	if (!root->lChild && !root->rChild)
	{
		(*num)++;
	}
	retLeafNum(root->lChild, num);
	retLeafNum(root->rChild, num);
}
int retTreeHeight(BinaryTreeNode* root)
{
	if (!root)return 0;
	int lHight = retTreeHeight(root->lChild);
	int rHight = retTreeHeight(root->rChild);
	return lHight > rHight ? lHight + 1 : rHight + 1;
}
BinaryTreeNode* copyTree(BinaryTreeNode* root)
{
	if (!root)return NULL;
	BinaryTreeNode* lTree = copyTree(root->lChild);
	BinaryTreeNode* rTree = copyTree(root->rChild);
	BinaryTreeNode* newTree = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	if (!newTree)return NULL;
	newTree->ch = root->ch;
	newTree->lChild = lTree;
	newTree->rChild = rTree;
	return newTree;
}
void freeTree(BinaryTreeNode* root)
{
	if (!root)return;
	freeTree(root->lChild);
	freeTree(root->rChild);
	printf("%c ", root->ch);
	free(root);
}
void test()
{
	BinaryTreeNode nodeA = { 'A',NULL,NULL };
	BinaryTreeNode nodeB = { 'B',NULL,NULL };
	BinaryTreeNode nodeC = { 'C',NULL,NULL };
	BinaryTreeNode nodeD = { 'D',NULL,NULL };
	BinaryTreeNode nodeE = { 'E',NULL,NULL };
	BinaryTreeNode nodeF = { 'F',NULL,NULL };
	BinaryTreeNode nodeG = { 'G',NULL,NULL };
	BinaryTreeNode nodeH = { 'H',NULL,NULL };
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;
	nodeB.rChild = &nodeC;
	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;
	nodeF.rChild = &nodeG;
	nodeG.lChild = &nodeH;
	recursion(&nodeA);

	int leafNum = 0;
	retLeafNum(&nodeA, &leafNum);
	printf("\nleaf num:%d\n", leafNum);

	int height = retTreeHeight(&nodeA);
	printf("tree height:%d\n", height);

	printf("new tree:");
	BinaryTreeNode* newTree = copyTree(&nodeA);
	recursion(newTree);

	printf("\nfree:");
	freeTree(newTree);
}
int main()
{
	test();
	system("pause");
	return 0;
}
