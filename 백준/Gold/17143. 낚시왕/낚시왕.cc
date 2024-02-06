#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;
int R,C,M;
int mp[101][101];
struct shark;
vector<shark> sv;
int dxy[4][2]={{-1,0},{1,0},{0,1},{0,-1}};//위 아래 오른쪽 왼쪽

struct shark{
    int r;
    int c;
    int s;
    int d;
    int z;
    bool live=true;
};

void Move(int k){
    shark cur=sv[k];
    int r=sv[k].r;
    int c=sv[k].c;
    int s=cur.s;
    int d=cur.d;
    if(d==1||d==2){
        s%=((R-1)*2);
    }
    else{
        s%=((C-1)*2);
    }
    for(int i=0;i<s;i++){
        int nr=r+dxy[d-1][0];
        int nc=c+dxy[d-1][1];
        if(nr<0||nc<0||nr>=R||nc>=C){
            if(d==1)d=2;
            else if(d==2)d=1;
            else if(d==3)d=4;
            else if(d==4)d=3;
            nr=r+dxy[d-1][0];
            nc=c+dxy[d-1][1];
        }
        r=nr;
        c=nc;
    }
    sv[k].r=r;
    sv[k].c=c;
    sv[k].d=d;
}

void Set(){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++)mp[i][j]=0;
    }
    for(int i=1;i<=M;i++){
        if(sv[i].live==false)continue;
        int r=sv[i].r;
        int c=sv[i].c;
        if(mp[r][c]){
            int bf=mp[r][c];
            if(sv[bf].z>sv[i].z){
                mp[r][c]=bf;
                sv[i].live=false;
            }
            else{
                mp[r][c]=i;
                sv[bf].live=false;
            }
        }
        else{
            mp[r][c]=i;
        }
    }

}

int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>R>>C>>M;
    int id=0;
    sv.push_back({-1,-1,-1,-1,-1});
    for(int i=0;i<M;i++){
        int r,c,s,d,z;
        cin>>r>>c>>s>>d>>z;
        r--;
        c--;
        id++;
        mp[r][c]=id;
        sv.push_back({r,c,s,d,z});
    }

    int day=-1;
    int ans=0;
    while(day<C-1){
        day++;
        for(int i=0;i<R;i++){
            if(mp[i][day]){
                ans+=sv[mp[i][day]].z;
                sv[mp[i][day]].live=false;
                break;
            }
        }
        for(int i=1;i<=M;i++){
            if(sv[i].live==false)continue;
            Move(i);
        }
        Set();
    }

    cout<<ans;


}

