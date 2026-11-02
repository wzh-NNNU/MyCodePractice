#include<bits/stdc++.h>
using namespace std;
void solved(){
    int a,b;
    cin>>a>>b;
    if(a<0||b>a+1) {
        cout<<"-1"<<endl;
        return ;
    }else if(a==0&&b==0){
        cout<<"0"<<endl;
        return ;
    }else {
        int c=b-a;
        
        if(c%2==1||c%2==-1) {
            a++;
            c--;
            
        }

        c=abs(c);
        cout<<c+b<<endl;
    }

}
int main(){
    int T=1;
    cin>>T;
    while(T--)
        solved();
}