#include"bst.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

Tree * newTree()
{
	Tree *bst = malloc(sizeof(Tree));
	bst->root = NULL;
	bst->insert = insert;
	bst->search = search;
	bst->sort = sort;
	bst->compare = compare;
	bst->clone = clone;
	bst->delete = delete;
	bst->removeData = removeData;
	return bst;
}

Node * newNode(Data data, Node * parent)
{
	Node *node = malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	return node;
}


Data * insertNode(Node *node, Data data)
{
	if(node->data.value == data.value)
	{
		return NULL;
	}
	else if(node->data.value < data.value)
	{
		if(node->right == NULL)
		{
			node->right = newNode(data, node);
			return &(node->right->data);
		}
		else
		{
			return insertNode(node->right, data);
		}
	}
	else if(node->data.value > data.value)
	{
		if(node->left == NULL)
		{
			node->left = newNode(data, node);
			return &(node->left->data);
		}
		else
		{
			return insertNode(node->left, data);
		}
	}
}

Data * insert(Tree *bst, Data data)
{
	Data *temp = NULL;
	if(bst->root == NULL)
	{
		bst->root = newNode(data, NULL);
		temp = &(bst->root->data);
	}
	else
	{
		temp = insertNode(bst->root, data);
	}
	return temp;
}

Node * searchNode(Node *node, Data data)
{
	if(node->data.value == data.value)
	{
		return node;
	}
	else if(node->data.value > data.value && node->left != NULL)
	{
		return searchNode(node->left, data);
	}
	else if(node->data.value < data.value && node->right != NULL)
	{
		return searchNode(node->right, data);
	}
}

Data * search(Tree * bst, Data data)
{
	Node *temp = NULL;
	if(bst->root == NULL)
	{
		return NULL;
	}
	else
	{
		temp = searchNode(bst->root, data);
		return &(temp->data);
	}
}

void sortTree(Node *node, Data *data, int *index)
{
	if(node != NULL)
	{
		sortTree(node->left, data, index);
		data[*index] = node->data;
		(*index)++;
		sortTree(node->right, data, index);
	}
}

void sort(Tree *bst, Data *data)
{	
	int i = 0;	
	if(bst->root != NULL)
	{
		sortTree(bst->root, data, &i);
	}
}

void Traversal(Node *node, Data *data, int *index)
{
	if(node != NULL)
	{
		data[*index] = node->data;
		(*index)++;
		Traversal(node->left, data, index);		
		Traversal(node->right, data, index);
	}
}

int compare(Tree *tree, Tree *treeCopy)
{
	if(tree==NULL || treeCopy==NULL)
	{
		return 0;
	}
	int f= comparedTree(tree->root, treeCopy->root);
	return f;
}

int comparedTree(Node *node, Node *treeCopy)
{
	int f=1;
	if(node!=NULL && treeCopy!=NULL)
	{
		if(node->data.value == treeCopy->data.value)
		{
			f = 1;
			comparedTree(node->left, treeCopy->left);
			comparedTree(node->right, treeCopy->right);
		}
		else
		{
			return f;
		}
	}
	else if(node==NULL && treeCopy==NULL)
	{
		f=1;
	}
	return f;
}

Node * cloneNode(Node *originalNode, Node *node1, Node *parentNode)
{
	Node *temp = NULL;
	if(originalNode != NULL)
	{
		temp = newNode(originalNode->data, parentNode);
		if(originalNode->left != NULL)
		{
			temp->left = cloneNode(originalNode->left, temp->left, temp);
		}
		if(originalNode->right != NULL)
		{
			temp->right = cloneNode(originalNode->right, temp->right, temp);
		}
	}
	return temp;
}

Tree * clone(Tree *tree)
{
	Tree *clone = newTree();
	clone->root = cloneNode(tree->root, clone->root, NULL);
	return clone;
}


void removeLeaf(Node * leaf)
{
	if(leaf->parent != NULL)
	{	
		if(leaf->parent->right == leaf)
			leaf->parent->right = NULL;
		else
			leaf->parent->left = NULL;
	}
	free(leaf);
}

void shortCircuit(Node *node)
{
	if(node->parent->right == node)
	{
		if(node->right == NULL)
		{
			node->parent->right = node->left;
			node->left->parent = node->parent;
		}
		else
		{
			node->parent->right = node->right;
			node->right->parent = node->parent;
		}
	}
	else if(node->parent->left == node)
	{
		if(node->left == NULL)
		{
			node->parent->left = node->right;
			node->right->parent = node->parent;
		}
		else
		{
			node->parent->left = node->left;
			node->left->parent = node->parent;
		}
	}

	free(node);
}

Node * searchMax(Node *node)
{
	while(node->right != NULL)
		node = node->right;
	return node;
}

void promotion(Node *node)
{
	Node *temp = searchMax(node->left);
	node->data = temp->data;
	if(temp->left == NULL && temp->right == NULL)
	{
		removeLeaf(temp);
	}
	else
	{
		shortCircuit(temp);
	}
}

void removeData(Tree * bst, Data data)
{
	Node *node = NULL;
	node = searchNode(bst->root, data);
	if(node != NULL)
	{
		if(node->left == NULL && node->right == NULL)
		{	
			if(bst->root == node)
			{
				free(node);
				bst->root = NULL;
			}
			else
			{
				removeLeaf(node);
			}
		}
		else if((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL))
		{
			if(bst->root == node)
			{
				if(node->left == NULL)
					bst->root = node->right;
				else
					bst->root = node->left;
				free(node);
			}
			else
			{
				shortCircuit(node);
			}
		}
		else if(node->left != NULL && node->right != NULL)
		{
			promotion(node);
		}
	}
}

void deleteTree(Node *node)
{
	if(node != NULL)
	{
		deleteTree(node->left);
		deleteTree(node->right);
		removeLeaf(node);
	}
}

void delete(Tree * bst)
{
	if(bst->root != NULL)
	{
		deleteTree(bst->root);
		free(bst);
	}
	else
	{
		free(bst);
	}
}
