#include <iostream>
#include <vector>
using namespace std;

int arr[100001][4]={0,};

int solution(vector<vector<int> > land)
{
    int answer = 0;

    for (int i=0; i<4; i++){
        arr[0][i]=land[0][i];
    }

    for (int i=1; i<land.size(); i++){
        for (int now=0; now<4; now++){
            
            for (int pro=0; pro<4; pro++){
                if (now==pro) continue;
                arr[i][now]=max(arr[i][now],land[i][now]+arr[i-1][pro]);
            }
            // cout<<arr[i][now]<<" ";
        }
        // cout<<'\n';
    }
    
    for (int i=0; i<4; i++){
        answer=max(answer,arr[land.size()-1][i]);
    }

    return answer;
}