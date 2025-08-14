#include <string>
#include <vector>
#include <iostream>

using namespace std;

//아래, 오른, 대각위
int dx[]={0,1,-1};
int dy[]={1,0,-1};

int arr[1001][1001]={0,};

vector<int> solution(int n) {
    vector<int> answer;
    
    
    int y=0; int x=0;
    int dir=0;
    arr[y][x]=1;
    int cnt=2;
    
    while(cnt<=n*(n+1)/2){
        
        int ny=y+dy[dir];
        int nx=x+dx[dir];
        
        if (ny<0 || nx<0 || ny>n-1 || nx>n-1|| arr[ny][nx]>0){
            dir=(dir+1)%3;
            continue;
        }
        
        arr[ny][nx]=cnt++;
        y=ny;
        x=nx;
        
        
    }
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (arr[i][j]!=0) answer.push_back(arr[i][j]);
        }
        
    }
    
    
    return answer;
}