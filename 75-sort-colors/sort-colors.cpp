class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one=0,two=0,zero=0,n=nums.size(),ptr=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            zero++;
            else if(nums[i]==1)
            one++;
            else
            two++;
        }
        for(int i=0;i<zero;i++)
        {
            nums[ptr++]=0;
        }
        for(int i=0;i<one;i++)
        {
            nums[ptr++]=1;
        }
        for(int i=0;i<two;i++)
        {
            nums[ptr++]=2;
        }
    }
};