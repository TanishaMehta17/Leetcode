class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<double>pq;
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        while(k!=0)
        {
            double top=pq.top();
            pq.pop();
            sum+= top;
            pq.push(ceil(top/3));
            k--;
        }
        return sum;
    }
};