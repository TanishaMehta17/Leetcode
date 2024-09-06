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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_map<int, int> m;
        unordered_set<int> present(nums.begin(), nums.end());  // Corrected from 'unordered_map' to 'unordered_set'
        ListNode* temp = head;

        while (temp != nullptr) {
            m[temp->val]++;
            temp = temp->next;
        }

        while (head != nullptr && present.find(head->val) != present.end()) {
            temp = head;
            head = head->next;
            m[temp->val]--;
            delete temp;            
        }
        ListNode*prev=nullptr;
        temp=head;
       
        while (temp != nullptr) {
            if (present.find(temp->val) != present.end()) {
                if (prev != nullptr) {
                    prev->next = temp->next;
                }
                temp->next = nullptr;
                m[temp->val]--;
                delete temp;
                temp = (prev != nullptr) ? prev->next : head;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};