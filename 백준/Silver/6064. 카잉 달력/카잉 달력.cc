#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    return b==0? a :gcd(b,a%b);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int m,n,x,y;
        cin>>m>>n>>x>>y;
        int ans=x;
        int flag=0;
        int ma=(m*n)/gcd(m,n);
        while(ans<=ma){
            if(ans%n==y){
                flag=1;
                break;
            }
            if(ans%n==0&&y==n){
                flag=1;
                break;
            }
            ans+=m;
        }
        if(flag)cout<<ans<<"\n";
        else cout<<"-1\n";
    }
}