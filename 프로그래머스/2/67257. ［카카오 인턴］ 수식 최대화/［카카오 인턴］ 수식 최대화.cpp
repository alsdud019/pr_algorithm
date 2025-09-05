#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> numbers;
vector<char> operators;

char op[3]={'+','-','*'};

void seperate(string expression){
    
    string num="";
    for (int i=0; i<expression.size(); i++){
        
        char now=expression[i];
        if (0<=(now-'0') && (now-'0')<=9){
            num+=now;
        }
        else {
            numbers.push_back(stoi(num));
            num="";
            operators.push_back(now);
        }
    }
    numbers.push_back(stoll(num));
}

int visited[3]={0,};
vector<char> priority_op;

long long calculation(char op, long long num1, long long num2){
    if (op=='+') return num1+num2;
    else if (op=='-') return num1-num2;
    else if (op=='*') return num1*num2;
}

long long solution(){
    
    vector<long long> temp_numbers=numbers;
    vector<char> temp_op=operators;
    
    
    for (int i=0; i<3; i++){
        char now=priority_op[i];
        
        for (int j=0; j<temp_op.size(); j++){
            if (now==temp_op[j]){
                long long re=calculation(now, temp_numbers[j], temp_numbers[j+1]);
                temp_numbers[j]=re;
                temp_numbers.erase(temp_numbers.begin()+j+1);
                temp_op.erase(temp_op.begin()+j);              
                j--;
            }
        }
    }
    
    return abs(temp_numbers[0]);
    
}

long long answer = 0;

void dfs(int level){
    
    if (level==3){
        long long result=solution();
        // cout<<result<<'\n';
        answer=max(result, answer);
        return ;
    }
    
    for (int i=0; i<3; i++){
        char now=op[i];
        
        if (visited[i]) continue;
        priority_op.push_back(now);
        visited[i]=1;
        dfs(level+1);
        visited[i]=0;
        priority_op.pop_back();
        
    }
    
}

long long solution(string expression) {
    
    
    seperate(expression);
    
    dfs(0);

    return answer;
}