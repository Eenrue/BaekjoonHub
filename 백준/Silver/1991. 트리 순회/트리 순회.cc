#include <bits/stdc++.h>
using namespace std;

int n;
char tree[50][2];

void pre(int x){
    if(x<0) return;
    cout<<char(x+'A');
    pre(tree[x][0]);
    pre(tree[x][1]);
}
void in(int x){
    if(x<0) return;
    in(tree[x][0]);
    cout<<char(x+'A');
    in(tree[x][1]);
}
void post(int x){
    if(x<0) return;
    post(tree[x][0]);
    post(tree[x][1]);
    cout<<char(x+'A');
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;

    for(int i=0;i<50;i++){
        tree[i][0]=-1;
        tree[i][1]=-1;
    }

    for(int i=0;i<n;i++){
        char c1,c2,c3;
        cin>>c1>>c2>>c3;
        int tmp=int(c1-'A');
        int tmp1,tmp2;
        tmp1=int(c2-'A');
        tmp2=int(c3-'A');
        if(c2!='.') tree[tmp][0]=tmp1;
        if(c3!='.') tree[tmp][1]=tmp2;
    }
    pre(0);
    cout<<'\n';
    in(0);
    cout<<'\n';
    post(0);
    return 0;
}