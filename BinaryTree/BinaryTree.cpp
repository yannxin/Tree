

#include "stdafx.h"
#include "BinaryTree.h"

void InsertNode(BSTreeNode *BSTree, int value)
{
	if (BSTree == NULL)
	{
		BSTree = new BSTreeNode();
		BSTree->value = value;
		BSTree->count = 1;
		BSTree->left = BSTree->right = NULL;
	}
	else if (value < BSTree->value)
		InsertNode(BSTree->left, value);
	else if (value > BSTree->value)
		InsertNode(BSTree->right, value);
	else
		++BSTree->count;
}

void DeleteNode(BSTreeNode *BSTree, int value)
{

}

BSTreeNode* BuildBSTree(BSTreeNode *BSTree, int data[], int low, int high)
{
	if (data == NULL || low > high)
		return NULL;
	BSTreeNode *BSTree = new BSTreeNode();

	int i;
	for (i = low + 1; i <= high; i++)
	{
		InsertNode(BSTree, data[i]);
	}
	return BSTree;
}

BSTreeNode* Search(BSTreeNode *BSTree, int value)
{
	return BSTree;
}
void PreOrderTraverse(BSTreeNode *BSTree)
{

}
void MidOrderTraverse(BSTreeNode *BSTree)
{
	if (BSTree == NULL)
	{
		return;
	}
	else
	{
		MidOrderTraverse(BSTree->left);
		printf("%d ", BSTree->value);
		MidOrderTraverse(BSTree->right);
	}

}
void PostOrderTraverse(BSTreeNode *BSTree)
{

}

