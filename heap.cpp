#include "heap.h"
#include <iostream>

MinHeap::MinHeap(int capacity) {
    size = capacity;
    keyArray.resize(capacity, INT_MAX);
    heapArray.resize(capacity);
    position.resize(capacity);

    for (int i = 0; i < capacity; ++i) {
        heapArray[i] = i;
        position[i] = i;
    }
    keyArray[0] = 0; // Start from vertex 0
}

bool MinHeap::isEmpty() {
    return size == 0;
}

int MinHeap::getKey(int v) {
    return keyArray[v];
}

bool MinHeap::isInHeap(int v) {
    return position[v] < size;
}

int MinHeap::extractMin() {
    int minVertex = heapArray[0];
    heapArray[0] = heapArray[size - 1];
    position[heapArray[0]] = 0;
    --size;
    minHeapify(0);
    return minVertex;
}

void MinHeap::decreaseKey(int v, int key) {
    keyArray[v] = key;
    int i = position[v];

    while (i && keyArray[heapArray[(i - 1) / 2]] > keyArray[heapArray[i]]) {
        position[heapArray[i]] = (i - 1) / 2;
        position[heapArray[(i - 1) / 2]] = i;
        swap(heapArray[i], heapArray[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void MinHeap::minHeapify(int i) {
    int left = 2 * i + 1, right = 2 * i + 2;
    int smallest = i;

    if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[smallest]])
        smallest = left;
    if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[smallest]])
        smallest = right;

    if (smallest != i) {
        position[heapArray[smallest]] = i;
        position[heapArray[i]] = smallest;
        swap(heapArray[i], heapArray[smallest]);
        minHeapify(smallest);
    }
}

void MinHeap::swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

std::vector<int> MinHeap::getKeyArray() {
    return keyArray;
}
