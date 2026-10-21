#include<bits/stdc++.h>

using namespace std;
int n,k;
const int N=1e6+10;
int a[N];
void solved(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<a[k];

}

int main(){
    int T=1;
    // cin>>T;
    while(T--){
        solved();
    }

}