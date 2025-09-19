#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

void crane(vector<string> &storage, char now){
    for (int i=0; i<storage.size(); i++){
        for (int j=0; j<storage[0].size(); j++){
            if (storage[i][j]==now){
                storage[i][j]='0';
            }
        }
    }
}

int dy[]={0,0,-1,1};
int dx[]={1,-1,0,0};

int visited[51][51]={0,};

void car(vector<string> &storage, char target){
    vector<pair<int, int>> vec;
    memset(visited, 0, sizeof(visited));
    
    for (int i=0; i<storage.size(); i++){
        for (int j=0; j<storage[0].size(); j++){
            
            //가장자리에서 시작 
            if (i!=0 && j!=0 && i!=storage.size()-1 && j!= storage[0].size()-1) continue;
            
            if (storage[i][j]=='0'){
                queue<pair<int, int>> q;
                q.push({i, j});

                while(!q.empty()){
                    pair<int, int> now=q.front(); q.pop();
                    
                    for (int k=0; k<4; k++){
                        int ny=now.first+dy[k];
                        int nx=now.second+dx[k];
                        
                        if (ny<0 || nx<0|| ny>storage.size()-1 || nx>storage[0].size()-1) continue;
                        
                        if (storage[ny][nx]=='0' && visited[ny][nx]==0){
                            q.push({ny, nx});
                            visited[ny][nx]=1;
                        }
                        else if (storage[ny][nx]==target && visited[ny][nx]==0){
                            vec.push_back({ny, nx});
                            visited[ny][nx]=1;
                        }
                        
                    }
                }
            }
            else if (storage[i][j]==target){
                vec.push_back({i, j});
                visited[i][j]=1;
            } 
        }
    }
    
    for (int i=0; i<vec.size(); i++){
        int y=vec[i].first;
        int x=vec[i].second;
        storage[y][x]='0';
    }
    
    
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    for (int i=0; i<requests.size(); i++){
        string request=requests[i];
        
        //글자수가 1개라면 
        if (request.size()==1){
            car(storage, request[0]);
        }
        //글자수가 2개라면
        else{
            char now=request[0];
            crane(storage,now);
        }
    }
    
    for (int i=0; i<storage.size(); i++){
        for (int j=0; j<storage[0].size(); j++){
            // cout<<storage[i][j];
            if (storage[i][j]=='0') continue;
            answer++;
        }
        // cout<<'\n';
    }
    
    
    return answer;
}