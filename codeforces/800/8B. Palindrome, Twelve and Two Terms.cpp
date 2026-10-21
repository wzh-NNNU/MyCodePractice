#include<bits/stdc++.h>
using namespace std;
#define int long long
bool isPalindrome(int x){//是否是回文数
    string s=to_string(x);
    string rev_s(s.rbegin(),s.rend());/*
        string rev_s(s.rbegin(), s.rend());
        s.rbegin() ：反向起始迭代器，指向字符串  最后一个字符
        s.rend() ：反向末尾迭代器，指向  第一个字符前面的位置 */
    return s==rev_s;


}

void solved(){
    int n;
    cin>>n;
    int a,b;
    bool flag=false;
    for(int i=0;i<=n;){
        // cout<<i<<endl;
        b=i;
        i+=12;
        a=n-b;
        if(isPalindrome(a)){
            flag=true;
            break;
        }
    }
    if(flag){
        cout<<a<<' '<<b<<endl;
    }else cout<<"-1"<<endl;

}
signed main(){
    int T=1;
    cin>>T;
    while(T--)
        solved();
}