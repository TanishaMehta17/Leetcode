#include<bits/stdc++.h>
#define ok "\n"
using namespace std;
/* mad_eye_moody */
void invest_good()
{
    int acha,thik; cin>>acha>>thik;
    if(acha >= thik * 2){
        cout<<"YES"<<ok;
    }
    else cout<<"NO"<<ok;
}

int main()
{
    int test_kiya; cin>>test_kiya;
    while(test_kiya--)
    invest_good();
    return 0;
}