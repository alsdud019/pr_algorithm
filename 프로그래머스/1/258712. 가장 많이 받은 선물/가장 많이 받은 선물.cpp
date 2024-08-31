#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include <algorithm>


using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int gift[51][51]={0,};
    map<string, int> friend_name;
    map<string, pair<int, int>> gisu;
    int arr[51]={0,};
    
    for (int i=0; i<friends.size(); i++){
        friend_name[friends[i]]=i;
    }
    
    for (int i=0; i<gifts.size(); i++){
        stringstream ss(gifts[i]);
        
        string from, to;
        ss>>from>>to;
        
        int from_idx=friend_name[from];
        int to_idx=friend_name[to];
        gift[from_idx][to_idx]++; 
        
        gisu[from].first++;
        gisu[to].second++;
    }
    
    for (string from: friends){
        for (string to:friends){
            if (from==to) continue;
            int from_idx=friend_name[from];
            int to_idx=friend_name[to];
            
            //내가 선물을 더 많이 준경우
            if (gift[from_idx][to_idx]>gift[to_idx][from_idx]){
                arr[from_idx]++;
            }
            else if (gift[from_idx][to_idx]==gift[to_idx][from_idx]){
                int from_gisu=gisu[from].first-gisu[from].second;
                int to_gisu=gisu[to].first-gisu[to].second;
                if (from_gisu>to_gisu) arr[from_idx]++;
            }
        }
    }
    
    int max=-999;
    for (int i=0; i<friends.size(); i++){
        if (arr[i]>max){
            max=arr[i];
        }
    }
    cout<<max<<endl;
    
    return max;
}