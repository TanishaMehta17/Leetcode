class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        long long score = 0;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        while (!pq.empty()) {
            auto top = pq.top();
            int num = top.first;
            int index = top.second;

            if (nums[index] != -1) {
                score += num;
                nums[index] = -1;

                if (index - 1 >= 0) {
                    nums[index - 1] = -1;
                }
                if (index + 1 < nums.size()) {
                    nums[index + 1] = -1;
                }
            }

            pq.pop();
        }

        return score;
    }
};
