class Solution {
public:
    int minLength(string s) {
        string ab = "AB";
        string cd = "CD";
        size_t pos;

        
       bool removed = true;
        while (removed) {
            removed = false;

           
            while ((pos = s.find(ab)) != std::string::npos) {
                s.erase(pos, ab.length());
                removed = true;
                cout<<s<<"   1  "<<removed<<endl;
            }

          
            while ((pos = s.find(cd)) != std::string::npos) {
                s.erase(pos, cd.length());
                removed = true;
                 cout<<s<<"   2  "<<removed<<endl;
            }
        }
        return s.length();
    }
};