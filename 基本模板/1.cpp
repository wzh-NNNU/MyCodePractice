#include "bits/stdc++.h"
using namespace std;
const int N=5e4+10;
int fa[N];
int n,k;
int d,x,y;
int res;
int sx[6]={0,-1,-2,-3,-4,-5};//-1~-3 abc;-4~-5 t1 t2 
void init(int n){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}

int  find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void Union(int x,int y){
    x=find(x),y=find(y);
    if(x!=y){
        fa[y]=x;
    }
}

void solve(){
   cin>>n>>k;
   init(n);
   int csh=0;
   while(k--){
        
        cin>>d>>x>>y;
        if(x>n||y>n) {
            res++;
            break;
        }
        if(d==2&&x==y) {
            res++;
            break;
        }
        if(csh==0){
            if(d==1){
                fa[find(x)]=sx[1];
                fa[find(y)]=sx[1];
            }else{
                fa[find(x)]=sx[1];
                fa[find(y)]=sx[2];
            }
            csh++;break;

        }

        if(d==1){
          

        }else {
            int t1=find(x),t2=find(y);
            if(t1>0){
                find(x)=
            }

        }


   }

}

int main(){
    solve();
    return 0;
}