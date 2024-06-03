#include<iostream> 
using namespace std;

class QueueNode
{
 public: 
    int val;
    QueueNode *next;
    QueueNode(int data)
    {
       val = data;
       next = NULL;
    }
};  

class Queue
{
	QueueNode *Front = NULL, *Rare = NULL;
public:
    int size = 0;
    
    bool Empty(){
    return Front == NULL;
	}
	 
    void Enqueue(int value){
    QueueNode *Temp;
    Temp = new QueueNode(value); 
    if (Temp == NULL)  //When heap exhausted 
        cout << "Queue is Full" << endl;
    else
    {
        if (Front == NULL)
        {
            Front = Temp;
            Rare = Temp;
        } 
        else
        {
            Rare->next = Temp;
            Rare = Temp;
        }
        cout<<value <<" Inserted into Queue "<<endl;
        size++;
    } 
	}      

    void Dequeue(){
    if (Front == NULL) 
        cout << "Queue is Empty" << endl;
    else
    { 
        cout<<Front->val <<" Removed From Queue"<<endl;
        QueueNode *Temp = Front;
        Front = Front->next;
        delete Temp;
        size--;
    }  
	}
	  
    int Peek(){
    if(Empty())  
     {  cout<<"Queue is Empty"<<endl;
        return -1;
     } 
    else 
      return Front->val;
	}
};  
int main()

{
    Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    Q.Dequeue();
    cout<<"The size of the Queue is "<<Q.size<<endl;
    cout<<"The Peek element of the Queue is "<<Q.Peek()<<endl;
    return 0;
}   

