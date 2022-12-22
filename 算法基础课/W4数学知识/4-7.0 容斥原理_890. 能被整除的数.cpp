#include<iostream>
#include<algorithm>
using namespace std;
using LL = long long;
const int N = 20;
int p[N];
int main(){
    int n,m,res=0;scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)cin>>p[i];
    for(int i=1;i<1<<m;++i){
        int t=1,s=0;
        for(int j=0;j<m;++j){
            if(i>>j&1){
                if((LL)t*p[j]>n){t=-1;break;}
                t*=p[j];++s;
            }
        }
        if(t!=-1) s%2 ? res+=n/t:res-=n/t;
    }
    printf("%d\n",res);
    return 0;
}
