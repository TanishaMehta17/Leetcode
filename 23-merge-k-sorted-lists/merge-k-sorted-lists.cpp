class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        int n = lists.size();
        for (int i = 0; i < n; i++) {
            if (lists[i]) pq.push(lists[i]);
        }
        ListNode* root = new ListNode(-1);
        ListNode* dummy = root;
        while (!pq.empty()) {
            dummy->next = pq.top();
            pq.pop();
            dummy = dummy->next;
            if (dummy->next) {
                pq.push(dummy->next);
            }
        }
        return root->next;
    }
};
