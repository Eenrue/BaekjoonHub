#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

vector<int> v;


void post(int s,int e){
    if(s>=e)return;
    if(s+1==e){
        cout<<v[s]<<'\n';
        return;
    }
    int idx = s + 1;
	while(idx < e){
		if(v[s] < v[idx]) break;
		idx++;
	}
    post(s+1,idx);
    post(idx,e);
    cout<<v[s]<<'\n';
}
int main()
{
    int n;
    while(cin>>n){
        v.push_back(n);
    }
    post(0,v.size());
    return 0;
}
