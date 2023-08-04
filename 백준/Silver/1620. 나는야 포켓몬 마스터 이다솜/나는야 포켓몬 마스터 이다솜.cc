#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<string,int> map1;
    map<int,string> map2;
    int n,m; cin >> n >> m;

    for(int i=1;i<n+1;i++){
        string inp;
        cin>>inp;
        map1.insert(make_pair(inp,i));
        map2.insert(make_pair(i,inp));
    }
    for(int i=0;i<m;i++){
        string inp;
        cin>>inp;
        char start=inp[0];
        if(start<='9'){
            int tmp=stoi(inp);
            cout<< map2[tmp]<<'\n';
        }
        else{
            cout<<map1[inp]<<'\n';
        }
    }

    return 0;
}
