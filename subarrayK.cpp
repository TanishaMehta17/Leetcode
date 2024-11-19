class Solution {
public:
    long long maximumSubarraySum(vector<int>& v, int k) {
       long long int l=0,r=0,sum=0,maxi=INT_MIN,len=0;
       map<int,int>m;
        while(r<v.size())
        {
           
                m[v[r]]++;
            
            len++;
            sum+=v[r];
            if(len>k)
            {
              m[v[l]]--;
                if(m[v[l]]==0)
                    m.erase(v[l]);
                sum-=v[l];
                l++;
                len--;
            }
           
            if(len==k &&  m.size()==k)
            {
               maxi= max(maxi,sum);
               
            }
            
            r++;
        }
      return (maxi == INT_MIN) ? 0 : maxi;
    }
};