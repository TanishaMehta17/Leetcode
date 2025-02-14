class Solution {
private:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) 
                fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;  // Fix: Initialize curr with head
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* middle = middleNode(head);
        ListNode* newHead = reverse(middle);
        middle->next = nullptr;

        ListNode* p1 = head;
        ListNode* p2 = newHead;

        while (p2 != nullptr) {
            if (p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;  
    }
};
