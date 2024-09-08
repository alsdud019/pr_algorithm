#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    vector<string> vec;
    
    for (int i=0; i<cities.size(); i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
    }
    
    if (cacheSize==0) return cities.size()*5;
    
    for (int i=0; i<cities.size(); i++){
        auto it=find(vec.begin(), vec.end(), cities[i]);
        
        //있을 때 
        if (it!=vec.end()){
            vec.erase(it);
            vec.push_back(cities[i]);
            answer+=1;
        }
        //없을때
        else {
            if (cacheSize<=vec.size()){
                vec.erase(vec.begin()+0);
                vec.push_back(cities[i]);
            }
            else{
                vec.push_back(cities[i]);
            }
            answer+=5;
        }
    }
    
    
    return answer;
}