///********************** Bismillahir Rahmanir Rahim *****************///
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
///************************** Area of spybit *************************///
/*
                             01    01
                            1010101010
                           010101010101
                        110101010101010101
                           0          0
                          0            0
                          0     **     0
                           0          0
                            0        0
                        *1111000000001111*
                        010            010
                        010            010
                        010            010
                        010            010
                        010            010
                        010            010
                              #spybit
*/
///*********************** Template Start Here ***********************///
///************************ C o n t a i n e r ************************///
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef set<int> si;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef tree< long long, null_type, less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update > ordered_set;

///**************************** M a r c o ****************************///
#define f first
#define s second
#define endl '\n'
#define sp <<" "<<
#define pb push_back
#define MOD 1000000007
#define gcd(a,b) __gcd(a,b)
#define fora(a) for(auto u:a)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define test int tc; cin>>tc; while(tc--)
#define forn(i,n) for(auto i=0; i<n; i++)
#define printm(a) {for(auto u:a) cout<<u.f sp u.s<<endl;}
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define abid() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction(a) cout.unsetf(ios::floatfield); cout.precision(a); cout.setf(ios::fixed,ios::floatfield);

///**************************** C o n s t ****************************///
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 900000000000000000;

///************************ Template End Here ************************///

int main()
{
    abid();

    test
    {
        int n;
        cin>>n;

        cout<< ((n>24) ? "YES" : "NO")<<endl;
    }

    return 0;
}

