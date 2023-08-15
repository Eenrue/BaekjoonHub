#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    bool arr[21];
    for(int i=0;i<n;i++){
        string str;
        int num;
        cin>>str;
        if(str=="all"){
            for(int j=1;j<21;j++){
                arr[j]=true;
            }
        }
        else if(str=="empty"){
            for(int j=1;j<21;j++){
                arr[j]=false;
            }
        }
        else if(str=="add"){
            cin>>num;
            arr[num]=true;
        }
        else if(str=="remove"){
            cin>>num;
            arr[num]=false;
        }
        else if(str=="check"){
            cin>>num;
            cout<<arr[num]<<'\n';
        }
        else if(str=="toggle"){
            cin>>num;
            arr[num]^=1;
        }

    }
    return 0;
}