#include <iostream>
using namespace std;

int main() {
	int T,N,X,M;
	cin>>T;
	while(T--)
	{
	    cin>>N>>M>>X;
	    cout<<X*(2*(N+M))<<endl;
	}
	return 0;
}