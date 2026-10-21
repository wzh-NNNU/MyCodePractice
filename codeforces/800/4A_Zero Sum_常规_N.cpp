#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
void solved(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int cnt1=0;
    for(int i=1;i<=n;i++)if(a[i]==1) cnt1++;
    if(n%2==1){
        cout<<"NO\n";
        return;
    }
    if(cnt1%2==n/2%2) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
    
}
int main(){
    int T=1;
    cin>>T;
    while(T--)
        solved();
}