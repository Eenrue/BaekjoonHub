#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t;
    cin>>t;
    for(int i=0;i<t;i++){

        int n;
        cin>>n;
        vector<string> v;
        for(int j=0;j<n;j++){
            string str;
            cin>>str;
            v.push_back(str);
        }
        if(n>32){
            cout<<"0\n";
            continue;
        }
        int ans=100;
        for(int j=0;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    int tmp=0;
                    for(int m=0;m<4;m++){
                        if(v[j][m]!=v[k][m])tmp++;
                        if(v[j][m]!=v[l][m])tmp++;
                        if(v[k][m]!=v[l][m])tmp++;
                    }
                    ans=min(ans,tmp);
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
