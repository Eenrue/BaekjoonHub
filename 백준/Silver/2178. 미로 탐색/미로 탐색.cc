#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

int n,m;
int miro[102][102];
int score[102][102];

void bfs(){
    deque<pair<int,int>> dq;
    dq.push_back({1,1});

    while(1){
        pair<int,int> f=dq.front();
        dq.pop_front();
        if(f.first==n&&f.second==m) return;
        if(miro[f.first+1][f.second]&&f.first<=n){
            if(!score[f.first+1][f.second]){
                score[f.first+1][f.second]=score[f.first][f.second]+1;
                dq.push_back({f.first+1,f.second});
            }
        }
        if(miro[f.first][f.second+1]&&f.second<=m){
            if(!score[f.first][f.second+1]){
                score[f.first][f.second+1]=score[f.first][f.second]+1;
                dq.push_back({f.first,f.second+1});

            }
        }
        if(miro[f.first-1][f.second]){
            if(!score[f.first-1][f.second]){
                score[f.first-1][f.second]=score[f.first][f.second]+1;
                dq.push_back({f.first-1,f.second});
            }
        }
        if(miro[f.first][f.second-1]){
            if(!score[f.first][f.second-1]){
                score[f.first][f.second-1]=score[f.first][f.second]+1;
                dq.push_back({f.first,f.second-1});
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    score[1][1]=1;

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        string tmp;
        cin>>tmp;
        for(int j=0;j<=m-1;j++){
            miro[i][j+1]=int(tmp[j])-'0';
        }
    }
    bfs();
    cout<<score[n][m];
    return 0;
}