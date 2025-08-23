#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> vec;

int check(string start){
    int answer=1e9;
    for (int i=0; i<vec.size(); i++){
        int hour=stoi(vec[i].substr(0,2));
        int minute=stoi(vec[i].substr(3,2));
        
        int start_hour=stoi(start.substr(0,2));
        int start_minute=stoi(start.substr(3,2));
        
        int total=hour*60+minute;
        int start_total=start_hour*60+start_minute;
        
        // cout<<total+10<<" "<<start_total<<'\n';
        if (total+10<=start_total) answer=min(answer, i);
        // if (hour<=start_hour && minute+10<=start_minute) answer=min(answer, i);
    }
    
    // cout<<answer<<'\n';
    if (answer!=1e9) return answer;
    else return -1;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    sort(book_time.begin(), book_time.end());
    
    // string start=book_time[0][0];
    // string end=book_time[0][1];
    vec.push_back(book_time[0][1]);
    answer++;
    
    for (int i=1; i<book_time.size(); i++){
        int idx=check(book_time[i][0]);
        // cout<<idx<<" ";
        if ((idx+1)==0) {
            answer++;
            vec.push_back(book_time[i][1]);
        }
        else {
            vec[idx]=book_time[i][1];
        }
        
        
    }
    
    return answer;
}