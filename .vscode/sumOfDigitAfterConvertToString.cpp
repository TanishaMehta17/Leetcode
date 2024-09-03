class Solution {
    int sumString(string s)
    {
         int sum=0;
        for(int i=0;i<s.length();i++)
        {
            sum+=s[i]-'0';
        }
        return sum;
    }
public:
    int getLucky(string s, int k) {
        string str="";
       
        for(int i=0;i<s.length();i++)
        {
            char ch= s[i];
            int num= ch-'a'+1;
            str+=to_string(num);
        }
         cout<<str<<endl;
        while(k!=0)
        {
            k--;
            str=to_string(sumString(str));
            
        }
        return stoi(str);
    }
};