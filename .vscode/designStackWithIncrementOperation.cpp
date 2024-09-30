#include <stack>

class CustomStack {
public:
    std::stack<int> s;
    int k1;

    CustomStack(int maxSize) {
        this->k1 = maxSize;
    }

    void push(int x) {
        if (k1 > 0) {
            s.push(x);
            k1--;
        }
    }

    int pop() {
        if (s.empty()) {
            return -1;
        } else {
            int topElement = s.top();
            s.pop();
            k1++;
            return topElement;
        }
    }

    void increment(int k, int val) {
        std::stack<int> tempStack;
        int size = s.size(),c=0;
        int incrementCount = min(k, size);  
       
        while (!s.empty()) {
            tempStack.push(s.top());
            s.pop();
        }

       
        while (!tempStack.empty()) {
            if (c++ < incrementCount) {  
                s.push(tempStack.top() + val);
            } else {
                s.push(tempStack.top());
            }
            tempStack.pop();
        }
       
    }
};
