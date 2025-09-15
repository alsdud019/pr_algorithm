using namespace std;

long long gcd(int w, int h){
    if (h==0) return w;
    else return gcd(h, w%h);
    
}

long long solution(int w,int h) {
    long long answer = 1;
    
    long long g=gcd(w,h);
    
    answer=((long long)w*(long long)h)-((long long)w+(long long)h-g);
    
    
    return answer;
}