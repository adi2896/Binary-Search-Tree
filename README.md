# Binary-Search-Tree
CS580u Programming and System Tools
Fall 2018
PROGRAM 6 README FILE
KNOWN BUGS AND INCOMPLETE PARTS:
Your program must pass all tests to be accepted
REFERENCES:
*******
MISCELLANEOUS COMMENTS:
Anything you would like the grader to know
Assignment Description
Program 6 - Binary Search Trees
Due Date: 5:00 p.m., December 7th, 2018
All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.

Driver Code and Test Files
program6.c
include the driver code with your submission, but do not alter it
Grading Rubric
TOTAL: 30 points

Part A (13 points): Initialize, Insert, and Read
Test 1 - Initialize the BST (1 point)
Test 2 - Insert into the BST (1 point)
Test 3 - Insert Duplicates(1 point)
Test 4 - Sorted data (3 points)
Test 5 - Search data (2 points)
Test 6 - Search for Missing data (2 points)
Test 7 - Clone and Compare trees (3 points)
Part B (17 points): Deletion
Test 8 - Remove a value not found (1 points)
Test 9 - Remove Leaf (2 points)
Test 10 - Remove 1 child node (2 points)
Test 11 - Remove 2 child node with leaf (2 points)
Test 12 - Remove 2 child node with short circuit (2 points)
Test 13 - Remove 2 child root (2 points)
Test 14 - Remove 1 child root (2 points)
Test 15 - Remove Leaf root (1 points)
Test 16 - Clean up memory. Delete all trees (3 points)
Style Guidelines and Memory Leaks
You will lose significant points for the following:
Makefile does not have requested format and labels (-5 points)
Memory leak or error detected in valgrind (-10 points)
Does not follow requested program structure and submission format (-10 points)
Guidelines
This is an individual assignment. You must do the vast majority of the work on your own. It is permissible to consult with classmates to ask general questions about the assignment, to help discover and fix specific bugs, and to talk about high level approaches in general terms. It is not permissible to give or receive answers or solution details from fellow students.

You may research online for additional resources; however, you may not use code that was written specifically to solve the problem you have been given, and you may not have anyone else help you write the code or solve the problem. You may use code snippets found online, providing that they are appropriately and clearly cited, within your submitted code.

By submitting this assignment, you agree that you have followed the above guidelines regarding collaboration and research.

In this program, you will learn to:

Work with a Binary Search Tree
⚠️ For all Data Structures, you may (and probably should) add additional functions, methods, and attributes, but what follows is the required minimum interface

Part A: BST
Create a link based Binary Search tree composed of a Node and Tree struct. You should have a header file, bst.h, with the following:

Node struct containing left, right, and parent pointers, in addition to holding an Data struct value.
Tree struct containing a pointer to the root of the tree.
A function declaration for a function that allocates a tree, and initializes the root to NULL;
A function declaration for a function that takes a Data struct as a parameter, allocates a node, and initializes the left, right, parent fields to NULL.
You should also have a source file, bst.c, that implements the two declared functions:
Tree * newTree();
Node * newNode(Data d, Node * parent); Test your functions and structure to ensure everything is initialized correctly by creating a Tree and adding a root to it.
Below is the expected interface for your structs:

Data struct

value (int)
Node struct

data (Data)
left (Node *)
right (Node *)
parent (Node *)
Tree struct

root (Node *)
Data * (*insert)(Tree *, Data);
Data * (*search)(Tree * bst, Data value);
void (*sort)(Tree *, Data *);
int (*compare)(Tree *t, Tree * copy);
Tree * (*clone)(Tree *t);
void (*delete)(Tree * bst);
void (*removeData)(Tree * bst, Data value);
Your constructors should have the following interfaces:

Node * newNode(Data d, Node * parent);
Tree * newTree();
Part B: BST Operations
Implement the following operations in your BST.c file.

INSERT:
Data * (*insert)(Tree * bst, Data value) -> Inserts into the tree.

💡 Helpful Hints

Return a pointer to the Data value inserted into the tree
Make sure you check for the special case of an empty tree [if(bst->root == NULL)],
After checking for the root, use a separate helper function to insert a value into the tree, Data * insertNode(Node * node, Data value), that you can use for the recursive call
If the value is already in the tree, return NULL
SEARCH:
Data * (*search)(Tree * bst, Data value) -> Searches for a value in the tree. Return a pointer to the Data object if found.

💡 Helpful hints:

Make sure you check for the special case of an empty tree [if(bst->root == NULL)],
After checking for the root, use a separate helper function to search the tree, Node * searchNode(Node * node, Data value), that you can use for the recursive call
REMOVE:
void (*removeData)(Tree * bst, Data value) -> Removes a value from the tree

💡 Helpful hints:

Use your (hopefully) working search auxiliary function to find the node you need to delete
Your auxiliary search function can return a node pointer, and you primary search function returns the data from that pointer.
You will have 3 cases requiring 3 separate functions:
remove a leaf node : void removeLeaf(Tree * bst, Node * d_node)
remove a node with 1 branch: void shortCircuit(Tree * bst, Node * d_node)
remove a node with 2 branches: void promotion(Tree * bst, Node * d_node)
You will need to use your removeLeaf() and shortCircuit() functions in your promotion function, so make sure they are working before starting on the promotion function.
You will also need to implement the following:

Tree * (*clone)(Tree*): Takes a tree and uses preorder traversal algorithm to return a clone of the tree
int (*compare)(Tree*, Tree*): Takes a tree and uses preorder traversal algorithm to determine if the trees are equal
void (*sort)(Tree *, Data *): Takes a tree and a data array buffer as parameters, and fills the buffer with the tree data in sorted order using the inorder traversal algorithm.
void (*delete)(Tree * bst): Add a post-order deleteTree() function that deletes all nodes and the tree
💡 post order only deletes leafs, so you need only call deleteLeaf()
💡 Each of the above functions is easier to implement if you use an auxiliary recursive function
Part C: Submission
Required file naming and organization:
program6.c //Driver Code
bst.c/h
makefile
You must have the following labels in your makefile:
all - to compile all your code to an executable called ‘program4’ (no extension). Do not run.
run - to compile if necessary and run
memcheck - to compile only if necessary and run with valgrind
clean - to remove all executables and object files
⛔️ Every program will have a required submission guidelines. Please read submission requirements carefully. Any deviations from specifications will result in point deductions or incomplete grades.

README
KNOWN BUGS AND INCOMPLETE PARTS
REFERENCES
MISCELLANEOUS COMMENTS
Before your final submission, edit the content for each of these sections in this README for your program. You do not have to use markdown, but you can find out more about markdown here if you would like to.

Git
Below is a reminder of the commands you need to use to submit your program.

⚠️ You have created several files and even a folder for this program. Be sure you add them to the repo. If you forget to add the files to the repo, your assignment will be considered late or not accepted at all.

git status
git add mylib.h
git commit -a -m "commit message"
git push
To find your most recent commit hash, use the following command:

git rev-parse HEAD
To complete your submission, you must copy and paste this number into mycourses. Go to MyCourses, select cs580u, and Assignment Hash Submission.

⚠️ You MUST submit the commit hash on mycourses before the deadline to be considered on time even if your program is completely working before the deadline. ⚠️
