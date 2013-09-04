

#pragma once

typedef struct BSTreeNode
{
	int value;
	int count;
	BSTreeNode* left;
	BSTreeNode* right;
}*BSTree;

void InsertNode(BSTree &BST, int value);
void DeleteNode(BSTree &BST, int value);
void BuildBSTree(BSTree &BST,int data[], int low, int high);
BSTree Search(BSTree &BST, int value);
void PreOrderTraverse(BSTree BST);
void MidOrderTraverse(BSTree BST);
void PostOrderTraverse(BSTree BST);
