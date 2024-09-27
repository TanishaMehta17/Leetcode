#include <map>
using namespace std;

class MyCalendarTwo {
public:
    map<int, int> s_map;
    
    MyCalendarTwo() { }
    
    bool book(int start, int end) {
        s_map[start]++;
        s_map[end]--;
        
        int activeBookings = 0;
        for (auto it : s_map) {
            activeBookings += it.second;
            if (activeBookings >= 3) {
                // Undo the changes
                s_map[start]--;
                s_map[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
