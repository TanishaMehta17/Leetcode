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
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode*temp=head;
        ListNode*prev=head;
        int a,b,ans;
        while(temp!=nullptr && temp->next!=nullptr)
        {
             a= temp->val;
            temp=temp->next;
            if(temp!=nullptr)
                 b= temp->val;
             ans= gcd(a,b);
            ListNode* newNode =new ListNode(ans);
            prev->next=newNode;
            newNode->next=temp;
            prev=temp;
        }
        return head;
    }
};