class Solution {
private:
    void findStartTime(vector<long long>& time,
                       const vector<int>& skill,
                       const vector<int>& mana,
                       int start) {
        int n = skill.size();
        vector<long long> prefix(n, 0);

       
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + (long long)skill[i - 1] * mana[start];
        }

       
        long long maxi = time[0];
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, time[i] - prefix[i]);
        }

       
        time[0] = maxi + (long long)skill[0] * mana[start];
        for (int i = 1; i < n; i++) {
            time[i] = time[i - 1] + (long long)skill[i] * mana[start];
        }
    }

public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> time(n, 0);

       
        time[0] = (long long)skill[0] * mana[0];
        for (int i = 1; i < n; i++) {
            time[i] = time[i - 1] + (long long)skill[i] * mana[0];
        }

       
        for (int j = 1; j < m; j++) {
            findStartTime(time, skill, mana, j);
        }

        return time[n - 1];
    }
};
