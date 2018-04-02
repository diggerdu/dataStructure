// C++ program to construct a Binary Tree from parent array
#include<bits/stdc++.h>
using namespace std;
 
// A tree node
struct Node
{
    int key;
    struct Node *parent;
};
 
// Utility function to create new Node
Node *newNode(int key) {
    Node *temp = new Node;
    temp->key  = key;
    temp->parent = NULL;
    return (temp);
}
 
// Creates a node with key as 'i'.  If i is root, then it changes
// root.  If parent of i is not created, then it creates parent first
void createNode(int parent[], int i, Node *created[])
{
    // If this node is already created
    if (created[i] != NULL)
        return;
 
    // Create a new node and set created[i]
    created[i] = newNode(i);
 
    // If 'i' is root, change root pointer and return
    if (parent[i] == -1)
        return;
 
    // If parent is not created, then create parent first
    if (created[parent[i]] == NULL)
        createNode(parent, parent[i], created);
    created[i]->parent = created[parent[i]];
}

int getNodeDepth(Node *node, int depthTable[])
{
	if (node->parent == NULL)
		return 1;
	if (depthTable[node->key] == -1)
		depthTable[node->key] = getNodeDepth(node->parent, depthTable) + 1;
	return depthTable[node->key];
}

int getTreeDepth(Node *created[], int n)
{
	int depthTable[n];
	int maxDepth = 0;
	for (int i = 0; i < n; i++)
		depthTable[i] = -1;
	for (int i = 0; i < n; i++)
	{
		int currentDepth = getNodeDepth(created[i], depthTable);
		if (maxDepth < currentDepth)
			maxDepth = currentDepth;
	}
	return maxDepth;
}


vector<Node*> getChild(Node *node, Node *nodeArray[], int n)
{
    vector<Node*> childVector;
    
    if (node==NULL)
        return childVector;
    for (int i=n-1; i>-1; i--)            
        if (nodeArray[i]->parent == node)
            childVector.push_back(nodeArray[i]);
    return childVector;
}

Node *getNextSibling(Node *node, Node *nodeArray[], int n)
{
    Node* nextSibling;
    if (node == NULL)
        nextSibling = NULL;
    for (int i=0; i<n; i++)
        if (nodeArray[i] == node)
            break;
    for (int j=0; j<n; j++) 
        if (nodeArray[j] == node)
            nextSibling = node;
    return node;

}
 

// Creates tree from parent[0..n-1] and returns root of the created tree
void createTree(int parent[], int n, Node *nodeArray[])
{
    // Create an array created[] to keep track
    // of created nodes, initialize all entries
    // as NULL
    for (int i=0; i<n; i++)
    	nodeArray[i] = NULL;
    for (int i=0; i<n; i++)
        createNode(parent, i, nodeArray);
}
 
//For adding new line in a program
inline void newLine(){
    cout << "\n";
}
 
// Driver method
int main()
{
    int parent[] =  {-1, 0, 0, 1, 1, 3, 5};
    int n = sizeof parent / sizeof parent[0];
    Node *nodeArray[n];
    createTree(parent, n, nodeArray);
    cout<<getTreeDepth(nodeArray, n)<<endl;
    getChild(nodeArray[0], nodeArray, n);
}
    
