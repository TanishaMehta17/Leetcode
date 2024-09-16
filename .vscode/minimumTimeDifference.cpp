
class Solution {
    private:
    long long int convertToMin(string s)
    {
        int hr = stoi(s.substr(0, 2));
        int minutes = stoi(s.substr(3, 2));
        return (hr * 3600 + (minutes * 60));
    }

    public:
    int findMinDifference(vector<string>& time) {
        vector<int> timeInSeconds;
        
       
        for (int i = 0; i < time.size(); i++) {
            timeInSeconds.push_back(convertToMin(time[i]));
        }

      
        unordered_map<int, int> freq;
        for (int i = 0; i < timeInSeconds.size(); i++) {
            freq[timeInSeconds[i]]++;
        }

        for (auto it = freq.begin(); it != freq.end(); it++) {
            if (it->second > 1) 
                return 0;
        }

        
        sort(timeInSeconds.begin(), timeInSeconds.end());

        int ans = INT_MAX;
        
       
        for (int i = 0; i < timeInSeconds.size() - 1; i++) {
            ans = min(ans, timeInSeconds[i + 1] - timeInSeconds[i]);
        }
      
        ans = min(ans, 86400 - (timeInSeconds.back() - timeInSeconds.front()));
        return ans/60;
    }
};
