class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq(gifts.begin(),gifts.end());
        long long sum=0;
        while(k!=0)
        {
            int top=pq.top();
            pq.pop();
            pq.push(sqrt(top));
            k--;
        }
        while(!pq.empty())
        {
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};