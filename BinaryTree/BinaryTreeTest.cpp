// BinaryTreeTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryTree.h"

void test1()
{
	int data[] = {35, 6, 15, 65, 7, 17, 3, 9, 26, 18, 36, 3, 46, 17, 43, 3};
//	int data[] = {3};
	int size = sizeof(data)/sizeof(*data);
//	printf("size = %d\n", size);
	BSTree BST = NULL;
	BuildBSTree(BST, data, 0, size - 1);
	MidOrderTraverse(BST);
	printf("\n");
	PreOrderTraverse(BST);
	printf("\n");
	PostOrderTraverse(BST);
	printf("\n");

	BSTree node = SearchBST(BST, 18);
	if (!node)
		printf("Search failed.\n");
	else
		printf("Search success, the search value is %d.\n", node->value);

	printf("\n");
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	test1();
	return 0;
}

