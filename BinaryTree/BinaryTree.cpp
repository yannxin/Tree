

#include "stdafx.h"
#include "BinaryTree.h"

void InsertNode(BSTree &BST, int value)
{
/*
 //insert node recursively.
	if (BST == NULL)
	{
		BSTree node = new struct BSTreeNode();
		node->value = value;
		node->count = 1;
		node->left = node->right = NULL;
		BST = node;
//		delete node;
	}
	else if (value < BST->value)
		InsertNode(BST->left, value);
	else if (value > BST->value)
		InsertNode(BST->right, value);
	else if (value == BST->value)
		++BST->count;
*/
	// insert node circularly
	BSTree node = new struct BSTreeNode();
	node->value = value;
	node->count = 1;
	node->left = node->right = NULL;
	if (BST == NULL)
	{
		BST = node;
	}
	else
	{
		BSTree p = BST;
		while (p)
		{
			if (value == p->value)
			{
				p->count++;
				break;
			}
			else if (value < p->value)
			{
				if (p->left)
					p = p->left;
				else
				{
					p->left = node;
					break;
				}

			}
			else if (value > p->value)
			{
				if (p->right)
					p = p->right;
				else
				{
					p->right = node;
					break;
				}
			}
		}
	}
}

void DeleteNode(BSTree &BST, int value)
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

BSTree SearchBST(BSTree &BST, int value)
{
	BSTree p = BST;
	while (p)
	{
		if (value == p->value)
			return p;
		else if (value < p->value)
			p = p->left;
		else if (value > p->value)
			p = p->right;
	}
	return NULL;
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
	}
}

