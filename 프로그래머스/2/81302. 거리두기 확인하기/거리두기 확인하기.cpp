#include <string>
#include <vector>

using namespace std;

int dy1[]={1,-1,0,0};
int dx1[]={0,0,1,-1};

int dy2[]={-1,-1,1,1};
int dx2[]={-1,1,-1,1};

int dy3[]={-2,2,0,0};
int dx3[]={0,0,-2,2};

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (int rooms=0; rooms<places.size(); rooms++){
        vector<string> room=places[rooms];
        
        int toggle=false;
        for (int i=0; i<room.size(); i++){
            for (int j=0; j<room[i].size(); j++){
                if (room[i][j]=='P'){
                    
                    //상하좌우
                    for (int k=0; k<4; k++){
                        int ny=dy1[k]+i;
                        int nx=dx1[k]+j;
                        
                        if (ny<0 || nx<0 || ny>4 || nx>4) continue;
                        if (room[ny][nx]=='P') {
                            toggle= true;
                            break;
                        }
                    }
                    
                    if (!toggle){
                        for (int k=0; k<4; k++){
                            int ny=dy2[k]+i;
                            int nx=dx2[k]+j;
                            if (ny<0 || nx<0 || ny>4 || nx>4) continue;
                            if (room[ny][nx]=='P'){
                                if (room[ny][j]!='X' || room[i][nx]!='X'){
                                    toggle=true;
                                    break;
                                }
                            }
                        }
                    }
                    if (!toggle){
                        for (int k=0; k<4; k++){
                            int ny=dy3[k]+i;
                            int nx=dx3[k]+j;
                            if (ny<0 || nx<0 || ny>4 || nx>4) continue;
                            if (room[ny][nx]=='P'){
                                if (room[(ny+i)/2][(nx+j)/2]!='X'){
                                    toggle=true;
                                    break;
                                }
                            }
                        }
                    }
                    else break;
                }
            }
            if (toggle) break;
        }
        
        if (toggle) answer.push_back(!toggle);
        else answer.push_back(!toggle);
        
    }
    
    return answer;
}