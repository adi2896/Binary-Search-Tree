#ifndef bst_h
#define bst_h

typedef struct data
{
	int value;
}Data;

typedef struct node
{
	Data data;
	struct node * left;
	struct node * right;
	struct node * parent;
}Node;

typedef struct Tree
{
	Node * root;
	Data * (*insert)(struct Tree *, Data);
	Data * (*search)(struct Tree * bst, Data value);
	void (*sort)(struct Tree *, Data *);
	int (*compare)(struct Tree *t, struct Tree * copy);
	struct Tree * (*clone)(struct Tree *t);
	void (*delete)(struct Tree * bst);
	void (*removeData)(struct Tree * bst, Data value);
}Tree;

Node * newNode(Data, Node *);

Tree * newTree();

Data * insert(Tree *, Data);

Data * insertNode(Node *, Data);

void sort(Tree *, Data *);

int sortAux(Node *, Data *, int );

Data * search(Tree *, Data);

Node * searchTree(Tree *, Data);

Node * searchNode(Node *, Data);

Tree * clone(Tree *);

Tree * traversen(Node *, Tree *);

int compare(Tree *, Tree *);

int compared(Node *, Node *);

void removeData(Tree *, Data);

void removeLeaf(Tree *, Node *);

void shortCircuit(Tree *, Node *);

void promotion(Tree *, Node *);

void deleteTree(Tree *);

void deleteData(Tree *, Node *);

void inorder(Tree *, Node *);

#endif