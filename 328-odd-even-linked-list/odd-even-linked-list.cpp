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
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; 
        ListNode* curr = head->next->next;
        int c = 3; 

        while (curr != nullptr) {
            if (c % 2 != 0) { 
                odd->next = curr;
                odd = odd->next;
            } else { 
                even->next = curr;
                even = even->next;
            }
            curr = curr->next;
            c++;
        }

      
        even->next = nullptr;


        odd->next = evenHead;
        return head;
    }
};