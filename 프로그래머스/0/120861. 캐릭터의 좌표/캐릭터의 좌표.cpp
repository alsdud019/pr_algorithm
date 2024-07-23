#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    int x=0;
    int y=0;
    
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    
    int half_x=board[0]/2;
    int half_y=board[1]/2;
    
    for (int i=0; i<keyinput.size(); i++){

        
        if (keyinput[i]=="up" && y<half_y){x+=dx[0]; y+=dy[0];}
        else if (keyinput[i]=="down" && y>-half_y){x+=dx[1]; y+=dy[1];}
        else if (keyinput[i]=="left" && x>-half_x){x+=dx[2]; y+=dy[2];}
        else if (keyinput[i]=="right" && x<half_x){x+=dx[3]; y+=dy[3];}
         
    }
    
    return answer={x,y};
}