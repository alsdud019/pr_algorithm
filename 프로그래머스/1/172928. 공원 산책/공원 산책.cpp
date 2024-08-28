#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    map<char, int> m ={{'N',0},{'S',1},{'W',2},{'E',3}};
    int dx[]={0,0,-1,1};
    int dy[]={-1,1,0,0};
    
    int st_x=-1;
    int st_y=-1;
    
    int x=park[0].size();
    int y=park.size();
    
    for (int i=0; i<park.size(); i++){
        for (int j=0; j<park[i].size(); j++){
            if (park[i][j]=='S') {
                st_x=j;
                st_y=i;
                break;
            }            
        }
    }
    
    for (auto route:routes){
        int direct_idx=m[route[0]];
        int goal_x=st_x+dx[direct_idx]*(route[2]-'0');
        int goal_y=st_y+dy[direct_idx]*(route[2]-'0');
        
        bool check=true;
        int num=route[2]-'0';
        
        // cout<<goal_y<<" "<<goal_x<<endl;
        // cout<<st_y<<" "<<st_x<<endl;
        
        int nx=st_x;
        int ny=st_y;
        
        for (int i=0; i<num; i++){
            nx+=dx[direct_idx];
            ny+=dy[direct_idx];
            
            if (nx>=x|| ny>=y||nx<0 || ny<0)
            {
                check=false;
                break;   
            }
            
            if (park[ny][nx]=='X') {
                check=false;
                break;  
            }
                
            
            cout<<ny<<" "<<nx<<endl;
            // if (goal_x==nx && goal_y==ny) break;
        }
        
        if (check) {
            st_x=goal_x; st_y=goal_y;
            
        }
        
        answer={st_y,st_x};
        // cout<<st_y<<" "<<st_x<<endl;
    }
    
    return answer;
}