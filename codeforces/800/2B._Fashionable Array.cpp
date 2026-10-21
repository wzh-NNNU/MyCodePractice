#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
int cnt[N];
void solved(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cnt[a[i]]++;
    for(int i=100;i>=1;i--){
        int x=cnt[i];
        if(x==0)continue;
        for(int j=i;j>=1;j--){
            for(int k=1;k<=x&&cnt[j];k++){
                cout<<j<<' ';
                cnt[j]--;
            }
        }
    }cout<<'\n';
    
}
int main(){
    int T=1;
    cin>>T;
    while(T--)
        solved();
}