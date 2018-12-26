#ifndef BST_H
#define BST_H
typedef struct Data
{
	int value;
} Data;

typedef struct Node
{
	Data data;
	struct Node *parent;
	struct Node *left;
	struct Node *right;
} Node;

typedef struct  Tree
{
    Node *root;
	Data * (*insert)(struct Tree *bst, Data data);
	Data * (*search)(struct Tree * bst, Data data);
	void (*sort)(struct Tree *bst, Data *data);
	int (*compare)(struct Tree *tree,struct Tree *treeCopy);
	struct Tree * (*clone)(struct Tree *tree);
	void (*delete)(struct Tree * bst);
	void (*removeData)(struct Tree * bst, Data value);
} Tree;

Tree * newTree();
Data * insert(Tree *bst, Data data);
Data * insertNode(Node *node, Data data);
void sort(Tree *bst, Data *data);
Data * search(Tree * bst, Data value);
Node * searchNode(Node *node, Data data);
Node * newNode(Data data, Node * parent);
void sortTree(Node *node, Data *data, int *index);
int compare(Tree *tree, Tree *treeCopy);
int comparedTree(Node *, Node *);
Tree * clone(Tree *tree);
void delete(Tree * bst);
void removeData(Tree * bst, Data data);
void Traversal(Node *node, Data *data, int *index);
Node * cloneNode(Node *originalNode, Node *node1, Node *parentNode);
void removeLeaf(Node * leaf);
void shortCircuit(Node *node);
Node * searchMax(Node *node);
void promotion(Node *node);
void deleteTree(Node *node);

#endif
