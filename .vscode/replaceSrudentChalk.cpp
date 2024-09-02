class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
       long long int i=0,n=chalk.size(),s=0;
        for(int i=0;i<n;i++)
            s+=chalk[i];
       long long  int div= k/s;
        k-=s*div;
        while(1)
        {
            int index= chalk[i%n];
            if(index<=k)
                k-=index;
            else
            {
                return i%n;
                break;
            }
            i++;
        }
        return i;
    }
};