#include <iostream>
using namespace std;

int main() {
	int T,X;
	cin>>T;
	while(T--)
	{
	    cin>>X;
	    if(X<4)
	    {
	        cout<<"MILD"<<endl;
	    }
	    else if(4<=X && X<7)
	    {
	        cout<<"MEDIUM"<<endl;
	    }
	    else
	    cout<<"HOT"<<endl;
	}
	return 0;
}