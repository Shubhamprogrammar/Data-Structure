#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] > heap[index]) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int leftChild = left(index);
        int rightChild = right(index);

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
            smallest = leftChild;

        if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
            smallest = rightChild;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    void deleteMin() {
        if (heap.size() == 0) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void displayHeap() {
        for (int i : heap) {
            cout << i << " ";
        }
        cout << endl;
    }
};

class MaxHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int leftChild = left(index);
        int rightChild = right(index);

        if (leftChild < heap.size() && heap[leftChild] > heap[largest])
            largest = leftChild;

        if (rightChild < heap.size() && heap[rightChild] > heap[largest])
            largest = rightChild;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    void deleteMax() {
        if (heap.size() == 0) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void displayHeap() {
        for (int i : heap) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap minHeap;
    MaxHeap maxHeap;

    int values[] = { 3, 1, 6, 5, 2, 4 };

    for (int value : values) {
        minHeap.insert(value);
        maxHeap.insert(value);
    }

    cout << "Min Heap: ";
    minHeap.displayHeap();

    cout << "Max Heap: ";
    maxHeap.displayHeap();

    minHeap.deleteMin();
    maxHeap.deleteMax();

    cout << "Min Heap after deletion: ";
    minHeap.displayHeap();

    cout << "Max Heap after deletion: ";
    maxHeap.displayHeap();

    return 0;
}

