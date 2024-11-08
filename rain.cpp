#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int a;
	    cin>>a;
	    if(a<3)
	    cout<<"LIGHT\n";
	    else if(a>=3 && a<7)
	    cout<<"MODERATE\n";
	    else
	    cout<<"HEAVY\n";
	}
	return 0;
}