//EDITION self
#include<iostream>
#include<cstring>
#include<set>
using namespace std;
const int N = 1e2+10,M=1e4+10;
int n,m, res=0,s[N],f[M];
int sg(int x){
    if(f[x]!=-1) return f[x];
    set<int> S;
    for(int i=0;i<m;++i){
        if(x >= s[i]) S.insert(sg(x-s[i]));
        else continue;
    }
    for(int i=0;;++i)if(!S.count(i)) return f[x] = i;
}
int main(){
    cin>>m;
    for(int i=0;i<m;++i)cin>>s[i];
    cin>>n;
    memset(f,-1,sizeof f);
    for(int i=0;i<n;++i){
        int x;cin>>x;
        res ^=sg(x);
    }
    res ? puts("Yes") : puts("No");
    return 0;
}



//EDITION　ACwing
#include<iostream>
#include<cstring>
#include<set>
using namespace std;
const int N = 1e2+10,M=1e4+10;
int n,m,s[N],f[M];//s存储的是可供选择的集合,f存储的是所有可能出现过的情况的sg值
//SG()函数计算可以利用 2(2,5)+1(10) 以及 2(2,5)+1(1) 两个例子理解
int sg(int x){
    if(f[x]!=-1) return f[x];//因为取石子数目的集合是已经确定了的,所以每个数的sg值也都是确定的,如果存储过了,直接返回即可
    set<int> S;//set代表的是有序集合(注:因为在函数内部定义,所以下一次递归中的S不与本次相同)
    for(int i=0;i<m;++i){
        //递归调用, 先延申至边界计算边界的SG值,然后从边界往回计算出所有局面的SG值
        //s[i]代表可以拿取的数目,如果当前石子数量大于s[i],代表可以执行行动,继续递归;如果当前石子数量小于s[i],代表不可以执行行动,即是递归边界
        if(x >= s[i]) S.insert(sg(x-s[i]));
        else continue;
    }
    for(int i=0;;++i)if(!S.count(i)) return f[x] = i;//第一个未出现的数即为SG函数(mex运算定义)
}
int main(){
    cin>>m;
    for(int i=0;i<m;++i)cin>>s[i];
    cin>>n;
    memset(f,-1,sizeof f);
    int res=0;
    for(int i=0;i<n;++i){
        int x;cin>>x;
        res ^=sg(x);
    }
    res ? puts("Yes") : puts("No");
    return 0;
}
