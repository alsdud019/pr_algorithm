#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer;
    
    int col=arr.size();
    int row=arr[0].size();
    
    if (col==row){
        return arr;
    }
    else if (col>row){
        for (int i=0; i<col; i++){
            for (int j=0; j<col-row; j++){
               arr[i].push_back(0); 
            }
            
        }
    }
    else if (col<row){
        vector<int> arr2(row,0);
        for (int j=0; j<row-col; j++){
            arr.push_back(arr2);
        }

    }
    
    return arr;
}