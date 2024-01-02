#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

char t[3073][6145];
int n;

void star(int x,int y, int cnt){
    if(cnt==3){
        t[y][x]='*';
        t[y+1][x-1]='*';
        t[y+1][x+1]='*';
        for(int i=0;i<5;i++){
            t[y+2][x-2+i]='*';
        }
        return;
    }
    star(x,y,cnt/2);
    star(x-cnt/2,y+cnt/2,cnt/2);
    star(x+cnt/2,y+cnt/2,cnt/2);
    return;
}

int main()
{

    cin>>n;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n*2;j++){
            t[i][j]=' ';
        }
    }
    int tmp=n/3;

    star(n-1,0,n);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=2*n;j++){
            cout<<t[i][j];
        }
        cout<<'\n';
    }
}
