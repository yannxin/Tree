

#include "stdafx.h"
#include "BinaryTree.h"

void InsertNode(BSTree &BST, int value)
{
	BSTree node = new struct BSTreeNode();
	node->value = value;
	node->count = 1;
	node->left = node->right = NULL;

	if (BST == NULL)
		BST = node;
	else if (value < BST->value)
		InsertNode(BST->left, value);
	else if (value > BST->value)
		InsertNode(BST->right, value);
	else if (value == BST->value)
		++BST->count;
}

void DeleteNode(BSTreeNode *BSTree, int value)
{

}

void BuildBSTree(BSTree &BST, int data[], int low, int high)
{
	if (data == NULL || low > high)
		return;

	int i;
	for (i = low; i <= high; i++)
	{
		InsertNode(BST, data[i]);
	}
}

BSTree Search(BSTree &BST, int value)
{
	return BST;
}
void PreOrderTraverse(BSTree BST)
{
	if (BST)
	{
		int i;
		for (i = 0; i < BST->count; i++)
		{
			printf("%d ", BST->value);
		}
		MidOrderTraverse(BST->left);
		MidOrderTraverse(BST->right);
	}
}
void MidOrderTraverse(BSTree BST)
{
	if (BST)
	{
		MidOrderTraverse(BST->left);
		int i;
		for (i = 0; i < BST->count; i++)
		{
			printf("%d ", BST->value);
		}
		printf("%d ", BST->value);
		MidOrderTraverse(BST->right);
	}
}

void PostOrderTraverse(BSTree BST)
{
	if (BST)
	{
		MidOrderTraverse(BST->left);
		MidOrderTraverse(BST->right);
		int i;
		for (i = 0; i < BST->count; i++)
		{
			printf("%d ", BST->value);
		}
		printf("%d ", BST->value);
	}
}

