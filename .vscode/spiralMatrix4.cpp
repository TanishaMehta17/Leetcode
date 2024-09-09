class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));  // Initialize matrix with -1
        int count = 0;
        int total = m * n;
        int startrow = 0;
        int endrow = m - 1;
        int startcol = 0;
        int endcol = n - 1;

        while (count < total) {
            // Fill top row
            for (int i = startcol; i <= endcol && count < total; i++) {
                if (head != nullptr) {
                    ans[startrow][i] = head->val;
                    head = head->next;
                }
                count++;
            }
            startrow++;

            // Fill right column
            for (int i = startrow; i <= endrow && count < total; i++) {
                if (head != nullptr) {
                    ans[i][endcol] = head->val;
                    head = head->next;
                }
                count++;
            }
            endcol--;

            // Fill bottom row
            for (int i = endcol; i >= startcol && count < total; i--) {
                if (head != nullptr) {
                    ans[endrow][i] = head->val;
                    head = head->next;
                }
                count++;
            }
            endrow--;

            // Fill left column
            for (int i = endrow; i >= startrow && count < total; i--) {
                if (head != nullptr) {
                    ans[i][startcol] = head->val;
                    head = head->next;
                }
                count++;
            }
            startcol++;
        }

        return ans;
    }
};
