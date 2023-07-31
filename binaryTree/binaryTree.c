#include<stdio.h>
#include<stdlib.h>
#include"../stack/seqStack.h"
//非递归遍历
typedef struct NonBinaryTreeNode
{
	char ch;
	struct BinaryTreeNode* lChild;
	struct BinaryTreeNode* rChild;
	int flag;
}NonBinaryTreeNode;
void nonRecursion(NonBinaryTreeNode* root);
//递归遍历
//所有递归的函数都可以看作是对一个结点操作：
//要么为空，要么对应操作，一般操作之前，先左子树再右子树操作
//即：判空，左子树，右子树，操作

typedef struct BinaryTreeNode
{
	char ch;
	struct BinaryTreeNode* lChild;
	struct BinaryTreeNode* rChild;
}BinaryTreeNode;
void recursion(BinaryTreeNode* root)
{
	if (!root)return;
	printf("%c ", root->ch);//先序（根）遍历
	recursion(root->lChild);
//	printf("%c ", root->c);//中序遍历
	recursion(root->rChild);
//	printf("%c ", root->c);//后序遍历
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
void test1()
{
	NonBinaryTreeNode nodeB = { 'B',NULL,NULL ,0 };
	NonBinaryTreeNode nodeC = { 'C',NULL,NULL ,0 };
	NonBinaryTreeNode nodeA = { 'A',NULL,NULL ,0 };
	NonBinaryTreeNode nodeD = { 'D',NULL,NULL ,0 };
	NonBinaryTreeNode nodeE = { 'E',NULL,NULL ,0 };
	NonBinaryTreeNode nodeF = { 'F',NULL,NULL ,0 };
	NonBinaryTreeNode nodeG = { 'G',NULL,NULL ,0 };
	NonBinaryTreeNode nodeH = { 'H',NULL,NULL ,0 };
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;
	nodeB.rChild = &nodeC;
	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;
	nodeF.rChild = &nodeG;
	nodeG.lChild = &nodeH;
	nonRecursion(&nodeA);
}
int main()
{
	test();
	//test1();
	system("pause");
	return 0;
}
void nonRecursion(NonBinaryTreeNode* root)
{
	if (!root)return;
	SeqStack* stack = InitSeqStack();
	if (!stack)return;
	PushSeqStack(stack, root);
	while (SizeSeqStack(stack)>0)
	{
		NonBinaryTreeNode* myNode = TopSeqStack(stack);
		PopSeqStack(stack);
		if (myNode->flag)
		{
			printf("%c ", myNode->ch);
			continue;
		}
		myNode->flag = 1;
		if (myNode->rChild)
		{
			PushSeqStack(stack, myNode->rChild);
		}
		if (myNode->lChild)
		{
			PushSeqStack(stack, myNode->lChild);
		}
		PushSeqStack(stack, myNode);
	}
	DestroySeqStack(stack);
}