#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int mp[9][9];
int flag=0;
void check(){
    int x=-1;
    int y=-1;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(mp[i][j]==0&&x==-1){
                x=i;
                y=j;
            }
        }
    }
    if(x==-1){
        flag=1;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<mp[i][j];
            }
            cout<<'\n';
        }
        return;
    }

    bool vis[10]={};
    for(int i=0;i<9;i++){
        if(mp[i][y]) vis[mp[i][y]]=true;
        if(mp[x][i]) vis[mp[x][i]]=true;
    }
    int nx=x/3;
    int ny=y/3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(mp[nx*3+i][ny*3+j])vis[mp[nx*3+i][ny*3+j]]=true;
        }
    }



    for(int i=1;i<=9;i++){
        if(vis[i]==false){
            mp[x][y]=i;
            check();
            if(flag)return;
        }
    }
    mp[x][y]=0;
}

int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    for(int i=0;i<9;i++){
        string str;
        cin>>str;
        for(int j=0;j<9;j++){
            mp[i][j]=int(str[j])-int('0');
        }
    }

    check();

}
