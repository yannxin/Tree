

#pragma once

struct BSTreeNode
{
	int value;
	int count;
	BSTreeNode* left;
	BSTreeNode* right;
};

void InsertNode(BSTreeNode **BSTree, int value);
void DeleteNode(BSTreeNode **BSTree, int value);
BSTreeNode* BuildBSTree(int data[], int low, int high);
BSTreeNode* Search(BSTreeNode *BSTree, int value);
void PreOrderTraverse(BSTreeNode *BSTree);
void MidOrderTraverse(BSTreeNode *BSTree);
void PostOrderTraverse(BSTreeNode *BSTree);
