#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 987654321
int b,a;
int n,m;
int dxy[4][2]={{1,0},{0,1},{-1,0},{0,-1}};//북에서 시계
int mp[101][101]={};

struct rob{
    int y;
    int x;
    int dir;
};
vector<rob> v;


int main(){
    cin>>a>>b>>n>>m;
    v.push_back({0,0,0});
    for(int i=0;i<n;i++){
        int t1,t2;
        char c1;
        cin>>t1>>t2>>c1;
        int t3=0;
        if(c1=='N')t3=0;
        if(c1=='E')t3=1;
        if(c1=='S')t3=2;
        if(c1=='W')t3=3;
        v.push_back({t2,t1,t3});
        mp[t2][t1]=i+1;
    }
    bool wrong=false;

    for(int i=0;i<m;i++){
        int ind;
        char mes;
        int re;
        cin>>ind>>mes>>re;
        if(wrong)continue;
        if(mes=='L'){
            int bd=v[ind].dir;
            int nd=bd-re;
            nd%=4;
            if(nd<0)nd+=4;
            v[ind].dir=nd;
        }
        if(mes=='R'){
            int bd=v[ind].dir;
            int nd=bd+re;
            nd%=4;
            if(nd<0)nd+=4;
            v[ind].dir=nd;
        }
        if(mes=='F'){
            int by=v[ind].y;
            int bx=v[ind].x;
            mp[by][bx]=0;
            int ny,nx;
            for(int j=0;j<re;j++){
                ny=by+dxy[v[ind].dir][0];
                nx=bx+dxy[v[ind].dir][1];
                if(ny<1||nx<1||ny>b||nx>a){
                    cout<<"Robot "<<ind<<" crashes into the wall";
                    wrong=true;
                    break;
                }
                if(mp[ny][nx]!=0){
                    cout<<"Robot "<<ind<<" crashes into robot "<<mp[ny][nx];
                    wrong=true;
                    break;
                }
                by=ny;
                bx=nx;
            }
            v[ind].y=ny;
            v[ind].x=nx;
            mp[ny][nx]=ind;
        }
    }
    if(!wrong)cout<<"OK";
}
