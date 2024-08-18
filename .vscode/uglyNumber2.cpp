class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumbers(n);
        uglyNumbers[0] = 1;
        
        int index2 = 0, index3 = 0, index5 = 0;
        int nextMultipleOf2 = 2;
        int nextMultipleOf3 = 3;
        int nextMultipleOf5 = 5;

        for (int i = 1; i < n; i++) {
            int nextUglyNumber = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
            uglyNumbers[i] = nextUglyNumber;

            if (nextUglyNumber == nextMultipleOf2) {
                index2++;
                nextMultipleOf2 = uglyNumbers[index2] * 2;
            }
            if (nextUglyNumber == nextMultipleOf3) {
                index3++;
                nextMultipleOf3 = uglyNumbers[index3] * 3;
            }
            if (nextUglyNumber == nextMultipleOf5) {
                index5++;
                nextMultipleOf5 = uglyNumbers[index5] * 5;
            }
        }
        
        return uglyNumbers[n - 1];
    }
};