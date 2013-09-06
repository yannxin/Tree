

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
	BSTree pnode = SearchBST(BST, value, 1);
	BSTree dnode = NULL;
	int position = 0; // position is -1, 0, 1, which represents left, self, right respectly.

	if (pnode == NULL)
	{
		printf("Delete node is not found.\n");
		return;
	}
	else if (value == pnode->value)
	{
		dnode = pnode;
		position = 0;
	}
	else if (value < pnode->value)
	{
		dnode = pnode->left;
		position = -1;
	}
	else
	{
		dnode = pnode->right;
		position = 1;
	}

	if (1 < dnode->count)
	{
		--dnode->count;
		return;
	}
	else if ( !dnode->left )
	{
		if (0 == position)
			BST = dnode->right;
		else if (-1 == position)
			pnode->left = dnode->right;
		else 
			pnode->right = dnode->right;
	}
	else if ( dnode->left )
	{

		BSTree pmostRight = dnode;
		BSTree mostRight = dnode->left;
		while (mostRight->right)
		{
			pmostRight = mostRight;
			mostRight = mostRight->right;
		}
		if (0 == position)
		{
			mostRight->right = BST->right;
			BST = BST->left;
		}
		else if(pmostRight == dnode)
		{
			dnode->left = mostRight->left;
			dnode->value = mostRight->value;
			dnode->count = mostRight->count;
		}
		else
		{
			pmostRight->right = mostRight->left;
			dnode->value = mostRight->value;
			dnode->count = mostRight->count;
		}

	}

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

// if flag is true, return the parent of node.
// else return the node.
BSTree SearchBST(BSTree &BST, int value, int flag)
{
	BSTree node = BST;
	BSTree pnode = BST;
	while (node)
	{
		if (value == node->value)
		{
			if (flag)
				return pnode;
			else
				return node;
		}
		else if (value < node->value)
		{
			pnode = node;
			node = node->left;
		}
			
		else if (value > node->value)
		{
			pnode = node;
			node = node->right;
		}
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
		PreOrderTraverse(BST->left);
		PreOrderTraverse(BST->right);
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
		PostOrderTraverse(BST->left);
		PostOrderTraverse(BST->right);
		int i;
		for (i = 0; i < BST->count; i++)
		{
			printf("%d ", BST->value);
		}
	}
}

