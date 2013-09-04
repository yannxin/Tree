// BinaryTreeTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryTree.h"

void test1()
{
	int data[] = {5, 6, 15, 65, 7, 3, 9, 26, 18, 36, 46, 17, 43};
	int size = sizeof(data)/sizeof(*data);
//	printf("size = %d\n", size);
	
	BSTreeNode *BSTree = BuildBSTree(data, 0, size - 1);
	MidOrderTraverse(BSTree);
	printf("\n");
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	BSTreeNode *BSTree1 = NULL;
	BSTreeNode *BSTree2 = new BSTreeNode();
	printf("BSTree1 = %x\nBSTree2 = %x\n", (int)BSTree1, (int)BSTree2);

	test1();
	return 0;
}

