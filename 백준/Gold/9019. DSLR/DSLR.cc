#include <bits/stdc++.h>
using namespace std;

int D(int x){
    return (x*2)%10000;
}
int S(int x){
    if(x==0) return 9999;
    else return x-1;
}
int L(int x){
    x*=10;
    int tmp=x/10000;
    x%=10000;
    x+=tmp;
    return x;
}
int R(int x){
    int tmp=x%10;
    x/=10;
    x+=tmp*1000;
    return x;
}

void bfs(int a, int b){
    bool visit[10000]={};
    queue<pair<int,string>> q;
    q.push({a,""});

    visit[a]=true;
    while(!q.empty()){
        int x=q.front().first;
        string str=q.front().second;
        if(x==b) {
                cout<<str<<'\n';
                return;
        }

        q.pop();
        if(!visit[D(x)]){
            visit[D(x)]=true;
            q.push({D(x),str+"D"});
        }
        if(!visit[S(x)]){
            visit[S(x)]=true;
            q.push({S(x),str+"S"});
        }
        if(!visit[L(x)]){
            visit[L(x)]=true;
            q.push({L(x),str+"L"});
        }
        if(!visit[R(x)]){
            visit[R(x)]=true;
            q.push({R(x),str+"R"});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int A,B;
        cin >>A>>B;
        bfs(A,B);
    }
    return 0;
}
