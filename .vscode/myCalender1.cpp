class MyCalendar {
public:
    vector<pair<int, int>> dates;
    
    MyCalendar() {}
    
    bool book(int start, int end) {
        for (auto &p : dates) {
            if (start < p.second && end > p.first) {
                return false;
            }
        }
        dates.push_back({start, end});
        return true;
    }
};