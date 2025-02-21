#include <string>
#include <vector>
#include <iostream>

using namespace std;
int D[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i==j) D[i][j]=0;
            else D[i][j]=1e9;
        }
    }
    
    for (int i=0; i<fares.size(); i++){
        int from=fares[i][0];
        int to=fares[i][1];
        int w=fares[i][2];
        
        D[from][to]=min(D[from][to],w);
        D[to][from]=min(D[to][from],w);
    }
    
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                D[i][j]=min(D[i][j], D[i][k]+D[k][j]);
            }
        }
    }
    
    // for (int i=1; i<=n; i++){
    //     for (int j=1; j<=n; j++){
    //         cout<<D[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    int min_sum=1e9;
    for (int i=1; i<=n; i++){
        int sum=D[s][i]+D[i][a]+D[i][b];
        if (D[s][i]>=1e9 || D[i][a] >= 1e9 || D[i][b]>=1e9) continue;
        else {
            min_sum=min(sum, min_sum);
        }                     
        // cout<<D[s][i]+D[i][a]<<" "<<D[i][b]<<" "<<D[s][i]+D[i][a]+D[i][b]<<endl;
    }
    
    // cout<<min_sum;
    
    return min_sum;
}