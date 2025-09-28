#include <string>
#include <vector>

using namespace std;

vector<string> map;

bool same(char i, char a, char b, char c){
    return (a==b && b==c && i==a);
}

bool check(char c){
    for (int i=0; i<map.size(); i++){
        if (same(c, map[i][0], map[i][1], map[i][2])) return true; //가로
        else if (same(c,map[0][i], map[1][i], map[2][i] )) return true; //세로
    }
    //대각선
    if (same(c,map[0][0], map[1][1], map[2][2])) return true;
    else if (same(c,map[0][2], map[1][1], map[2][0])) return true;
    
    return false;
}

int solution(vector<string> board) {
    int answer = -1;
    
    map=board;
    
    int pre=0; int post=0;
    for (int i=0; i<board.size(); i++){
        for (int j=0; j<board[0].size(); j++){
            if (board[i][j]=='O') pre++;
            else if (board[i][j]=='X') post++;
        }
    }
    
    if (pre<3){
        if (pre==0 && post==0) return 1;
        else if (pre!=0 && (post==pre || post==pre-1)) return 1;
    }
    else{
        if (pre==3 && post==2) return 1;
        else if (pre==post){
            if (!check('O')) return 1;
        }
        
        else if (pre==post+1){
            if ( !check('X')) return 1;
        }
    }
    
    return 0;
    
    // return answer;
}