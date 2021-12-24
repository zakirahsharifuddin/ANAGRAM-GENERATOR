#ifndef DYNAMICQUEUE_H 
#define DYNAMICQUEUE_H 
#include <iostream> 

using namespace std; 

// Queue node template 
template <class T> 
class QueueNode 
{ 
	public: 
		T value; // Value in a node 
		QueueNode<T> *next; // Pointer to the next node 
	
		//constructor for creating a new node in queue 
		QueueNode(T nodeValue)
		{ 
			value = nodeValue; 
			next = NULL; 
		} 
};


// DynamicQueue template 
template <class T> 
class DynamicQueue 
{ 
	private: 
		QueueNode<T> *front;  // The front of the queue 
		QueueNode<T> *rear;   // The rear of the queue 
		int numItems;      // Number of items in the queue 
		
	public: 
		DynamicQueue(); // Constructor 
		~DynamicQueue(); // Destructor 
		
		// Queue operations 
		void enqueue(T); 
		
		// insert into queue 
		void dequeue(T &); 
		
		// remove from queue 
		bool isEmpty() const; 
		bool isFull() const; 
		void clear(); 
};


//******************************************** 
// The constructor creates an empty queue.   * 
//******************************************** 
template <class T> 
DynamicQueue<T>::DynamicQueue() 
{ 
	front = NULL; 
	rear = NULL; 
	numItems = 0; 
} 

//******************************************** 
// Destructor                                * 
//******************************************** 
template <class T> 
DynamicQueue<T>::~DynamicQueue() 
{ 
	clear(); 
}


// Function enqueue inserts the value item at the rear of the queue 
template <class T> 
void DynamicQueue<T>::enqueue(T item) 
{ 
	QueueNode<T> *newNode = NULL; 
	
	// Create a new node and store the new value there. 
	newNode = new QueueNode<T>(item); 
	
	// Adjust front and rear as necessary. 
	if (isEmpty()) 
	{ 
		front = newNode; 
		rear = newNode; 
	} 
	else 
	{ 
		rear->next = newNode; 
		rear = newNode; 
	} 
	
	numItems++; // Update numItems. 
} 



// Function dequeue removes the value at the front of the queue, 
// and copies it into item. 
template <class T> 
void DynamicQueue<T>::dequeue(T &item) 
{ 
	QueueNode<T> *temp = NULL; 
	
	if (isEmpty()) 
	{ 
		cout << "The queue is empty.\n"; 
	} 
	else 
	{ 
		// Save the front node value in item. 
		item = front->value; 
		
		// Remove the front node and delete it. 
		temp = front; 
		front = front->next; 
		delete temp; 
		
		// Update numItems. 
		numItems--; 
	} 
} 


// Function isEmpty returns true if the queue is empty, else false 
template <class T> 
bool DynamicQueue<T>::isEmpty() const 
{ 
	bool status; 
	if (numItems > 0) 
		status = false; 
	else 
		status = true; 
		
	return status; 
} 

// Function clear dequeues all the elements in the queue. 
template <class T> 
void DynamicQueue<T>::clear() 
{ 
	T value;   // Dummy variable for dequeue 
	
	while(!isEmpty()) 
	dequeue(value); 
} 

#endif 
