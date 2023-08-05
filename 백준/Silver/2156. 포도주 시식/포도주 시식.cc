#include <bits/stdc++.h>

using namespace std;

int num=0;
int sta[10002];
int ma[10002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>num;
    int ans;

    for(int i=0;i<num;i++){
        cin>>sta[i];
    }
    for(int x=0;x<num;x++){
        if(x==0)ma[0]=sta[0];
        else if(x==1)ma[1]=sta[0]+sta[1];
        else if(x==2)ma[2]=max(sta[0]+sta[2],sta[1]+sta[2]);
        else if(x==3)ma[3]=max(ma[x-2]+sta[x],ma[x-3]+sta[x-1]+sta[x]);
        else{
            ma[x]=max(max(ma[x-2]+sta[x],ma[x-3]+sta[x-1]+sta[x]),ma[x-4]+sta[x-1]+sta[x]);
        }
    }

    if(num<=2) cout<<ma[num-1];
    else cout<<max(ma[num-1],ma[num-2]);

    return 0;
}
