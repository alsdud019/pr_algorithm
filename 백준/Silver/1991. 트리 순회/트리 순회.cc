#include <iostream> 
#include <vector>
using namespace std;

int N;
struct Node{
    char left;
    char right;
};

vector<Node> arr(27);

void preorder(char now){
    if (now=='.') return;
    cout<<now;
    preorder(arr[now-'A'].left);
    preorder(arr[now-'A'].right);
}
void postorder(char now){
    if (now=='.') return;
    postorder(arr[now-'A'].left);
    postorder(arr[now-'A'].right);
    cout<<now;
}
void midorder(char now){
    if (now=='.') return;
    midorder(arr[now-'A'].left);
    cout<<now;
    midorder(arr[now-'A'].right);
}

int main(){
    
    cin>>N;
    for (int i=0; i<N; i++){
        char mid, left,right;
        cin>>mid>>left>>right;
        arr[mid-'A'].left=left;
        arr[mid-'A'].right=right;
        //arr[mid-'A']={left, right};
        
    }
    
    preorder('A');
    cout<<endl;
    midorder('A');
    cout<<endl;
    postorder('A');
    
    
    
}