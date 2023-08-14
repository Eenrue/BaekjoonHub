#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    string str;
    cin>>str;
    int flag=0;
    int tmp=0;
    int ans=0;

    for(int i=0;i<str.size();i++){
        if(flag==0&&str[i]=='I'){
            flag=-1;
        }
        else if(flag==-1&&str[i]=='O'){
            flag=1;
        }
        else if(flag==1&&str[i]=='I'){
            flag=-1;
            tmp++;
            if(tmp>=n) ans++;
        }
        else if(str[i]=='I'){
            flag=-1;
            tmp=0;
        }
        else{
            flag=0;
            tmp=0;
        }
    }

    cout<<ans;
}
