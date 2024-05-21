// Data Structures.cpp
// A section of common data sturctures and common methods to modify them
// - Linked List
// - Doubly Linked List
// - Binary Tree
// - Binary Search Tree
// 07/25/2023

#include <iostream>
#include <queue>
#include <format>
using namespace std;

// Helper function to display True or False from boolean result
void printBool(bool (func)) {
	if (func)
		cout << "True\n";
	cout << "False\n";
}

struct Array {
	int arr[5] = { 1,2,3,4,5 };
	int N = sizeof(arr) / sizeof(arr[0]);

	void traverseArray(int arr[], int N) {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << ' ';
		}
	}
};

// Singly Linked List Node
struct ListNode {
	int data;
	struct ListNode* next; // pointer to the next Node in the list
};

// A list type just needs to keep track of the head of the list
struct List {
	struct ListNode* head;

	// Traversing Linked List
	void printList(ListNode* head) {
		ListNode* current = head;		// Creates a new pointer "current" as head
		while (current != NULL) {			// Loops until current is not NULL
			printf("%d->", current->data);	// Print current data
			current = current->next;		// next is now current
		}
		printf("NULL\n");
	}

	// Searching a Linked List
	// Checks whether the value x is present in linked list 
	bool search(ListNode* head, int x) {
		ListNode* current = head;	// Initialize current
		while (current != NULL) {	// Traverse Linked List
			if (current->data == x)	// if data is not x continue down list
				return true;
			current = current->next;
		}
		return false;
	}

	// Reverse the linked list
	void reverse(ListNode** head) { //Time Complexity : O(N) - Auxiliary Space : O(1)
		ListNode* current = *head;	// Initialize current, previous and next pointers
		ListNode* prev = NULL, * next = NULL;

		while (current != NULL) {
			next = current->next;	// Store next
			current->next = prev;	// Reverse current node's pointer
			prev = current;			// Move pointers one position ahead
			current = next;
		}
		*head = prev;
	}

	// Push new node to the front of the Linked List
	void push(ListNode** head, int new_data) { // Time Complexity: O(1) - Auxiliary Space: O(1)
		ListNode* new_node = new ListNode(); // Allocate node
		new_node->data = new_data;			// Put in the data
		new_node->next = (*head);			// Make next of new node as head
		(*head) = new_node;					// Move the head to point to the new node
	}

	// Insert new node after selected node
	void insertAfter(ListNode* prev, int new_data) { // Time Complexity: O(1) - Auxiliary Space: O(1)
		if (prev == NULL) { // Check if the given prev_node is NULL
			cout << "The given previous node cannot be NULL";
			return;
		}
		ListNode* new_node = new ListNode(); // Allocate new node
		new_node->data = new_data;			// Put in the data
		new_node->next = prev->next;		// Make next of new node as next of prev
		prev->next = new_node;				// move the next of prev as new_node
	}

	// Insert new node at the end of the Linked List
	void append(ListNode** head, int new_data) { // Time Complexity: O(N) - Auxiliary Space: O(1)
		ListNode* new_node = new ListNode(); // Allocate node
		ListNode* last = *head;				// Last equals head
		new_node->data = new_data;			// Put in the data
		new_node->next = NULL;				// This new node is going to be last so save as NULL
		if (*head == NULL) {				// If the Linked List is empty then make the new node as head
			*head = new_node;
			return;
		}
		while (last->next != NULL) {		// Else traverse till the last node
			last = last->next;
		}
		last->next = new_node;				// Change the next of last node
		return;
	}

	// Finding length a Linked List
	int getLength(ListNode* head) { // Time complexity: O(N) - Auxiliary Space: O(1)
		int count = 0;				// Initialize count
		ListNode* current = head;	// Initialize current
		while (current != NULL) {	// Loop to end
			count++;				// Count each interation
			current = current->next;// traverse Linked List
		}
		return count;
	}

	// Deleting a Linked List
	// Head deletion
	ListNode* deleteHead(ListNode* head) { // Time complexity: O(1) - Auxiliary Space : O(1)
		if (head == NULL) {
			return NULL;
		}
		ListNode* temp = head;		// temp holds current head
		head = head->next;			// Point head to the next node (second node)
		free(temp);					// delete prev head
		return head;
	}

	// Delete from end
	void deleteEnd(ListNode** head) { // Time complexity: O(N) - Auxiliary Space : O(1)
		if (head == NULL) {
			return;
		}
		ListNode* end = *head;		// End equals head
		ListNode* prev = NULL;		// Prev is now NULL
		while (end->next){			// Traverse List to 2nd last 
			prev = end;				// Prev is now end
			end = end->next;		// Point end to next element
		}
		prev->next = NULL;			// Prev is now the new last element
		free(end);					// Drop the original last element
	}

	// Delete from N Position
	void deleteN(ListNode** head, int position) {
		ListNode* temp;							// Create two pointers
		ListNode* prev;
		temp = *head;							// Have them both become new head
		prev = *head;
		for (int i = 0; i < position; i++) {	// Traverse Link List until reached position
			if (i == 0 && position == 1) {		// if position is 1 free head
				*head = (*head)->next;
				free(temp);
			}
			else {								
				if (i == position - 1 && temp) { // When you traverse to the node before picked position 
					prev->next = temp->next;	 // prev next takes value of next 
					free(temp);					 // Delete temp which equals position
				}
				else {
					prev = temp;

					// Position was greater than
					// number of nodes in the list
					if (prev == NULL)
						break;
					temp = temp->next;
				}
			}
		}
	}

	// Delete whole Linked List from beginning
	void deleteList(ListNode** head)
	{
		ListNode* current = *head;	// create current to be head
		ListNode* next = NULL;		
		while (current != NULL){	// Traverse list to end
			next = current->next;	// Capture next ListNode
			free(current);			// Delete current
			current = next;			// Current is now the next ListNode
		}
		*head = NULL;				// Head is now NULL
	}
	
	// Is Linked List a Cycle - no NULL
	// Time: O(n) Space: O(1)
	bool hasCycle(ListNode *head) {
		ListNode *fast = head;		// Making two pointers fast and slow
		ListNode* slow = head;		// Assigning both to head
		
		while(fast != NULL && fast->next != NULL){ // Loop Linked List until NULL
			fast = fast->next->next;		// fast moves 2x
            slow = slow->next;				// slow moves 1x
			
			if (fast == slow)		// if no NULL, fast eventually will equal slow (overlap)
				return true;		// Stops loop
		}
		return false;		// if traversal reaches NULL there is no cycle
	}
};

// Doubly Linked List
struct DoublyListNode {
	int data;
	struct DoublyListNode* next; // pointer to the next Node in the list
	struct DoublyListNode* prev; // pointer to the prev Node in the list
};

// A list type just needs to keep track of the head of the list
struct DoubleList {
	struct DoublyListNode* head;
};


// Binary Tree
struct TreeNode {
	int data;
	struct TreeNode *left, *right;

	TreeNode* createNode(int data) {
		TreeNode* newNode = new TreeNode;
		if (!newNode) {
			cout << "Memory error\n";
			return NULL;
		}
		newNode->data = data;
		newNode->left = newNode->right = NULL;
		return newNode;
	}

	// Depth First Search - DFS
	// Time: O(n) Space: O(log n)
	void printInorder(TreeNode* node) {
		if (node == NULL) {
			return;
		}
		// First recur on left child
		printInorder(node->left);
		// Then print the data of node (root)
		cout << node->data << " ";
		// Now recur on right child
		printInorder(node->right);
	}

	void printPreorder(TreeNode* node) {
		if (node == NULL) {
			return;
		}
		// Then print the data of node (root)
		cout << node->data << " ";
		// First recur on left child
		printPreorder(node->left);
		// Now recur on right child
		printPreorder(node->right);
	}

	void printPostorder(TreeNode* node) {
		if (node == NULL) {
			return;
		}
		// First recur on left child
		printPostorder(node->left);
		// Now recur on right child
		printPostorder(node->right);
		// Then print the data of node (root)
		cout << node->data << " ";
	}

	// Breath First Search
	// Time: O(n^2) Space: O(n)
	void printLevelOrder(TreeNode* root) {
		// Base Case
		if (root == NULL)
			return;

		// Create an empty queue for level order traversal
		queue<TreeNode*> q;

		// Enqueue Root and initialize height
		q.push(root);

		while (q.empty() == false) {

			// Print front of queue and remove it from queue
			TreeNode* node = q.front();
			cout << node->data << " ";
			q.pop();

			// Enqueue left child
			if (node->left != NULL)
				q.push(node->left);

			// Enqueue right child
			if (node->right != NULL)
				q.push(node->right);
		}
	}
};

// Binary Search Tree
struct BST {
	int data;
	struct BST *left, *right;

public:
	// Default constructor.
	BST()
		:data(0)
		, left(NULL)
		, right(NULL)
	{}
	// Parameterized constructor.
	BST(int value) {
		data = value;
		left = right = NULL;
	}

	// Insert function
	// Time: O(n) Space: O(1)
	BST* insert(BST *root, int value) {
		if (!root) {
			// Insert the first node, if root is NULL.
			return new BST(value);
		}

		// Insert data.
		if (value > root->data) {
			// Insert right node data, if the 'value'
			// to be inserted is greater than 'root' node data.
			// Process right nodes.
			root->right = insert(root->right, value);
		}
		else if (value < root->data) {
			// Insert left node data, if the 'value'
			// to be inserted is smaller than 'root' node data.
			// Process left nodes.
			root->left = insert(root->left, value);
		}
		// Return 'root' node, after insertion.
		return root;
	}

	// Search BST
	// Time: O(h) Space: O(h) | h = height of BST
	BST* search(BST *root, int key)
	{
		// Base Cases: root is null or key is present at root
		if (root == NULL || root->data == key)
			return root;

		// Key is greater than root's key
		if (root->data < key)
			return search(root->right, key);

		// Key is smaller than root's key
		return search(root->left, key);
	}

	// Delete BST
	// Time: O(h) Space: O(n) | h = height of BST
	BST* deleteNode(BST *root, int k)
	{
		// Base case
		if (root == NULL)
			return root;

		// Recursive calls for ancestors of node to be deleted
		if (root->data > k) {
			root->left = deleteNode(root->left, k);
			return root;
		}
		else if (root->data < k) {
			root->right = deleteNode(root->right, k);
			return root;
		}

		// We reach here when root is the node to be deleted.
		// If one of the children is empty
		if (root->left == NULL) {
			BST* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL) {
			BST* temp = root->left;
			delete root;
			return temp;
		}

		// If both children exist
		else {
			BST* succParent = root;
			// Find successor
			BST* succ = root->right;
			while (succ->left != NULL) {
				succParent = succ;
				succ = succ->left;
			}
			// Delete successor.  Since successor is always left child of its parent
			// we can safely make successor's right child as left of its parent.
			// If there is no succ, then assign succ->right to succParent->right
			if (succParent != root)
				succParent->left = succ->right;
			else
				succParent->right = succ->right;
			// Copy Successor Data to root
			root->data = succ->data;
			// Delete Successor and return root
			delete succ;
			return root;
		}
	}
	// Inorder traversal.
	void Inorder(BST* root) {
		if (!root) {
			return;
		}
		Inorder(root->left);
		cout << root->data << " ";
		Inorder(root->right);
	}
};


int main()
{
	/* Start with the empty list */
	List ll;
	ListNode* head = NULL;

	// Push Test
	ll.push(&head,20);
	ll.push(&head,4);
	ll.push(&head,15);
	ll.push(&head,85);

	cout << "Given linked list:\n";
	ll.printList(head);
	
	// Reverse Test
	ll.reverse(&head);

	cout << "\nReversed linked list:\n";
	ll.printList(head);
	
	// Search Test
	cout << "\nIs value (4) in current Linked List:\n";
	if (ll.search(head, 4)) {
		cout << "True\n";
	}
	else {
		cout << "False\n";
	}

	// Insert After
	ll.insertAfter(head, 12);
	cout << "\nInsert after head in linked list \n";
	ll.printList(head);

	// Insert at the end Append
	ll.append(&head, 99);
	cout << "\nInsert at the end of the linked list: \n";
	ll.printList(head);

	// Get Length of Linked List
	cout << "\nLength of linked list: " << ll.getLength(head) << endl;

	// Delete Head of Linked List
	head = ll.deleteHead(head);
	cout << "\nLinked List after head was deleted:\n";
	ll.printList(head);

	// Delete from end of Linked List
	ll.deleteEnd(&head);
	cout << "\nLinked List after end was deleted:\n";
	ll.printList(head);

	// Delete position n from end of Linked List
	ll.deleteN(&head,2);
	cout << "\nLinked List after Postion 2 was deleted:\n";
	ll.printList(head);

	// Delete whole Linked List
	ll.deleteList(&head);
	cout << "\nLinked List after deletion:\n";
	ll.printList(head);

	// Is Linked List a Cycle
	ll.hasCycle(head);
	cout << "\nLinked a cycle?\n";
	printBool(ll.hasCycle(head));
	///////////////////////////////////////////////////////////////////////

	// Create Binary Tree
	TreeNode tn;
	TreeNode* root = tn.createNode(1);
	root->left = tn.createNode(2);
	root->right = tn.createNode(3);
	root->left->left = tn.createNode(4);
	root->left->right = tn.createNode(5);

	// Print Tree InOrder
	cout << "\nDFS Inorder traversal of binary tree is: \n";
	tn.printInorder(root);
	cout << endl;

	// Print Tree Preorder
	cout << "\nDFS Preorder traversal of binary tree is: \n";
	tn.printPreorder(root);
	cout << endl;

	// Print Tree Postorder
	cout << "\nDFS Postorder traversal of binary tree is: \n";
	tn.printPostorder(root);
	cout << endl;

	// Print Tree BFS (LevelOrder)
	cout << "\nBFS LevelOrder traversal of binary tree is: \n";
	tn.printLevelOrder(root);
	cout << endl;
	///////////////////////////////////////////////////////////////////////

	// Create Binary Search Tree (BST)
	BST bs;
	BST* bst_root = NULL;
	bst_root = bs.insert(bst_root, 50);
	bs.insert(bst_root, 30);
	bs.insert(bst_root, 20);
	bs.insert(bst_root, 40);
	bs.insert(bst_root, 70);
	bs.insert(bst_root, 60);
	bs.insert(bst_root, 80);

	// Print Binary Search Tree Inorder
	cout << "\nInorder traversal of Binary Search Tree is: \n";
	bs.Inorder(bst_root);

	// Searching BST
	int key = 20;
	cout << format("\n\nSearching for {} in BST:", key);
	
	if (bs.search(bst_root, key) == NULL)
		cout << endl << key << " not found" << endl;
	else
		cout << endl << key << " found" << endl;

	// Delete key in BST
	cout << format("\nDeleted {} in BST", key);
	bs.deleteNode(bst_root, 20);
	cout << "\nBinary Search Tree after deletion: \n";
	bs.Inorder(bst_root);
	cout << endl;

	return 0;

}

