class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {
     for(int i=0;i<heights.size();i++)
     {
         for(int j=0;j<heights.size()-1;j++)
         {
             if(heights[j]<heights[j+1])
             {
                 int temp= heights[j];
                 heights[j]=heights[j+1];
                 heights[j+1]=temp;

                 string s= names[j];
                 names[j]=names[j+1];
                 names[j+1]=s;
             }
         }
     }
     return names;   
    }
};