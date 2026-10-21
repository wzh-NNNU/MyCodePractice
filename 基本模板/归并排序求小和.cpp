#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N=1e6+10;
int a[N];
int n;
int tem[N];
int sum;



ll merge1(int a[],int l,int m,int r){
    ll ans=0;
    //左跨右
    for(int j=m+1,i=l,sum=0;j<=r;j++){
        while(i<=m&&a[i]<a[j]){
            sum+=a[i];
            i++;
        }
        ans+=sum;
    }
    //正常merge排序
    int i=l,j=m+1,k=l;
    while(i<=m&&j<=r){
        if(a[i]<=a[j]){
            tem[k++]=a[i++];
        }else{
            tem[k++]=a[j++];
        }
    }
    while(i<=m) tem[k++]=a[i++];
    while(j<=r) tem[k++]=a[j++];
    for(int i=l;i<=r;i++){
        a[i]=tem[i];
    }
    return ans;

}

ll small_sum(int a[],int l,int r){
    if(l>=r) return 0;
    int m=(l+r)/2;
    return small_sum(a,l,m)+small_sum(a,m+1,r)+merge1(a,l,m,r);
}



void solve(){
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll res=small_sum(a,1,n);
    cout<<res<<endl;

}

int main(){
    int T=1;
    // cin>>T;
    while(T--) 
        solve();
    return 0;
}