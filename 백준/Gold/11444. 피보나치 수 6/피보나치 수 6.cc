#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DIV 1000000007LL
ll n;
map<ll,ll> f;

ll fibo(ll n){
    if(n==0)return 0;
    if(n==1)return 1;
    if(n==2)return 1;
    if(f.count(n)>0)return f[n];

    if(n%2==0){
        ll n1=fibo(n/2);
        ll n2=fibo(n/2-1);
        return f[n]=(n1*(2LL*n2+n1))%DIV;
    }
    ll n1=fibo((n-1)/2);
    ll n2=fibo((n-1)/2+1);
    return f[n]=(n1*n1+n2*n2)%DIV;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    cout<<fibo(n);


    return 0;
}
