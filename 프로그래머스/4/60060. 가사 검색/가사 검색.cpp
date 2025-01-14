#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Trie{
    Trie *Node[26];
    int cnt;
    
    Trie(){
        cnt=0;
        for (int i=0; i<26; i++) Node[i]=NULL;
    }
    
    void insert(string str){
        Trie *now=this;
        for (char ch:str){
            now->cnt++;
            if (now->Node[ch-'a']==NULL) now->Node[ch-'a']=new Trie();
            now=now->Node[ch-'a'];
        }
    }
    
    int find(string str){
        Trie *now=this;
        for (char ch:str){
            if (ch=='?') return now->cnt;
            if (now->Node[ch-'a']==NULL) return false;
            now=now->Node[ch-'a'];
        }
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    Trie Root[10000];
    Trie ReRoot[10000];
    
    
    for (string word: words){
        Root[word.size()-1].insert(word);
        
        //"?"로 시작하는 단어를 위한 단어 거꾸로 저장
        reverse(word.begin(), word.end());
        ReRoot[word.size()-1].insert(word);
    }
    
    for (string query:queries){
        if (query[0]!='?'){
            answer.push_back(Root[query.size()-1].find(query));
        }
        
        //"?"로 시작하는 단어뒤집어서 문자열부터 찾기 
        else{       
            reverse(query.begin(), query.end());
            answer.push_back(ReRoot[query.size()-1].find(query));
        }

    }
    
    return answer;
}