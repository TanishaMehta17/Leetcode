class Solution {
private:
    bool isEqual(vector<vector<int>>& temp) {
        int sumr = 0, sumd1 = 0, sumd2 = 0, count = 0;
        set<int> s;

        // Sum of the first row
        for (int i = 0; i < 3; i++) {
            sumr += temp[0][i];
        }

        // Check rows, columns, and diagonals
        for (int i = 0; i < 3; i++) {
            int sumRow = 0, sumCol = 0;
            for (int j = 0; j < 3; j++) {
                if (s.find(temp[i][j]) == s.end()) {
                    s.insert(temp[i][j]);
                    sumRow += temp[i][j];
                } else {
                    cout<<"here1"<<endl;
                    return false; // Duplicate element found in the row
                }

                
                    sumCol += temp[j][i];
             
                if (temp[i][j] < 1 || temp[i][j] > 9) 
                {
                    cout<<"here3"<<endl;
                    return false;
                }// Ensure numbers are between 1 and 9
            }
            if (sumRow != sumr || sumCol != sumr) return false;
            count += 2;
        }

        // Check diagonals
        for (int i = 0; i < 3; i++) {
            sumd1 += temp[i][i];
            sumd2 += temp[i][2 - i];
        }
        if (sumd1 != sumr || sumd2 != sumr) return false;
        count += 2;

        return count == 8;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                vector<vector<int>> temp(3, vector<int>(3));

                // Copy the 3x3 grid
                for (int k = 0; k < 3; k++) {
                    for (int h = 0; h < 3; h++) {
                        temp[k][h] = grid[i + k][j + h];
                    }
                }

                if (isEqual(temp)) {
                    count++;
                }
            }
        }
        return count;
    }
};
