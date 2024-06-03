// Q.1 Reverse a string without changing the word

#include<iostream>
#include<stack>
using namespace std;
 
void reverse(string s)
{
//create an empty string stack
stack<string> stc;

//create an empty temporary string
string temp="";

//traversing the entire string
for(int i=0;i<s.length();i++)
{
	if(s[i]==' ')
	{
	
	//push the temporary variable into the stack
	stc.push(temp); 
	
	//assigning temporary variable as empty
	temp="";		 
	}
	else
	{
	temp=temp+s[i];
	}

}

//for the last word of the string
stc.push(temp);

while(!stc.empty()) {

	// Get the words in reverse order 
	temp=stc.top();
	cout<<temp<<" ";
	stc.pop();
}
cout<<endl;
}

//Driver code
int main()
{
string s="I Love To Code";
reverse(s); 
return 0;
}

// Q.2. Reverse a string

#include<iostream>
#include<string>
#include<stack>
using namespace std;

void rev(string &str){
//stack which take char input.
stack<char> s;
//we push all char in stack.
for(auto it:str){
s.push(it);
}
//here we clear all char present in str. 
str.clear();
// as stack is LIFO DS we push_back all char and our string is reverse now.
while(!s.empty()){
	str.push_back(s.top());
	s.pop();
}
}
int main() {
//string we want to reverse.
string str = "I love to code";

//the function that make all necessary changes.
rev(str);
//finally return/output the reverse string
cout << "Reversed string is : " << str;
return 0;
}

// Q.3. Find and remove the lowest element in a stack.
#include <iostream>

using namespace std;

#define MAX_SIZE 15 // Maximum size of stack

class Stack {
private:
    int top; // Index of top element
    int arr[MAX_SIZE]; // Array to store elements

public:
    Stack() {
        top = -1; // Initialize top index to -1 (empty stack)
    }

    bool push(int x) {
        if (isFull()) {
            cout << "Stack overflow" << endl; // Display message if stack is full
            return false; // Return false to indicate failure in pushing element
        }
        // Increment top index and add element to array
        arr[++top] = x; 
        return true; // Return true to indicate successful element addition
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl; // Display message if stack is empty
            return 0; // Return 0 to indicate failure in popping element
        }
        // Return top element and decrement top index
        return arr[top--]; 
    }
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl; // Display message if stack is empty
            return 0; // Return 0 to indicate failure in peeking element
        }
        // Return top element without modifying top index
        return arr[top]; 
    }

    bool isEmpty() {
        // Stack is empty if top index is -1
        return (top < 0); 
    }

    bool isFull() {
        // Stack is full if top index is equal to MAX_SIZE - 1
        return (top >= MAX_SIZE - 1); 
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty" << endl; // Display message if stack is empty
            return;
        }
        cout << "\nStack elements are: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " "; // Display elements of the stack
        cout << endl;
    }

    int find_and_remove_lowest() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl; // Display message if stack is empty
            return -1; // Return -1 to indicate failure in finding the lowest element
        }

        int minElement = INT_MAX; // Initialize minElement with the largest possible integer value
        Stack temp;
        while (!isEmpty()) {
            int element = pop();
            if (element < minElement) {
                minElement = element; // Update minElement if a smaller element is found
            }
            temp.push(element); // Push other elements onto the temporary stack
        }

        while (!temp.isEmpty()) {
            int element = temp.pop();
            if (element != minElement) { // Push all elements except for the minElement back onto the original stack
                push(element);
            }
        }
        return minElement; // Return the lowest element that was removed
    }
};

int main() {
    // Initialize the stack stk
    Stack stk; 
    cout << "Input some elements onto the stack:";
    stk.push(7);
    stk.push(4);
    stk.push(2);
    stk.push(5);
    stk.display(); 
    int z = stk.find_and_remove_lowest(); 
    cout << "Find and remove the lowest element " << z << " from the stack.";
    stk.display(); 
    cout << "\nInput two more elements";
    stk.push(-1);
    stk.push(2);
    stk.display();
    z = stk.find_and_remove_lowest(); 
    cout << "Find and remove the lowest element " << z << " from the stack.";
    stk.display(); 
    cout << endl;
    return 0;
}

// 4. Remove duplicates from the stack 

#include <iostream>

using namespace std;
#define MAX_SIZE 15 // Maximum size of stack

class Stack {
private:
    int top; // Index of top element
    int arr[MAX_SIZE]; // Array to store elements

public:
    Stack() {
        top = -1; // Initialize top index to -1 (empty stack)
    }

    bool push(int x) {
        if (isFull()) {
            cout << "Stack overflow" << endl; // Display message if stack is full
            return false; // Return false to indicate failure in pushing element
        }
        // Increment top index and add element to array
        arr[++top] = x; 
        return true; // Return true to indicate successful element addition
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl; // Display message if stack is empty
            return 0; // Return 0 to indicate failure in popping element
        }
        // Return top element and decrement top index
        return arr[top--]; 
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl; // Display message if stack is empty
            return 0; // Return 0 to indicate failure in peeking element
        }
        // Return top element without modifying top index
        return arr[top]; 
    }

    bool isEmpty() {
        // Stack is empty if top index is -1
        return (top < 0); 
    }

    bool isFull() {
        // Stack is full if top index is equal to MAX_SIZE - 1
        return (top >= MAX_SIZE - 1); 
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty" << endl; // Display message if stack is empty
            return;
        }
        cout << "\nStack elements are: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " "; // Display elements of the stack
        cout << endl;
    }

    // Function to remove duplicates from the stack
    void remove_duplicates(Stack& stk);
};

void Stack::remove_duplicates(Stack& stk) {
    if (stk.isEmpty()) {
        cout << "Stack is empty." << endl; // Display message if the stack is empty
        return;
    }

    int size = stk.top + 1; // Get the size of the stack
    int temp[size]; // Create a temporary array to store stack elements
    int count = 0; // Initialize count to 0

    // The stack elements are copied into a temporary array
    while (!stk.isEmpty()) {
        temp[count++] = stk.pop(); // Pop elements from stack and store in temporary array
    }

    // Remove duplicates from the temporary array
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (temp[i] == temp[j]) {
                // Duplicate elements are marked with -1
                temp[j] = -1;
            }
        }
    }

    // Non-duplicate elements are pushed back onto the stack
    for (int i = count - 1; i >= 0; i--) {
        if (temp[i] != -1) {
            stk.push(temp[i]); // Push non-duplicate elements back onto the original stack
        }
    }
}

int main() {
    Stack stk; 
    cout << "Input some elements onto the stack:";
    stk.push(7);
    stk.push(4);
    stk.push(2);
    stk.push(2);
    stk.push(5);
    stk.display();
    cout << "\nRemove duplicates from the said stack:";
    stk.remove_duplicates(stk); // Remove duplicates from the stack
    stk.display();
    cout << "\nInput two more elements onto the stack:";
    stk.push(7);
    stk.push(5);
    stk.display();
    cout << "\nRemove duplicates from the said stack:";
    stk.remove_duplicates(stk); // Remove duplicates from the stack
    stk.display();
    cout << endl;
}

// 5. Average of the element in the stack
#include <iostream>

using namespace std;

#define MAX_SIZE 15 // Maximum size of stack

class Stack {
private:
    int top; // Index of top element
    int arr[MAX_SIZE]; // Array to store elements

public:
    Stack() {
        top = -1; // Initialize top index to -1 (empty stack)
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack overflow" << endl; // Display message if stack is full
        }
        // Increment top index and add element to array
        arr[++top] = x; 
    }

    bool isFull() {
        // Stack is full if top index is equal to MAX_SIZE - 1
        return (top >= MAX_SIZE - 1); 
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty" << endl; // Display message if stack is empty
            return;
        }
        cout << "\nStack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " "; // Display elements of the stack
        cout << endl;
    }
    
    bool isEmpty() {
        // Stack is empty if top index is -1
        return (top < 0); 
    }

    double average() {
        if (isEmpty()) {
            return 0.0; // Return 0 if the stack is empty
        }
        int sum = 0;
        for (int i = 0; i <= top; i++) {
            sum += arr[i]; // Calculate the sum of all elements in the stack
        }
        return (double) sum / (top + 1); // Return the average value
    }
};

int main() {
    // Initialize the stack stk
    Stack stk; 
    cout << "Input some elements onto the stack:";
    stk.push(7);
    stk.push(4);
    stk.push(2);
    stk.push(5);
    stk.push(1);
    stk.push(0);
    stk.display(); // Display the elements of the stack

    // Calculate the average value of the elements in the stack
    double avg_val = stk.average(); 
    printf("Average of the said stack values: %0.2f\n", avg_val);
    cout << endl;
    return 0;
}
