#include<bits/stdc++.h>
using namespace std;
void solved(){
    int a[6][6];
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
            cout<<a[i][j]<<' ';
            if(a[i][j]==1)cout<<abs(i-3)+abs(j-3)<<endl;
        }cout<<"\n";
    }

}
int main(){
    int T=1;
    // cin>>T;
    while(T--)
        solved();
}