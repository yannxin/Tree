// BinaryTreeTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryTree.h"

void test1()
{
	int data[] = {35, 6, 15, 65, 7, 3, 9, 26, 18, 36, 3, 46, 17, 43};
	int size = sizeof(data)/sizeof(*data);
//	printf("size = %d\n", size);
	BSTree BST = NULL;
	BuildBSTree(BST, data, 0, size - 1);
	MidOrderTraverse(BST);
	printf("\n");
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	test1();
	return 0;
}

