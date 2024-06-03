// Operations on Linked List

// 1. Sort the Linked List
//#include<iostream>
//using namespace std;
//
//class Node{
//	public:
//		int data;
//		Node* next;
//		Node(int val){
//			this->data = val;
//			this->next=NULL;
//		}
//};
//class Linkedlist { 
//	Node* head; 
//
//public: 
//	Linkedlist() { head = NULL; }
//	
//	void addNode(int data){
//		Node* newNode = new Node(data);  
//		if (head == NULL) { 
//			head = newNode; 
//			return; 
//		} 
//		Node* temp = head; 
//		while (temp->next != NULL) { 
//			temp = temp->next; 
//		} 
//		temp->next = newNode; 
//	}
//	void sortList() {  
//        //Node current will point to head  
//        Node *current = head, *index = NULL;  
//        int temp;  
//          
//        if(head == NULL) {  
//            return;  
//        }  
//        else {  
//            while(current != NULL) {  
//                //Node index will point to node next to current  
//                index = current->next;  
//                  
//                while(index != NULL) {  
//                    //If current node's data is greater than index's node data, swap the data between them  
//                    if(current->data > index->data) {  
//                        temp = current->data;  
//                        current->data = index->data;  
//                        index->data = temp;  
//                    }  
//                    index = index->next;  
//                }  
//                current = current->next;  
//            }      
//        }  
//    } 
//	 void display(){
//		Node* temp = head;  
//		if (head == NULL) { 
//			cout << "List empty" << endl; 
//			return; 
//		} 
//		while (temp != NULL) { 
//			cout << temp->data << " "; 
//			temp = temp->next; 
//		}
//	}
//};
//int main()  
//{  
//	Linkedlist ll;
//    //Adds data to the list  
//    ll.addNode(9);  
//    ll.addNode(7);  
//    ll.addNode(2);  
//    ll.addNode(5);  
//    ll.addNode(4);  
//      
//    //Displaying original list  
//    cout<<"Original list: \n";  
//    ll.display();  
//      
//    //Sorting list  
//    ll.sortList();  
//      
//    //Displaying sorted list  
//    cout<<"\nSorted list: \n";  
//    ll.display();  
//          
//    return 0;  
//}  

// 2. merge two sorted linked list
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(NULL) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(NULL) {}

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next!= NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    Node* mergeSortedLists(LinkedList& head1, LinkedList& head2) {
        Node *result = NULL;
   if (head1 == NULL) {
      return head2;
   }
   if (head2 == NULL) {
      return head1;
   }
   if (head1->data < head2->data) {
      result = head1;
      result->next = mergeSortedLists(head1->next, head2);
   } else {
      result = head2;
      result->next = mergeSortedLists(head1, head2->next);
   }
   return result;
}
	void display(){
		Node* temp = head;  
		if (head == NULL) { 
			cout << "List empty" << endl; 
			return; 
		} 
		while (temp != NULL) { 
			cout << temp->data << " "; 
			temp = temp->next; 
		}
	}
};
int main(){
	LinkedList ll1;
	Node* head1(10);
	Node* n1(20);
	head1->next=n1;
	Node* n2(30);
	n1->next=n2;
	
	Node* head2(1);
	Node* n3(2);
	head1->next=n3;
	Node* n4(3);
	n3->next=n4;
	
	ll1.mergeSortedLists(head1,head2);
	ll1.display();
}

// 3. Find middle of the linked list
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
    	data = x;
        next = NULL;
    }
};

class LL{
	Node* head = NULL;
	public:
	// Function to add a new node
	void pushNode(int data_val)
{
    // Allocate node
    Node* new_node = new Node(data_val);

    // Link the old list of the new node
    new_node->next = head;

    // move the head to point to the new node
    head = new_node;
}

// function to find the middle of the linked list
	int getMiddle()
	{
    Node* mid = head;
    int counter = 1;
    // Traverse over the entire linked list
    while (head) {
          // If counter is even, move the mid pointer to the
        // next node
        if (counter % 2 == 0) {
            mid = mid->next;
        }
        head = head->next;
        // Increment the counter for each node
        counter += 1;
    }
    return mid->data;
}	
};

int main()
{
    LL l;
    for (int i = 5; i > 0; i--) {
        l.pushNode(i);
    }
    cout << "Middle Value Of Linked List is: "
         << l.getMiddle() << endl;
    return 0;
}

// 4. Rotate the linked list

#include <iostream> 
using namespace std; 

class Node { 
public: 
	int data; 
	Node* next; 
}; 
class ll{
	Node* head = NULL;
	public:
	void rotate( int k) 
{ 
	if (k == 0) 
		return; 

	// Let us understand the below code for example k = 4 and list = 10->20->30->40->50->60. 
	Node* current = head; 

	// current will either point to kth or NULL after this loop. current will point to node 40 in the above example 
	int count = 1; 
	while (count < k && current != NULL) { 
		current = current->next; 
		count++; 
	} 

	// If current is NULL, k is greater than or equal to count of nodes in linked list. Don't change the list in this case 
	if (current == NULL) 
		return; 

	// current points to kth node. Store it in a variable. kthNode points to node 40 in the above example 
	Node* kthNode = current; 

	// current will point to last node after this loop current will point to node 60 in the above example 
	while (current->next != NULL) 
		current = current->next; 

	// Change next of last node to previous head Next of 60 is now changed to node 10 
	current->next = head; 

	// Change head to (k+1)th node head is now changed to node 50 
	head = kthNode->next; 

	// change next of kth node to NULL next of 40 is now NULL 
	kthNode->next = NULL; 
} 

	void push(int new_data) 
{ 
	/* allocate node */
	Node* new_node = new Node(); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list of the new node */
	new_node->next =head; 

	/* move the head to point to the new node */
	head = new_node; 
} 

void printList() 
{ 
	Node* temp = head;  
		if (head == NULL) { 
			cout << "List empty" << endl; 
			return; 
		} 
		while (temp != NULL) { 
			cout << temp->data << " "; 
			temp = temp->next; 
		}
} 

};  

int main() 
{ 
	/* Start with the empty list */
	ll l; 

	// create a list 10->20->30->40->50->60 
	for (int i = 60; i > 0; i -= 10) 
		l.push(i); 

	cout << "Given linked list \n"; 
	l.printList(); 
	l.rotate(4); 

	cout << "\nRotated Linked list \n"; 
	l.printList(); 

	return (0); 
} 

// 5. Reverse the linked list
#include <iostream>
using namespace std;

class Node {
	public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
	public:
    Node* head;
    
    LinkedList() { head = NULL; }

    Node* reverse(Node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        /* reverse the rest list and put the first element at the end */
        Node* rest = reverse(head->next);
        head->next->next = head;

        head->next = NULL;

        /* fix the head pointer */
        return rest;
    }

    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};
int main()
{
    /* Start with the empty list */
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(18);
    ll.push(85);
    ll.push(52);

    cout << "Given linked list\n";
    ll.print();

    ll.head = ll.reverse(ll.head);

    cout << "\nReversed linked list \n";
    ll.print();
    return 0;
}

