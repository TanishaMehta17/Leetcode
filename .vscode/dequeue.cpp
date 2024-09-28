#include <deque>
using namespace std;

class MyCircularDeque {
public:
    deque<int> q;  // The deque to store elements
    int k;         // The current capacity left
    int k1;        // The initial size of the deque (max size)

    MyCircularDeque(int k) {
        k1 = k;    // Initialize max size
        this->k = k;   // Initialize the current capacity left
    }

    // Insert element at the front of the deque
    bool insertFront(int value) {
        if (q.size() < k1) { // Only insert if there is room
            q.push_front(value);
            return true;
        }
        return false;
    }

    // Insert element at the rear (back) of the deque
    bool insertLast(int value) {
        if (q.size() < k1) { // Only insert if there is room
            q.push_back(value);
            return true;
        }
        return false;
    }

    // Delete element from the front of the deque
    bool deleteFront() {
        if (!q.empty()) {
            q.pop_front();
            return true;
        }
        return false;
    }

    // Delete element from the back of the deque
    bool deleteLast() {
        if (!q.empty()) {
            q.pop_back();
            return true;
        }
        return false;
    }

    // Get the front element of the deque
    int getFront() {
        if (!q.empty()) {
            return q.front();
        }
        return -1; // Return -1 if the deque is empty
    }

    // Get the rear element of the deque
    int getRear() {
        if (!q.empty()) {
            return q.back();
        }
        return -1; // Return -1 if the deque is empty
    }

    // Check if the deque is empty
    bool isEmpty() {
        return q.empty();
    }

    // Check if the deque is full
    bool isFull() {
        return q.size() == k1;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
