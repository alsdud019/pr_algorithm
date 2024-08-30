#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string,vector<string>> report_list;
    
    map<string, int> count_list;
    
    for (int i=0; i<report.size(); i++){
        stringstream ss(report[i]);
        
        string first, second;
        ss>>first>>second;
        if (find(report_list[first].begin(), report_list[first].end(), second)
            ==report_list[first].end()){
            report_list[first].push_back(second);
            count_list[second]++;
        }   
    }

    int i=0;
    for (string name:id_list){
        int count=0;
        for (int i=0; i<report_list[name].size(); i++){
            // cout<<report_list[name][i]<<" "<<count_list[report_list[name][i]]<<endl;
            
            if (count_list[report_list[name][i]]>=k) count++;
        }
        answer.push_back(count);
        i++;
        // cout<<endl;
    }
    // map<string,vector<string>>::iterator it;
    // for (it=report_list.begin(); it!=report_list.end(); it++){
    //     // cout<<(*it).first<<" : ";
    //     for (int j=0; j<(*it).second.size(); j++){
    //         // cout<<(*it).second[j]<<" ";
    //     }
    //     // cout<<endl;
    // }
    
    return answer;
}