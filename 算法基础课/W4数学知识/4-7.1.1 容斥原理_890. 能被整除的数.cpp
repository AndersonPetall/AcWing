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
        int t=1;  //t储存质数的乘积(用于确定交集的大小)
        int s=0;  //s储存当前组合中选取的集合数目
        for(int j=0;j<m;++j){
            if(i>>j&1){  //判断当前组合情况中 质数p[j]是否存在
                if((LL)t*p[j]>n){t=-1;break;}  //若乘积 > n, 则当前组合情况不成立
                t*=p[j];++s;  //若乘积 < n, 则当前组合情况成立
            }
        }
        if(t!=-1) s%2 ? res+=n/t:res-=n/t;  //组合中方案数目为奇数则相加,偶数相减 (详见 4-7.0 容斥原理(Inclusion-exclusion Principle) function1)
    }
    printf("%d\n",res);
    return 0;
}
