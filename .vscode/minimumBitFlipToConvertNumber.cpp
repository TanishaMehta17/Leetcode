class Solution {
  
public:
    int minBitFlips(int start, int goal) {
       bitset<32>num1(start);
       bitset<32>num2(goal);
       int ans=0;
       for(int i=0;i<32;i++)
       {
           if(num1[i]!=num2[i])
               ans++;
       }
        return ans;
    }
};