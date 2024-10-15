#include <string>
using namespace std;

int dy[]={-1,1,0,0};
int dx[]={0,0,1,-1};
int MAP[12][12][4];

int direction(char a){
    if (a=='U') return 0;
    else if (a=='D') return 1;
    else if (a=='R') return 2;
    else if (a=='L') return 3;
}

int reversedir(int n){
    if (n==0) return 1;
    else if (n==1) return 0;
    else if (n==2) return 3;
    else if (n==3) return 2;
}

int solution(string dirs) {
    //dirs="UUUUUDDDDD";
    int answer = 0;
    int stY=5;
    int stX=5;
    
    
    for (int i=0; i<dirs.size(); i++){
        char now=dirs[i];
        int d=direction(now);
        int rd=reversedir(d);
        
        int ny=dy[d]+stY;
        int nx=dx[d]+stX;
    
        //벗어나는 경우
        if (nx<0 || ny<0|| nx>=11 || ny>=11) continue;
        
        //방문했던 곳이라면 
        if (!MAP[ny][nx][rd] && !MAP[stY][stX][d]) {
            MAP[stY][stX][d]=1;
            MAP[ny][nx][rd]=1;
            answer++;
        }

        stX=nx;
        stY=ny;
    }
    
    return answer;
}