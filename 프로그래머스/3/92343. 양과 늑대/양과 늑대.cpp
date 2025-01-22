#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[20];
int answer=-1e9;

void dfs(vector<int> info, int now, int sheep, int wolf, queue<int> q){
    if (info[now]) wolf++;
    else sheep++;
    
    if (sheep<=wolf) return;
    answer=max(answer, sheep);
    
    for (int i=0; i<vec[now].size(); i++){
        q.push(vec[now][i]);
    }
    
    for (int i=0; i<q.size(); i++){
        int next=q.front(); q.pop();

        dfs(info, next, sheep, wolf,q);
        
        // if (info[next]) wolf--;
        // else sheep--;
        
        q.push(next);
        
        
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    
    for (int i=0; i<edges.size(); i++){
        int from=edges[i][0];
        int to=edges[i][1];
        
        vec[from].push_back(to);
        // vec[to].push_back(from);
    }
    
    queue<int> q;
    dfs(info, 0,0,0, q);
    
    
    return answer;
}