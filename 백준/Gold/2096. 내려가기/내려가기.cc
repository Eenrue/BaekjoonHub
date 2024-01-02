#include <bits/stdc++.h>
using namespace std;
# define INF 987654321
typedef long long ll;

int mindp[3]={};
int maxdp[3]={};
int n;


int main()
{

    cin>>n;
    for(int i=0;i<n;i++){
        int inp1,inp2,inp3;
        cin>>inp1>>inp2>>inp3;
        if(i==0){
            mindp[0]=inp1;
            mindp[1]=inp2;
            mindp[2]=inp3;
            maxdp[0]=inp1;
            maxdp[1]=inp2;
            maxdp[2]=inp3;
            continue;
        }
        int tmp1=mindp[0]; int tmp2=mindp[2];
        mindp[0]=min(mindp[0],mindp[1])+inp1;
        mindp[2]=min(mindp[1],mindp[2])+inp3;
        mindp[1]=min(tmp1,min(mindp[1],tmp2))+inp2;
        tmp1=maxdp[0]; tmp2=maxdp[2];
        maxdp[0]=max(maxdp[0],maxdp[1])+inp1;
        maxdp[2]=max(maxdp[1],maxdp[2])+inp3;
        maxdp[1]=max(tmp1,max(maxdp[1],tmp2))+inp2;

    }

    cout<<max(max(maxdp[0],maxdp[1]),maxdp[2])<<' '<<min(min(mindp[0],mindp[1]),mindp[2]);
}
