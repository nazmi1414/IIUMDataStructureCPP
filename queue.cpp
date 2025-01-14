// A CPP program to demonstrate linked list 
// based implementation of queue 
#include <bits/stdc++.h> 
using namespace std; 

// A linked list (LL) node to store a queue entry 
class QNode { 
public: 
	int key; 
	QNode* next; 
}; 

// The queue, front stores the front node 
// of LL and rear stores the last node of LL 
class Queue { 
public: 
	QNode *front, *rear; 
}; 

// A utility function to create 
// a new linked list node. 
QNode* newNode(int k) 
{ 
	QNode* temp = new QNode(); 
	temp->key = k; 
	temp->next = NULL; 
	return temp; 
} 

// A utility function to create an empty queue 
Queue* createQueue() 
{ 
	Queue* q = new Queue(); 
	q->front = q->rear = NULL; 
	return q; 
} 

// The function to add a key k to q 
void enQueue(Queue* q, int k) 
{ 
	// Create a new LL node 
	QNode* temp = newNode(k); 

	// If queue is empty, then 
	// new node is front and rear both 
	if (q->rear == NULL) { 
		q->front = q->rear = temp; 
		return; 
	} 

	// Add the new node at 
	// the end of queue and change rear 
	q->rear->next = temp; 
	q->rear = temp; 
} 

// Function to remove 
// a key from given queue q 
QNode* deQueue(Queue* q) 
{ 
	// If queue is empty, return NULL. 
	if (q->front == NULL) 
		return NULL; 

	// Store previous front and 
	// move front one node ahead 
	QNode* temp = q->front; 
	q->front = q->front->next; 

	// If front becomes NULL, then 
	// change rear also as NULL 
	if (q->front == NULL) 
		q->rear = NULL; 
	return temp; 
} 

// Driver code 
int main() 
{ 
	Queue* q = createQueue(); 
	enQueue(q, 10); 
	enQueue(q, 20); 
	deQueue(q); 
	deQueue(q); 
	enQueue(q, 30); 
	enQueue(q, 40); 
	enQueue(q, 50); 
	QNode* n = deQueue(q); 
	if (n != NULL) 
		cout << "Dequeued item is " << n->key; 
	return 0; 
} 

