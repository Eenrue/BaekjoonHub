#include <bits/stdc++.h>

using namespace std;

int heap[400002];

int ind=0;

void ins(int n){
    heap[++ind]=n;
    int chi=ind;
    int par=ind/2;
    while(par!=0){
        if(heap[chi]<heap[par]){
            int tmp=heap[chi];
            heap[chi]=heap[par];
            heap[par]=tmp;
            chi/=2;
            par/=2;
        }
        else break;
    }
}
void del(){
    if(ind==0){
        cout<<"0\n";
        return;
    }
    int last=heap[ind];
    cout<<heap[1]<<'\n';
    heap[1]=last;
    heap[ind--]=0;
    int par=1;
    int ch1=par*2;
    int ch2=par*2+1;
    while(heap[ch1]!=0){
        if(heap[par]>min(heap[ch1],heap[ch2])&&heap[ch2]!=0){ // ch2
            int mini=min(heap[ch1],heap[ch2]);
            if(heap[ch1]==mini){
                heap[ch1]=heap[par];
                heap[par]=mini;
                par=ch1;
            }
            else{
                heap[ch2]=heap[par];
                heap[par]=mini;
                par=ch2;
            }
            ch1=par*2;
            ch2=par*2+1;
        }
        else if(heap[par]>heap[ch1]){
            int mini=heap[ch1];
            heap[ch1]=heap[par];
            heap[par]=mini;
            par=ch1;
            ch1=par*2;
            ch2=par*2+1;
        }
        else break;
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin>>num;

    for(int i=0;i<num;i++){
        int inp;
        cin>>inp;
        if(inp==0) del();
        else ins(inp);
    }


    return 0;
}
