#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int keypad[][9]={{3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
    
    int l_x=0;
    int l_y=3;
    int r_x=2;
    int r_y=3;
    
    for (int i=0; i<numbers.size(); i++){
        int num=numbers[i];
        //왼손으로 눌러야할 때
        if (num==1 ||num==4 ||num==7){
            l_x=keypad[num][1];
            l_y=keypad[num][0];
            answer+='L';
        }
        else if (num==3 ||num==6 ||num==9){
            r_x=keypad[num][1];
            r_y=keypad[num][0];
            answer+='R';
        }
        else {
            int key_x=keypad[num][1];
            int key_y=keypad[num][0];
            
            int diff_l=abs(key_x-l_x)+abs(key_y-l_y);
            int diff_r=abs(key_x-r_x)+abs(key_y-r_y);
            
            // cout<<diff_l<<" "<<diff_r<<endl;
            
            if (diff_l<diff_r) {
                l_x=keypad[num][1];
                l_y=keypad[num][0];
                answer+='L';
            }
            else if (diff_l>diff_r){
                r_x=keypad[num][1];
                r_y=keypad[num][0];
                answer+='R';
            }
            
            else {
                string now=(hand=="left")? "L" :"R";
                if (now=="L") {
                    l_x=keypad[num][1];
                    l_y=keypad[num][0];
                    answer+=now;
                }
                else {
                    r_x=keypad[num][1];
                    r_y=keypad[num][0];
                    answer+=now;
                }
            }
            
            
            
            
        }
    }
    
    return answer;
}