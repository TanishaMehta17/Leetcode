#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,x;
    cin >> n >> x;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].first;
        a[i].second=i;
    }
    sort(a.begin(), a.end());
    int i=0,j=n-1;
    while(i<j){
        if(a[i].first+a[j].first==x){
            cout << a[i].second+1 << " " << a[j].second+1 << endl;
            return 0;
        }
        else if(a[i].first+a[j].first>x){
            j--;
        }
        else{
            i++;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}