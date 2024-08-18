#include <string>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    int sum=0;
    int x=0;
    int cnt=0;
    
    vector <int> arr;
    
    
    for (int i=0; i<dartResult.size(); i++){
        if (dartResult[i]=='0'||'2'<=dartResult[i] && dartResult[i]<='9'){
            x=dartResult[i]-'0';
            cout<<"x : "<<x<<endl;
            
        }
        else if (dartResult[i]=='1'){
            
            if (dartResult[i+1]=='0'){
                x=10;
                i++;
            }
            else {
                x=1;
            }
            // cout<<"x : "<<x<<endl;
            
        }
        if (dartResult[i]=='S'){
            arr.push_back(x);
            // cout<<"Sx : "<<x<<endl;
            cnt++;
            
        }
        else if (dartResult[i]=='D'){
            x=pow(x,2);
            arr.push_back(x);
            // cout<<"Dx : "<<x<<endl;
            cnt++;
        }   
            
        else if (dartResult[i]=='T'){
            x=pow(x,3);
            arr.push_back(x);
            // cout<<"Tx : "<<x<<endl;
            cnt++;
        }
        
        if (dartResult[i]=='*'){
            if (cnt<2) 
                arr[cnt-1]*=2;

            else {
                arr[cnt-2]*=2;
                arr[cnt-1]*=2;
            }

        }
        else if (dartResult[i+1]=='#'){
            arr[cnt-1]*=-1;
        }
        
        
    }
    for (int i=0; i<arr.size(); i++){
            sum+=arr[i];
        }
    return sum;
}