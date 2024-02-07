#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sizes_rows는 2차원 배열 sizes의 행 길이, sizes_cols는 2차원 배열 sizes의 열 길이입니다.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int answer = 0;
    int n1=0; //min
    int n2=0; //max
    for(int i=0;i<sizes_rows;i++){
        int t1,t2;
        if(sizes[i][0]<=sizes[i][1]){
            t1=sizes[i][0];
            t2=sizes[i][1];
        }
        else{
            t1=sizes[i][1];
            t2=sizes[i][0];
        }
        if(n1<t1)n1=t1;
        if(n2<t2)n2=t2;
    }
    answer=n1*n2;
    return answer;
}