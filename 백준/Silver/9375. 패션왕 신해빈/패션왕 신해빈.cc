#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        map<string,int> m;
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            string str1;
            string str2;
            cin>>str1>>str2;
            m[str2]++;
        }
        vector<int> v;
        for(auto iter=m.begin();iter!=m.end();iter++){
            v.push_back(iter->second);
        }
        int ans=1;
        for(int j=0;j<v.size();j++){
            ans*=v[j]+1;
        }
        cout<<--ans<<'\n';
    }
    return 0;
}
