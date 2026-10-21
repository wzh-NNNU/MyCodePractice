#include<bits/stdc++.h>

using namespace std ;
int n;
struct zidan{
    int dj;//等级
    int sl;//数量
};
bool cmp(zidan a,zidan b){
    return a.dj>b.dj;
}
int main(){
    cin>>n;
    vector<zidan>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i].dj>>a[i].sl;
    }
    int enemy_dj,enemy_hj,enemy_xl,sh;//敌人护甲等级、敌人初始护甲耐久、敌人初始血量、单颗子弹伤害
    int h;//敌人自定义修复护甲耐久值
    bool has_h=false;
    bool clear=false;
    cin>>enemy_dj>>enemy_hj>>enemy_xl>>sh;
    cin>>h;
    // sort(a.begin()+1,a.end(),cmp);
    for(int i=1;i<=n;++i){
        if(clear==true) break;

        if(a[i].dj>=enemy_dj){
            
            while(a[i].sl--){
                enemy_hj--;
                enemy_xl-=sh;
                if(enemy_xl<=0) {
                    clear=true;
                    break;
                }
                if(enemy_hj<10&&has_h==false){
                    enemy_hj+=h;
                    has_h=true;
                }
            }
        }else {
            
            while(a[i].sl--){
                if(enemy_xl<=0) {
                    clear=true;
                    break;
                }
                if(enemy_hj==0){
                    enemy_xl-=sh;
                }
                else enemy_hj--;
                if(enemy_hj<10&&has_h==false){
                    enemy_hj+=h;
                    has_h=true;
                }




            }
        }

    }

    if(clear) cout<<"clear"<<endl;
    else cout<<enemy_dj<<' '<<enemy_hj<<' '<<enemy_xl;



}