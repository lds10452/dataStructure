#include<stdio.h>
#include<stdlib.h>

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
}
int main()
{
	test();
	system("pause");
	return 0;
}
