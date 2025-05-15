#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <climits>

class MinHeap {
private:
    int size;
    std::vector<int> heapArray;
    std::vector<int> keyArray;
    std::vector<int> position;

    void minHeapify(int);

public:
    MinHeap(int capacity);
    bool isEmpty();
    int extractMin();
    void decreaseKey(int v, int key);
    bool isInHeap(int v);
    void swap(int& a, int& b);
    int getKey(int v);
    std::vector<int> getKeyArray();
};

#endif
