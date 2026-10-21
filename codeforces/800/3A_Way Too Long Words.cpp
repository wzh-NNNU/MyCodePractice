#include<bits/stdc++.h>
using namespace std;
void solved(){

    string s;
    cin>>s;
    if(s.size()<=10) cout<<s<<'\n';
    else cout<<s[0]<<s.size()-2<<s[s.size()-1]<<'\n';

}
int main(){
    int T=1;
    cin>>T;
    while(T--)
        solved();
}