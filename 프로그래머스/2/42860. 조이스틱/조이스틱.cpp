#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    int answer = 0;
    int move=name.size()-1;
    int n=name.size();
    for(int i=0;i<n;i++){
        answer+=min(name[i] - 'A','Z' - name[i] +1);
        int ind=i+1;
        while(ind<n&& name[ind] == 'A'){
            ind++;
        }
        move=min(move,i+n-ind+min(i,n-ind));
    }

    return answer+move;
}