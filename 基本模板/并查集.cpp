#include<bits/stdc++.h>

using namespace std;
const int Max=INT_MAX;
const int N=1e5+10;
int fa[N],sz[N];
int n,m,a,b;
char op;
void init(int n){
    for(int i=1;i<=n;i++){
        fa[i]=i;
        sz[i]=1;
    }
}

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void Union(int x,int y){
    x=find(x),y=find(y);//变量 x 和 y 存的是两个根节点的编号
    if(x!=y){//x 存较大的根编号，y 存较小的根编号
        if(sz[x]<sz[y]) swap(x,y);//交换的是根节点编号，不是数组，也不是集合里的元素。
        fa[y] = x;
        sz[x]+=sz[y];
    }

}

bool same(int x,int y){
    return find(x)==find(y);
}

int size(int x){
    return sz[find(x)];
}

void solve(){
    cin>>n>>m;
    init(n);
    while(m--){
        cin>>op>>a>>b;
        if(op=='M'){
            Union(a,b);
        }
        else{
            if(find(a)==find(b)) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;

        }
    }
}

int main(){
    solve();

}