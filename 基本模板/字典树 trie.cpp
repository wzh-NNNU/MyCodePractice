#include "bits/stdc++.h"
using namespace std;
const int N=1e5+10;
int trie [N][26];//指向的是子节点的根
int cnt[N];
int subtree[N];
int idx;
int n;

//1.插入单词
void insert(char s[]){
    int p=0;
    subtree[p]++;
    for(int i=0;s[i];i++){
        int c=s[i]-'a';
        if(!trie[p][c]) trie[p][c]=++idx;
        p=trie[p][c];
        subtree[p]++;
    }
    cnt[p]++;
}

//2.查找单词出现次数
int find (char s[]){
    int p=0;
    for(int i=0;s[i];i++){
        int c=s[i]-'a';
        if(!trie[p][c]) return 0;
        p=trie[p][c];
    }
    return cnt[p];
}

//3.判断单词是否存在
bool exits(char s[]){
    return find(s)>0;
}

//4.查找以某个前缀开头的单词总数
int countPrefix(char s[]){
    int p=0;
    for(int i=0;s[i];i++){
        int c=s[i]-'a';
        if(!trie[p][c]) return 0;
        p=trie[p][c]; 
    }
    return subtree[p];
}

//5.查找是否存在以某前缀和开头的单词
bool hasPrefix(char s[]){
    int p=0;
    for(int i=0;s[i];i++){
        int c=s[i]-'a';
        if(!trie[p][c]) return false;
        p=trie[p][c];
    }
    return true;
}

//6.删除一个单词（一次）
bool eraseOne(char s[]){
    if(!exits(s)) return false;//先判断存不存在

    int p=0;
    subtree[p]--;
    for(int i=0;s[i];i++){
        int c=s[i]-'a';
        p=trie[p][c];
        subtree[p]--;
    }
    cnt[p]--;
    return true;
}

//7.Z删除所有相同单词
bool eraseAll(char s[]){
    int num=find(s);
    if(num==0) return false;
    
    //这里想保留一位的话，num=num-1;这样可以保留一位，去重效果
    int p=0;
    subtree[p]-=num;
    for(int i=0;s[i];i++){
        int c=s[i]-'a';
        p=trie[p][c];
        subtree[p]-=num;
    }    
    cnt[p]=0;//当保留一位时，cnt[p]=1
    return true;

}




//14.清空字典树
void clear(){
    memset(trie,0,sizeof(trie));
    memset(cnt,0,sizeof(cnt));
    memset(subtree,0,sizeof(subtree));
    idx=0;
}


int query(char s[]){

}


void solve(){
 

}

int main(){
    solve();
    return 0;
}