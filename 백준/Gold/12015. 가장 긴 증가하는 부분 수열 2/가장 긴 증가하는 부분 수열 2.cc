#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int n;
int inp[1000001];
vector<int> v;
int ind=0;


int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inp[i];
        if(v.size()==0){v.push_back(inp[i]); continue;}
        int ind = lower_bound(v.begin(),v.end(),inp[i])-v.begin();
        if(ind == v.size()) v.push_back(inp[i]);
        else{
            v[ind]=inp[i];
        }
    }
    printf("%d\n",v.size());
}
