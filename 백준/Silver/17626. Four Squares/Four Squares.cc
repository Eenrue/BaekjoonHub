#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin>>n;
    vector<int> v1;
    for(int t=1;pow(t,2)<50001;t++){
        if(pow(t,2)==n){
            cout<<"1";
            return 0;
        }
        v1.push_back(pow(t,2));
    }
    vector<int> v2;
    for(int i=0;i<v1.size();i++){
        for(int j=i;j<v1.size();j++){
            if(v1[i]+v1[j]==n){
                cout<<"2";
                return 0;
            }
            v2.push_back(v1[i]+v1[j]);
        }
    }
    vector<int> v3;
    for(int i=0;i<v1.size();i++){
        for(int j=i;j<v2.size();j++){
            if(v1[i]+v2[j]==n){
                cout<<"3";
                return 0;
            }
            v3.push_back(v1[i]+v2[j]);
        }
    }
    vector<int> v4;
    for(int i=0;i<v1.size();i++){
        for(int j=i;j<v3.size();j++){
            if(v1[i]+v3[j]==n){
                cout<<"4";
                return 0;
            }
            v4.push_back(v1[i]+v3[j]);
        }
    }
    return 0;
}