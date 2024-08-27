#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int col=wallpaper.size();
    int row=wallpaper[0].size();
    
    // cout<<col<<" "<<row;
    
    vector<int> arr={99,99,0,0};
    
    for (int i=0; i<col; i++){
        for (int j=0; j<row; j++){
            if(wallpaper[i][j]=='#'){
                // cout<<i<<" "<<j<<endl;
                arr[0]=min(arr[0],i);
                arr[1]=min(arr[1],j);
                arr[2]=max(arr[2],i+1);
                arr[3]=max(arr[3],j+1);                                  
            }   
        }
    }
    
    return arr;
}