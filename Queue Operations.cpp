// C or C++ program for insertion and
// deletion in Circular Queue
// Q.1. Create a circular queue
#include<iostream>
using namespace std;

class Queue
{
	// Initialize front and rear
	int rear, front;

	// Circular Queue
	int size;
	int *arr;
public:
	Queue(int s)
	{
	front = rear = -1;
	size = s;
	arr = new int[s];
	}

	void enQueue(int value);
	int deQueue();
	void displayQueue();
};


/* Function to create Circular queue */
void Queue::enQueue(int value)
{
	if ((front == 0 && rear == size-1) ||
			((rear+1) % size == front))
	{
		printf("\nQueue is Full");
		return;
	}

	else if (front == -1) /* Insert First Element */
	{
		front = rear = 0;
		arr[rear] = value;
	}

	else if (rear == size-1 && front != 0)
	{
		rear = 0;
		arr[rear] = value;
	}

	else
	{
		rear++;
		arr[rear] = value;
	}
}

// Function to delete element from Circular Queue
int Queue::deQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty");
		return INT_MIN;
	}

	int data = arr[front];
	arr[front] = -1;
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (front == size-1)
		front = 0;
	else
		front++;

	return data;
}

// Function displaying the elements
// of Circular Queue
void Queue::displayQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty");
		return;
	}
	printf("\nElements in Circular Queue are: ");
	if (rear >= front)
	{
		for (int i = front; i <= rear; i++)
			printf("%d ",arr[i]);
	}
	else
	{
		for (int i = front; i < size; i++)
			printf("%d ", arr[i]);

		for (int i = 0; i <= rear; i++)
			printf("%d ", arr[i]);
	}
}

/* Driver of the program */
int main()
{
	Queue q(5);

	// Inserting elements in Circular Queue
	q.enQueue(14);
	q.enQueue(22);
	q.enQueue(13);
	q.enQueue(-6);

	// Display elements present in Circular Queue
	q.displayQueue();

	// Deleting elements from Circular Queue
	printf("\nDeleted value = %d", q.deQueue());
	printf("\nDeleted value = %d", q.deQueue());

	q.displayQueue();

	q.enQueue(9);
	q.enQueue(20);
	q.enQueue(5);

	q.displayQueue();

	q.enQueue(20);
	return 0;
}

// Q.2. Implement queue using two stack
#include <iostream>
#include<stack>
using namespace std;

class Queue {
	public:
	stack<int> s1, s2;

	void enQueue(int x)
	{
		// Move all elements from s1 to s2
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}

		// Push item into s1
		s1.push(x);

		// Push everything back to s1
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}

	// Dequeue an item from the queue
	int deQueue()
	{
		// if first stack is empty
		if (s1.empty()) {
			return -1;
		}

		// Return top of s1
		int x = s1.top();
		s1.pop();
		return x;
	}
};

// Driver code
int main()
{
	Queue q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);

	cout << q.deQueue() << '\n';
	cout << q.deQueue() << '\n';
	cout << q.deQueue() << '\n';

	return 0;
}

// Q.3. Convert queue into priority queue
#include <iostream>
#include<queue>
using namespace std;

void frontelement(queue<int>& q, int qsize)
{
	// Base condition
	if (qsize <= 0)
		return;

	// Pop front element and push this last in a queue
	q.push(q.front());
	q.pop();

	// Recursive call for pushing element
	frontelement(q, qsize - 1);
}

// Function for inserting element in the queue
void insertelement(queue<int>& q, int val, int qsize)
{
	if (qsize == 0 || q.empty()) {
		q.push(val);
		return;
	}

	// If current element is greater than the element at the front
	else if (val >= q.front()) {

		// Call stack with front of queue
		q.push(val);

		// Recursive call for inserting a front element of the queue to the last
		frontelement(q, qsize);
	}
	else {

		// Push front element into last in a queue
		q.push(q.front());
		q.pop();

		// Recursive call for pushing elements in a queue
		insertelement(q, val, qsize - 1);
	}
}

// Function to sort queue
void sortqueue(queue<int>& q)
{
	if (q.empty()) {
		return;
	}
	int item = q.front();
	q.pop();
	sortqueue(q);
	insertelement(q, item, q.size());
}

// Driver Code
int main()
{
	queue<int> q;
	q.push(3);
	q.push(4);
	q.push(2);
	q.push(8);
	q.push(1);
	q.push(7);

	// Initially queue is 3 4 2 8 1 7
	sortqueue(q);

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	return 0;
}

// Q.4. Find the median of the elements in the queue
#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

class Queue {
  private:
    int front; // Front index of the queue
    int rear; // Rear index of the queue
    int arr[MAX_SIZE]; // Array to store elements

  public:
    Queue() {
      front = -1; // Initialize front index to -1
      rear = -1; // Initialize rear index to -1
    }

    bool isFull() {
      return (rear == MAX_SIZE - 1); // Check if the queue is full
    }

    bool isEmpty() {
      return (front == -1 && rear == -1); // Check if the queue is empty
    }

    void enqueue(int x) {
      if (isFull()) {
        cout << "Error: Queue is full" << endl; // Display error message if queue is full
        return;
      }
      if (isEmpty()) {
        front = 0;
        rear = 0;
      } else {
        rear++;
      }
      arr[rear] = x; // Insert the element at the rear index
    }

    void dequeue() {
      if (isEmpty()) {
        cout << "Error: Queue is empty" << endl; // Display error message if queue is empty
        return;
      }
      if (front == rear) {
        front = -1;
        rear = -1;
      } else {
        front++;
      }
    }

    int peek() {
      if (isEmpty()) {
        cout << "Error: Queue is empty" << endl; // Display error message if queue is empty
        return -1;
      }
      return arr[front]; // Return the element at the front of the queue
    }

    void display() {
      if (isEmpty()) {
        cout << "Error: Queue is empty" << endl; // Display error message if queue is empty
        return;
      }
      cout << "Queue elements are: ";
      for (int i = front; i <= rear; i++) {
        cout << arr[i] << " "; // Display all elements in the queue
      }
      cout << endl;
    }

    // Function to calculate the median of elements in the queue
    float median_Queue(Queue & q) {
      if (q.isEmpty()) {
        cout << "Error: Queue is empty" << endl; // Display error message if queue is empty
        return 0.0;
      }
      int count = 0;
      int mid = 0;
      for (int i = q.front; i <= q.rear; i++) {
        count++; // Count the number of elements
      }
      mid = count / 2; // Calculate the middle index

      if (count % 2 == 0) {
        // If the count is even, calculate the average of two middle elements
        float median = static_cast < float > (q.arr[q.front + mid] + q.arr[q.front + mid - 1]) / 2;
        return median;
      } else {
        // If the count is odd, return the middle element
        float median = q.arr[q.front + mid];
        return median;
      }
    }
};

int main() {
  cout << "Initialize a Queue." << endl;
  Queue q;
  cout << "\nInsert some elements into the queue:" << endl;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.display();

  // Calculate and display the median of elements in the queue
  float med_val = q.median_Queue(q);
  cout << "Find the median of all elements of the said queue: " << med_val;

  cout << "\n\nInput one more element into the queue:" << endl;
  q.enqueue(6);
  q.display();

  // Calculate and display the median of elements in the queue after adding a new element
  med_val = q.median_Queue(q);
  cout << "Find the median of all elements of the said queue: " << med_val;

  return 0;
}
