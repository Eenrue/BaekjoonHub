#include <bits/stdc++.h>
using namespace std;

int sae[129][129];
int n;
int res[2];

void count(int x, int y, int s){
    bool same=true;
    int fir=sae[x][y];
    for(int i=x;i<x+s;i++){
        for(int j=y;j<y+s;j++){
            if(sae[i][j]!=fir)same=false;
        }
    }
    if(same){
        res[fir]++;
        return;
    }
    else{
        count(x,y,s/2);
        count(x+s/2,y,s/2);
        count(x,y+s/2,s/2);
        count(x+s/2,y+s/2,s/2);
    }
}

int main()
{
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>sae[i][j];
        }
    }
    count(0,0,n);
    cout<<res[0]<<'\n'<<res[1];
}
