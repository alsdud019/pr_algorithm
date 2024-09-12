#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    // phone_book={"234","12","456","134","4578","3456","235","2357"};
    bool answer = true;
    map<string, int> m;
    
    sort(phone_book.begin(), phone_book.end());
    for (string phone:phone_book){
        m[phone]++;
    }
    
    for (int i=0; i<phone_book.size(); i++){
        string number="";
        for (int j=0; j<phone_book[i].size()-1; j++){
            number+=phone_book[i][j];
            if (m[number]) return false;
        }
        
    }
    
    return answer;
}