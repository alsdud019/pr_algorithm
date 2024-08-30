#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    // bandage={5, 3, 2};
    // health=30;
    // attacks={{1, 1}, {4, 12}};
    int answer = 0;
    int time=bandage[0];
    int recover=bandage[1];
    int plus_recover=bandage[2];
    
    int running_time=attacks[attacks.size()-1][0];
    
    int monster[1001]={0,};
    for (int i=0; i<attacks.size(); i++){
        monster[attacks[i][0]]=attacks[i][1];
    }
    
    int sequence=0;
    int total=health;
    for (int i=1; i<=running_time; i++){
        // cout<<total<<endl;
        
        if (total<=0) return -1;
        //몬스터 공격 
        if (monster[i]!=0) {
            total-=monster[i];
            sequence=0;
            continue;
        }
        sequence+=1; //연속성 카운트 
        
        if (sequence==time){
            total+=recover;
            total+=plus_recover;
            if (total>=health) total=health;
            sequence=0;
            continue;
        }
        
        
        if (total>=health) {total=health; continue;}
        total+=recover; // 1초당 올라가능 회복량 

    }
    
    cout<<total<<endl;
    if (total<=0) return -1;
    
    return total;
}