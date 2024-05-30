#include <iostream>
using namespace std;

// 1. Search the key in the array
int findElement(int arr[], int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == key)
			return i;
	
	// If the key is not found
	return -1;
}
int main()
{
	int arr[] = { 12, 34, 10, 6, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Using a last element as search element
	int key = 40;

	// Function call
	int position = findElement(arr, n, key);

	if (position == -1)
		cout << "Element not found";
	else
		cout << "Element Found at Position: "
			<< position + 1;
	
	return 0;
}

// 2. Insert an element in the array
#include <iostream>
using namespace std;
int insertSorted(int arr[], int n, int key, int capacity)
{
	if (n >= capacity)
		return n;

	arr[n] = key;
	return (n + 1);
}

int main()
{
	int arr[20] = { 12, 16, 20, 40, 50, 70 };
	int capacity = sizeof(arr) / sizeof(arr[0]);
	int n = 6;
	int i, key = 26;

	cout << "Before Insertion: ";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";

	// Inserting an element at the last
	n = insertSorted(arr, n, key, capacity);

	cout << "\nAfter Insertion: ";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}


// 3. Insert an element at the position in the array
#include <iostream>
using namespace std;

void insertElement(int arr[], int n, int x, int pos)
{
	for (int i = n - 1; i >= pos; i--)
		arr[i + 1] = arr[i];

	arr[pos] = x;
}

int main()
{
	int arr[15] = { 2, 4, 1, 8, 5 };
	int n = 5;

	cout<<"Before insertion : ";
	for (int i = 0; i < n; i++)
		cout<<arr[i]<<" ";

	cout<<endl;

	int x = 10, pos = 2;
	insertElement(arr, n, x, pos);
	n++;

	cout<<"After insertion : ";
	for (int i = 0; i < n; i++)
		cout<<arr[i]<<" ";

	return 0;
}

// 4. Delete an element in the array
#include <iostream>
using namespace std;

// To search a key to be deleted
int findElement(int arr[], int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == key)
			return i;

	return -1;
}

// Function to delete an element
int deleteElement(int arr[], int n, int key)
{
	// Find position of element to be deleted
	int pos = findElement(arr, n, key);

	if (pos == -1) {
		cout << "Element not found";
		return n;
	}

	// Deleting element
	int i;
	for (i = pos; i < n - 1; i++)
		arr[i] = arr[i + 1];

	return n - 1;
}

int main()
{
	int i;
	int arr[] = { 10, 50, 30, 40, 20 };

	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 30;

	cout << "Array before deletion\n";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	
	n = deleteElement(arr, n, key);

	cout << "\n\nArray after deletion\n";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}

// 5. Sort an array
#include<iostream>
using namespace std;
void SortArray(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++) {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
        cout << endl;
    }
}
int main()
{
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    SortArray(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}

#include<iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    cout<<"Reversed Array: ";
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
	cout<<"\n";
    return 0;
}

// 6. Print three largest element in the array
#include<iostream>
using namespace std;

void print3largest(int arr[], int arr_size) 
{ 
    int first, second, third; 

    // There should be atleast three elements 
    if (arr_size < 3) 
    { 
        cout << " Invalid Input "; 
        return; 
    } 

    third = first = second = INT_MIN; 
    for(int i = 0; i < arr_size; i++) 
    { 
        
        // If current element is
        // greater than first
        if (arr[i] > first)
        { 
            third = second; 
            second = first; 
            first = arr[i]; 
        } 

        // If arr[i] is in between first
        // and second then update second 
        else if (arr[i] > second && arr[i] != first)
        { 
            third = second; 
            second = arr[i]; 
        } 

        else if (arr[i] > third && arr[i] != second && arr[i] != first) 
            third = arr[i]; 
    } 

    cout << "Three largest elements are "
        << first << " " << second << " "
        << third << endl; 
} 

// Driver code
int main() 
{ 
    int arr[] = { 12, 13, 1, 10, 34, 11, 34 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    
    print3largest(arr, n); 
    return 0; 
} 

// 7. Remove duplicates from the array
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = 7;
    int unique[7];
    int newSize = 0;

    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == unique[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            unique[newSize] = arr[i];
            newSize++;
        }
    }

    cout<<"Array with duplicates removed: ";
    for (int i = 0; i < newSize; i++) {
        cout<<unique[i]<<" ";
    }
	cout<<"\n";
    return 0;
}
// 8. Program to rotate an array to the right by a given number of positions:

#include <iostream>
using namespace std;
void rightRotate(int arr[], int n, int k) {
    int temp[k];

    // Copy the last k elements to a temporary array
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Shift the remaining elements to the right
    for (int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

    // Copy the temporary array back to the original array
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int k = 2; // Number of positions to rotate

    rightRotate(arr, n, k);

    cout<<"Rotated array: ";
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
	cout<<endl;
    return 0;
}
// 9. Program to find the union of two arrays:

#include <stdio.h>

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {3, 4, 5, 6, 7};
    int n1 = 5, n2 = 5;
    int unionArray[10];
    int count = 0;

    // Add elements from the first array to the unionArray
    for (int i = 0; i < n1; i++) {
        unionArray[count++] = arr1[i];
    }

    // Add elements from the second array to the unionArray if they are not already present
    for (int i = 0; i < n2; i++) {
        int isAlreadyPresent = 0;
        for (int j = 0; j < count; j++) {
            if (arr2[i] == unionArray[j]) {
                isAlreadyPresent = 1;
                break;
            }
        }
        if (!isAlreadyPresent) {
            unionArray[count++] = arr2[i];
        }
    }

    cout<<"Union of arrays: ";
    for (int i = 0; i < count; i++) {
        cout<<unionArray[i]<<" ";
    }
	cout<<endl;
    return 0;
}
// 10. Program to find the intersection of two arrays:

#include <stdio.h>

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {3, 4, 5, 6, 7};
    int n1 = 5, n2 = 5;
    int intersection[5];
    int count = 0;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                intersection[count++] = arr1[i];
                break;
            }
        }
    }

    cout<<"Intersection of arrays: ";
    for (int i = 0; i < count; i++) {
        cout<<intersection[i]<<" ";
    }

    return 0;
}

