#include <string>
#include <vector>

using namespace std;

int MAP[101][101]={0,};

int rotation(int x1, int y1, int x2, int y2){
    int mini=1e9;
    int first=MAP[x1][y1];
    
    //왼쪽벽
    for (int i=x1+1; i<=x2; i++) {
        MAP[i-1][y1]=MAP[i][y1];
        mini=min(mini, MAP[i-1][y1]);
    }
    //아랫면
    for(int i=y1+1; i<=y2; i++) {
        MAP[x2][i-1]=MAP[x2][i];
        mini=min(mini, MAP[x2][i-1]);
    }
    
    //오른쪽벽
    for(int i=x2-1; i>=x1; i--) 
    {
        MAP[i+1][y2]=MAP[i][y2];
        mini=min(mini, MAP[i+1][y2]);
    }
    
    //위쪽면
    for (int i=y2-1; i>y1; i--) {
        MAP[x1][i+1]=MAP[x1][i];
        mini=min(mini, MAP[x1][i+1]);
    }
    
    MAP[x1][y1+1]=first;
    mini=min(mini, MAP[x1][y1+1]);
    
    return mini;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    int num=1;
    for (int i=1; i<=rows; i++){
        for (int j=1; j<=columns; j++){
            MAP[i][j]=num;
            num++;
        }
    }
    
    for (int i=0; i<queries.size(); i++){
        vector<int> query=queries[i];
        int x1=query[0];
        int y1=query[1];
        int x2=query[2];
        int y2=query[3];
        
        int min_result=rotation(x1, y1, x2, y2);
        
        answer.push_back(min_result);
        
    }
    
    return answer;
}