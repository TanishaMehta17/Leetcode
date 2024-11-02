class Solution {
public:
    bool isCircularSentence(string sentence) {
        char first = sentence[0];
        char last = sentence[sentence.length() - 1];
        bool cond1 = first == last;
        vector<string> v;
        istringstream stream(sentence);
        string word;
        while (stream >> word) {
            v.push_back(word);
        }
        char f1,f2,l1,l2;
        for(int i=0;i<v.size()-1;i++)
        {
           
            f2=v[i+1][0];
            l1= v[i][v[i].length()-1];
            if(l1!=f2)
                return false;
        }
        if(cond1==true)
            return true;
        return false;
    }
};
