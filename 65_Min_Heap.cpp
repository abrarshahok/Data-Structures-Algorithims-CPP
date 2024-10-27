#include <iostream>
#include <vector>

class MinHeap {
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

    // Function to maintain the heap property for min heap
    void heapifyDown(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        // Compare with left child
        if (l < heap.size() && heap[l] < heap[smallest]) {
            smallest = l;
        }

        // Compare with right child
        if (r < heap.size() && heap[r] < heap[smallest]) {
            smallest = r;
        }

        // If smallest is not the root
        if (smallest != i) {
            std::swap(heap[i], heap[smallest]);
            heapifyDown(smallest); // Recursive call to heapify the affected subtree
        }
    }

    // Function to maintain the heap property for min heap
    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    // Insert a new element into the heap
    void insert(int value) {
        heap.push_back(value);       // Add new element at the end
        heapifyUp(heap.size() - 1);  // Heapify from the last element up to restore min heap property
    }

    // Remove and return the minimum element from the heap
    int extractMin() {
        if (heap.empty()) {
            std::cerr << "Heap is empty.\n";
            return -1;
        }

        int root = heap[0];         // The root is the minimum element
        heap[0] = heap.back();      // Move the last element to root
        heap.pop_back();            // Remove the last element
        heapifyDown(0);             // Heapify from root down to restore min heap property
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
    MinHeap h;

    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);
    h.insert(15);

    std::cout << "Min-Heap elements: ";
    h.displayHeap();

    std::cout << "Extracted min: " << h.extractMin() << std::endl;
    std::cout << "Min-Heap after extracting min: ";
    h.displayHeap();

    return 0;
}
