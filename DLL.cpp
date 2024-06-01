#include<iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next, *prev;
};

class DoublyLinkedList
{
private:
  Node * head;
public:
  DoublyLinkedList ()
  {				// constructor
    head = NULL;
  }
  int countItems ();
  void insertStart (int data);
  void insertLast (int data);
  void insertAfter (int pos, int data);
  void deleteStart ();
  void deleteLast ();
  void deleteNthNode (int pos);
  void display ();
};

void DoublyLinkedList::insertStart (int data)
{
  Node *new_node = new Node ();

  new_node->data = data;
  new_node->next = head;
  new_node->prev = NULL;

  // if DLL had already >=1 nodes
  if (head != NULL)
    head->prev = new_node;

  // changing head to this
  head = new_node;
}

void DoublyLinkedList::insertLast (int data)
{
  Node *new_node = new Node ();

  // assign data
  // since this will be the last node its next will be NULL
  new_node->data = data;
  new_node->next = NULL;

  //if we are entering the first node
  if (head == NULL)
    {
      head = new_node;
      new_node->prev = NULL;
      return;
    }

  Node *last = head;

  // traverse to the current last node
  while (last->next != NULL)
    last = last->next;

  // assign current last node's next to this new node
  last->next = new_node;
  new_node->prev = last;

  // new_node becomes the last node now
}

void DoublyLinkedList::insertAfter (int n, int data)
{
  int len = countItems ();

  // if insertion position is 0 means entering at start
  if (n == 0)
    {
      insertStart (data);
      return;
    }
  // means inserting after last item
  if (n == len)
    {
      insertLast (data);
      return;
    }

  // else insertion will happen somewhere in the middle


  if (n < 1 || len < n)
    cout << "Invalid position" << endl; else { Node *new_node = new Node (); new_node->data = data;
      new_node->next = NULL;
      new_node->prev = NULL;

      // nthNode used to traverse the Linked List
      Node *nthNode = head;

      // traverse till the nth node
      while (--n)
	{
	  nthNode = nthNode->next;
	}

      Node *nextNode = nthNode->next;	// (n+1)th node

      // assigning (n+1)th node's previous to this new node
      nextNode->prev = new_node;

      // new_node's next assigned to (n+1)th node
      new_node->next = nextNode;
      // new_node's previous assigned to nth node
      new_node->prev = nthNode;

      // assign nth node's next to new_node
      nthNode->next = new_node;
    }
}

int DoublyLinkedList::countItems ()
{

  Node *node = new Node ();
  node = head;

  int items = 0;

  while (node != NULL)
    {
      node = node->next;
      items++;
    }
  return items;
}

void DoublyLinkedList::deleteStart ()
{

  Node *temp = head;

  // if DLL is empty
  if (head == NULL)
    {
      cout << "Linked List Empty, nothing to delete\n";
      return;
    }

  // if Linked List has only 1 node 
  if (temp->next == NULL)
    {
      cout << temp->data << " deleted\n";
      head = NULL;
      return;
    }

  // move head to next node 
  head = head->next;
  // assign head node's previous to NULL
  head->prev = NULL;

  cout << temp->data << " deleted\n";
  delete temp;
}

void DoublyLinkedList::deleteLast ()
{

  Node *temp = head;

  // if DLL is empty
  if (head == NULL)
    {
      cout << ("DLL empty can't delete\n");
      return;
    }

  // if Linked List has only 1 node 
  if (temp->next == NULL)
    {
      cout << temp->data << " deleted\n";
      head = NULL;
      return;
    }				// else traverse to the last node 

  while (temp->next != NULL)
    temp = temp->next;

  Node *secondLast = temp->prev;

  // Curr assign 2nd last node's next to Null
  secondLast->next = NULL;

  cout << temp->data << " deleted\n";
  delete temp;
}

void DoublyLinkedList::deleteNthNode (int n)
{
  //if the head node itself needs to be deleted
  int len = countItems ();

  // not valid
  if (n < 1 || n > len)
    {
      cout << "Not a valid position\n";
      return;
    }

  // delete the first node 
  if (n == 1)
    {
      deleteStart ();
      return;
    }

  if (n == len)
    {
      deleteLast ();
      return;
    }

  Node *temp = head;

  // traverse to the nth node 
  while (--n)
    {
      temp = temp->next;
    }

  Node *previousNode = temp->prev;	// (n-1)th node
  Node *nextNode = temp->next;	// (n+1)th node

  // assigning (n-1)th node's next pointer to (n+1)th node
  previousNode->next = temp->next;

  // assigning (n+1)th node's previous pointer to (n-1)th node
  nextNode->prev = temp->prev;

  // deleting nth node
  cout << temp->data << " deleted\n";
  delete temp;
}

void DoublyLinkedList::display ()
{
  Node *node = head;
  Node *end = NULL;

  cout << "Reading DLL Forward: ";
  while (node != NULL)
    {
      cout << node->data << " "; end = node; node = node->next;
    }

  cout << "\nReading DLL Backward: ";

  while (end != NULL)
    {
      cout << end->data << " "; end = end->prev;
    }
  cout << "\n\n"; } 
  int main () 
  { 
  DoublyLinkedList *dll = new DoublyLinkedList (); 
  dll->insertStart (6);
  dll->insertStart (4);
  dll->insertStart (2);

  dll->display ();

  dll->insertLast (8);
  dll->insertLast (12);
  dll->insertLast (14);
  dll->display ();


  // delete 3rd node
  dll->insertAfter (3, 10);
  dll->display ();
  
  dll->deleteStart ();
  dll->display ();

  dll->deleteLast ();
  dll->display ();

  // delete 3rd node
  dll->deleteNthNode (3);
  dll->display ();

  // delete 2nd node
  dll->deleteNthNode (2);
  dll->display ();

  // delete 1st node
  dll->deleteLast ();
  dll->display ();

  // delete 1st node
  dll->deleteStart ();
  dll->display ();


  return 0;
}
