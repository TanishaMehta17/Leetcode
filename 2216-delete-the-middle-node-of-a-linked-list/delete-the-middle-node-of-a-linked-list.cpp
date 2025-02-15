/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    private:
    ListNode* middleNode(ListNode*head)
    {
        ListNode*slow=head;
        ListNode*fast=head->next;
        ListNode*prev=nullptr;
        while(fast!=nullptr)
        {
            fast=fast->next;
            if(fast!=nullptr)
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }
        return prev;
    }

public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        return nullptr;
        ListNode*prev= middleNode(head);
        prev->next=prev->next->next;
        return head;
    }
};