#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,a[N];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    
}
int main(){
    int T=1;
    cin>>T;
    while(T--)
        solve();
}