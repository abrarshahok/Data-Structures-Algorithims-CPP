#include <iostream>
#include <vector>

class MaxHeap {
    std::vector<int> heap;

    // Helper function to get the parent index of a given node
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Helper functions to get the left and right child indices of a given node
    int left(int i) {
        return (2 * i + 1);
    }
    int right(int i) {
        return (2 * i + 2);
    }

    // Function to maintain the heap property for max heap
    void heapifyDown(int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        // Compare with left child
        if (l < heap.size() && heap[l] > heap[largest]) {
            largest = l;
        }

        // Compare with right child
        if (r < heap.size() && heap[r] > heap[largest]) {
            largest = r;
        }

        // If largest is not the root
        if (largest != i) {
            std::swap(heap[i], heap[largest]);
            heapifyDown(largest); // Recursive call to heapify the affected subtree
        }
    }

    // Function to maintain the heap property for max heap
    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] < heap[i]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    // Insert a new element into the heap
    void insert(int value) {
        heap.push_back(value);       // Add new element at the end
        heapifyUp(heap.size() - 1);  // Heapify from the last element up to restore max heap property
    }

    // Remove and return the maximum element from the heap
    int extractMax() {
        if (heap.empty()) {
            std::cerr << "Heap is empty.\n";
            return -1;
        }

        int root = heap[0];         // The root is the maximum element
        heap[0] = heap.back();      // Move the last element to root
        heap.pop_back();            // Remove the last element
        heapifyDown(0);             // Heapify from root down to restore max heap property
        return root;
    }

    // Utility function to display heap
    void displayHeap() const {
        for (int value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MaxHeap h;

    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);
    h.insert(15);

    std::cout << "Max-Heap elements: ";
    h.displayHeap();

    std::cout << "Extracted max: " << h.extractMax() << std::endl;
    std::cout << "Max-Heap after extracting max: ";
    h.displayHeap();

    return 0;
}
