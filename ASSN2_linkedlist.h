// A class template for holding a linked list. 
// The node type is also a class template. 
//#ifndef LINKEDLIST_H 
//#define LINKEDLIST_H 
#include <iostream> 
using namespace std; 
 
 
//********************************************* 
// The ListNode class creates a type used to  * 
// store a node of the linked list.           * 
//********************************************* 
 
template <class T> 
class ListNode 
{ 
	public:    
		T value;           // Node value    
		ListNode<T> *next; // Pointer to the next node 
 
   		// Constructor    
		ListNode (T nodeValue)       
		{ 
			value = nodeValue;         
			next = NULL;
		} 
}; 
 
//********************************************* 
// LinkedList class                           * 
//********************************************* 
 
template <class T> 
class LinkedList 
{ 
	private:    
		ListNode<T> *head;   // List head pointer    
	public:    
		// Constructor    
		LinkedList()       
		{ 
			head = NULL; 
		}
		           
		// Destructor    
		~LinkedList();           
		
		// Linked list operations    
		void appendNode(T); //to add node     
		void insertNode(T, T); //to insert node  
   		void deleteNode(T); //to delete node     
		void displayList() const; //to display all nodes 
		void searchData(T, int &) ; //to display all nodes 
}; 
 
 
//************************************************** 
// appendNode appends a node containing the value  * 
// pased into newValue, to the end of the list.    * 
//************************************************** 
 
template <class T> 
void LinkedList<T>::appendNode(T newValue) 
{    
	ListNode<T> *newNode;  // To point to a new node    
	ListNode<T> *nodePtr;  // To move through the list 
 
   	// Allocate a new node and store newValue there.    
	newNode = new ListNode<T>(newValue); 
 
   	// If there are no nodes in the list    
	// make newNode the first node.    
	if (!head)       
		head = newNode;    
	else // Otherwise, insert newNode at end.    
	{       
		// Initialize nodePtr to head of list.       
		nodePtr = head; 
 
      	// Find the last node in the list.       
		while (nodePtr->next)          
		nodePtr = nodePtr->next; 
 
      	// Insert newNode as the last node.       
		nodePtr->next = newNode;    
	} 
} 
 
//************************************************** 
// displayList shows the value stored in each node * 
// of the linked list pointed to by head.          * 
//************************************************** 
 
template <class T> 
void LinkedList<T>::displayList() const 
{    
	ListNode<T> *nodePtr;  // To move through the list 
 	int i = 1;
 	
   // Position nodePtr at the head of the list.    
   nodePtr = head; 
 
   // While nodePtr points to a node, traverse    
   // the list.    
   while (nodePtr)    
   {       
   	// Display the value in this node.          
	cout << "\t\t" << i << ". " << nodePtr->value << endl;        
	// Move to the next node.       
	nodePtr = nodePtr->next;
	i++;   
	} 
} 
 
 
//************************************************** 
// The insertNode function inserts a node with     * 
// newValue copied to its value member.            * 
//************************************************** 
 
template <class T> 
void LinkedList<T>::insertNode(T newValue, T Value) 
{    
	ListNode<T> *newNode;    // A new node    
	ListNode<T> *nodePtr;    // To traverse the list    
	ListNode<T> *previousNode = NULL; // The previous node 
 
   	// Allocate a new node and store newValue there.    
	newNode = new ListNode<T>(newValue);        
	
	// Position nodePtr at the head of list.       
	nodePtr = head; 
 
   	// Initialize previousNode to NULL.       
 	previousNode = NULL; 
 
   	// Skip all nodes whose value is less than newValue.       
	while (nodePtr != NULL && nodePtr->value != Value) 
    {            
	  	previousNode = nodePtr;          
		nodePtr = nodePtr->next;       
	} 
 
    // If the new node is to be the 1st in the list,       
	// insert it before all other nodes.       
	if (nodePtr)       
	{    
		previousNode = nodePtr;
		nodePtr = nodePtr->next;         
		previousNode->next = newNode;
		newNode->next = nodePtr;       
	} 
} 

 
//***************************************************** 
// The deleteNode function searches for a node        * 
// with searchValue as its value. The node, if found, * 
// is deleted from the list and from memory.          * 
//***************************************************** 
 
template <class T> 
void LinkedList<T>::deleteNode(T searchValue) 
{    
	ListNode<T> *nodePtr;       // To traverse the list    
	ListNode<T> *previousNode;  // To point to the previous node 
 
   	// If the list is empty, do nothing.    
	if (!head)       
	cout <<"List is Empty\n";            
	
	else    
	{       
		// Initialize nodePtr to head of list       
		nodePtr = head; 

       	// Skip all nodes whose value member is        
		// not equal to num.       
		while (nodePtr != NULL && nodePtr->value != searchValue)       
		{            
			previousNode = nodePtr;          
			nodePtr = nodePtr->next;       
		}
		
		if (nodePtr == head)
		{
			head = nodePtr->next;
			delete nodePtr;   
 		}
      	// If nodePtr is not at the end of the list,        
		// link the previous node to the node after       
		// nodePtr, then delete nodePtr.       
		else if (nodePtr)       
		{          
			previousNode->next = nodePtr->next;          
			delete nodePtr;       
		}    
	} 
} 
 
 
//************************************************** 
// Destructor                                      * 
// This function deletes every node in the list.   * 
//************************************************** 
 
template <class T> 
LinkedList<T>::~LinkedList() 
{    
	ListNode<T> *nodePtr;   // To traverse the list    
	ListNode<T> *nextNode;  // To point to the next node 
 
   	// Position nodePtr at the head of the list.    
	nodePtr = head; 
 
   	// While nodePtr is not at the end of the list...    
	while (nodePtr != NULL)    
	{       
		// Save a pointer to the next node.       
		nextNode = nodePtr->next; 
 
      	// Delete the current node.       
		delete nodePtr; 
 
      	// Position nodePtr at the next node.       
		nodePtr = nextNode;    
	} 
} 


//************************************************** 
// searchData shows the value stored in list       * 
//************************************************** 
 
template <class T> 
void LinkedList<T>::searchData(T searchValue, int &b) 
{    
	ListNode<T> *nodePtr;       // To traverse the list    
	ListNode<T> *previousNode;  // To point to the previous node 
 
   	// If the list is empty, do nothing.    
	if (!head)       
	cout <<"List is Empty\n";        

	else
	{       
		// Initialize nodePtr to head of list       
		nodePtr = head; 

       	// Skip all nodes whose value member is        
		// not equal to num.       
		while (nodePtr != NULL && nodePtr->value != searchValue)       
		{            
			previousNode = nodePtr;          
			nodePtr = nodePtr->next;       
		} 
 
      	// If nodePtr is not at the end of the list,        
		// link the previous node to the node after       
		// nodePtr, then delete nodePtr.       
		if (nodePtr)       
		{   
			system("cls");       
//			cout << "\n\n\n\n\t\tWord searched = " << nodePtr->value << "\n\n"; 
			b = 1;   
		}
		  
		else
		cout << "\n\n\t\tThis word is unavailable in data...\n";  
	} 
} 

//#endif 
