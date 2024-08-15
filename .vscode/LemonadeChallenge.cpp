class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0,twenty=0;
        if(bills[0]==10 || bills[0]==20)
            return false;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
            {
                  five++;
            }
            else
            {
                int diff= bills[i]-5;
                if(diff==5 && five!=0)
                {
                    five--;
                }
               else if(diff==15 && five!=0 && ten!=0)
                {
                    five--;
                    ten--;
                }
                else if (diff==15 && five>=3)
                {
                    five-=3;
                }
                else
                    return false;
                if(bills[i]==10)
                    ten++;
                else
                    twenty++;
                
                    
            }
        }
        return true;
    }
};