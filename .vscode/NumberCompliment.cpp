#include<algorithm>
#include<cmath>
#include<string>
#include<iostream>

class Solution {
    private:
    string decimalToBinary(int num)
    {
        if (num == 0) return "0";  
        string s = "";
        while(num != 0)
        {
            s += ('0' + num % 2);
            num /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    int binaryToDecimal(string s)
    {
        int decimal = 0;
        int length = s.length();

        for (int i = 0; i < length; ++i) {
            if (s[length - 1 - i] == '1') {
                decimal += pow(2, i);
            }
        }

        return decimal;
    }

    public:
    int findComplement(int num) {
        string s = decimalToBinary(num);
        cout << s << endl;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1')
                s[i] = '0';
            else
                s[i] = '1';
        }
        return binaryToDecimal(s);
    }
};

int main() {
    Solution solution;
    int num = 5;
    int complement = solution.findComplement(num);
    cout << complement << endl;

    return 0;
}
