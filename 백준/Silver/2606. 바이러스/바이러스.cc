#include <bits/stdc++.h>

using namespace std;

int num=0;
int link=0;
bool bir[102];
bool rel[102][102];
int ma[10002];

void bfs(){
    deque<int> dq;

    dq.push_back(1);
    int p;

    while(dq.size()){
        p=dq.front();
        dq.pop_front();
        for(int i=1;i<=num;i++){
            if(rel[p][i]==true&&!bir[i]){
                bir[i]=true;
                dq.push_back(i);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>num;
    cin>>link;
    int ans=0;
    bir[1]=true;

    for(int i=0;i<link;i++){
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        rel[tmp1][tmp2]=true;
        rel[tmp2][tmp1]=true;
    }

    bfs();

    for(int i=1;i<=num;i++){
        if(bir[i])ans++;
    }
    cout<<ans-1;
    return 0;
}
