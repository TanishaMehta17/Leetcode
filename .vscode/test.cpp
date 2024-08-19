class Solution
{
    public:
    vector<int>twoSum(vector<int>nums, int target)
    {
        unordered_map<int,int>m;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            int compliment= target-nums[i];
            if(m.find(compliment)!=m.end() && m[compliment]!=i)
            {
                 ans.push_back(i);
                 ans.push_back(m[compliment]);
                 break;
            }
        }
        return ans;
    }
};