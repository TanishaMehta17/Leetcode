class Solution {
    private:
    bool checkPrime(int num)
    {
        for(int i=2;i<=sqrt(num);i++)
        {
            if(num%i==0)
            return false;
        }
        return true;
    }
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>prime;
        for(int i=left==1?2:left;i<=right;i++)
        {
            if(checkPrime(i))
            prime.push_back(i);
        }
        if(prime.size()<2)
        return {-1,-1};
        int a=0,b=0,mini=INT_MAX;
        for(int i=0;i<prime.size()-1;i++)
        {
             if(prime[i+1]-prime[i]<mini)
             {
                mini=prime[i+1]-prime[i];
                b=prime[i+1];
                a=prime[i];
             }
        }
        return {a,b};
        
    }
};