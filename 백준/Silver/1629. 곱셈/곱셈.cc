#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,tmp;
ll cal(ll x){
    if(x==0) return 1;
    if(x==1) return a%c;

    tmp=(cal(x/2))%c;
    if(x%2==0) return tmp*tmp%c;
    return ((tmp*tmp)%c*cal(x%2))%c;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>>a>>b>>c;
    cout<<cal(b);
    return 0;
}