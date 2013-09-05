// BinaryTreeTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryTree.h"

void test1()
{
	int data[] = {35, 6, 15, 65, 7, 46, 17, 43, 3, 7};
//	int data[] = {3};
	int size = sizeof(data)/sizeof(*data);
//	printf("size = %d\n", size);
	BSTree BST = NULL;
	BuildBSTree(BST, data, 0, size - 1);
	PreOrderTraverse(BST);
	printf("\n");
	MidOrderTraverse(BST);
	printf("\n");
	PostOrderTraverse(BST);
	printf("\n");

	BSTree node = SearchBST(BST, 17, 0);
	if (!node)
		printf("Search failed.\n");
	else
		printf("Search success, the search value is %d.\n", node->value);

	int n;
	scanf("%d", &n);
	while (n != -1)
	{
		DeleteNode(BST, n);
//		printf("Delete node %d.\n", n);
		MidOrderTraverse(BST);
		printf("\n");
		scanf("%d", &n);
	}

	printf("\n");
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	test1();
	return 0;
}

