class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = queries.size();
        vector<int> ans(n);

        // Sort items by price
        sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        // Preprocess items to have the max beauty up to that point
        for (int i = 1; i < items.size(); ++i) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }

        // Process each query
        for (int i = 0; i < n; ++i) {
            int value = queries[i];
            int start = 0, end = items.size() - 1, maxi = 0;

            // Binary search for the highest price <= value
            while (start <= end) {
                int mid = start + (end - start) / 2;
                if (items[mid][0] <= value) {
                    maxi = items[mid][1];
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            ans[i] = maxi;
        }

        return ans;
    }
};
