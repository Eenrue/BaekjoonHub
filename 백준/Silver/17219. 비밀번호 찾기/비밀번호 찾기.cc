#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    map<string,string> mp;
    for(int i=0;i<n;i++){
        string str1,str2;
        cin>>str1>>str2;
        mp[str1]=str2;
    }
    for(int i=0;i<m;i++){
        string str;
        cin>>str;
        cout<<mp[str]<<"\n";
    }
    return 0;
}