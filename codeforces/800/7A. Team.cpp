#include<bits/stdc++.h>
using namespace std;
int res;
void solved(){
    int a[4];
    int n=0;
    for(int i=1;i<=3;i++){
        cin>>a[i];
        if(a[i]==1)n++;
    }if(n>=2)res++;

}
int main(){
    int T=1;
    cin>>T;
    while(T--)
        solved();
    cout<<res;
}