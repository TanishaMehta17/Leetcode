#include <iostream>
using namespace std;

int main() {
	int T,X;
	cin>>T;
	while(T--)
	{
	    cin>>X;
	    if(X<=70)
	    {
	        cout<<0<<endl;
	    }
	    else if(70<X && X<=100)
	    {
	        cout<<500<<endl;
	    }
	    else
	    cout<<2000<<endl;
	}
	return 0;
}