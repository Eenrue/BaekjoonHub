#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

bool vis[11][11][11][11];

int ans=INF;
int n,m;
int mp[11][11];
int dxy[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

struct ball{
    int rx,ry;
    int bx,by;
    int cnt;
};


void flip(int &y,int &x, int &dis, int cnt){
    while(mp[y+dxy[cnt][0]][x+dxy[cnt][1]]!='#'&&mp[y][x]!='O'){
        y+=dxy[cnt][0];
        x+=dxy[cnt][1];
        dis++;
    }
}

void bfs(ball sb){
    queue<ball> q;
    q.push(sb);
    vis[sb.ry][sb.rx][sb.by][sb.bx]=true;
    while(!q.empty()){

        ball b=q.front();
        //cout<<b.ry<<' '<<b.rx<<'\n';
        q.pop();
        if(b.cnt>=10)break;
        for(int i=0;i<4;i++){
            ball tmpb=b;
            int rx=tmpb.rx;
            int ry=tmpb.ry;
            int bx=tmpb.bx;
            int by=tmpb.by;
            int ncnt=tmpb.cnt+1;
            int rd=0;
            int bd=0;
            flip(ry,rx,rd,i);
            flip(by,bx,bd,i);
            if(mp[by][bx]=='O')continue;
            if(mp[ry][rx]=='O'){
                cout<<ncnt;
                return;
            }
            if(ry==by&&rx==bx){
                if(rd<bd){
                    by-=dxy[i][0];
                    bx-=dxy[i][1];
                }
                else{
                    ry-=dxy[i][0];
                    rx-=dxy[i][1];
                }
            }
            if(vis[ry][rx][by][bx]) continue;
            vis[ry][rx][by][bx]=true;
            tmpb={rx,ry,bx,by,ncnt};
            q.push(tmpb);
        }
    }
    cout<<"-1";
}

int main()
{
    ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    ball b;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            if(c=='R'){
                b.ry=i;
                b.rx=j;
                c='.';
            }
            else if(c=='B'){
                b.by=i;
                b.bx=j;
                c='.';
            }
            mp[i][j]=c;
        }
    }
    b.cnt=0;
    bfs(b);
}
