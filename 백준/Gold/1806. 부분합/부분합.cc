#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int n,s;
int ans=INF;
vector<int> v;
int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>s;

    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    int p1=0;
    int p2=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        while(cnt<s && p2<n){
            cnt+=v[p2];
            p2++;
        }
        if(cnt>=s){
            ans=min(ans,p2-p1);
        }
        cnt-=v[p1];
        p1++;
    }
    if(ans==INF)cout<<'0';
    else cout<<ans;

}
