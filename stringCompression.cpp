class Solution {
public:
    string compressedString(string s) {
      
        string ans="";
        int c=1;
        for(int i=0;i<s.length();i++){
             
              if(s[i]==s[i+1])
                  c++;
            else
            {
               if(c<=9)
               {
                   ans+=to_string(c);
                   ans+=s[i];
               }
                else
                {
                    int div= c/9;
                    while(div!=0)
                    {
                        div--;
                         ans+=to_string(9);
                         ans+=s[i];
                    }
                    int remainder= c%9;
                    if(remainder>0)
                    {
                        ans+=to_string(remainder);
                        ans+=s[i];
                    }
                }
                c=1;
            }
            }
        
        return ans;
    }
};