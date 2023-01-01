有向图游戏
  给定一个有向无环图,图中有一个唯一的起点,在起点上放有一个棋子. 两名玩家交替的把这枚棋子沿有向边进行移动, 每次可以移动一步,无法移动者判负. 该游戏称之为有向图游戏.
  任何一个公平组合游戏都可以转换为有向图游戏. 具体方法是,把每一局面看成图中的一个节点,并且从每个局面向沿着合法行动能够到达的下一个局面连接有向边
Mex运算
  假设S表示一个非负整数集合.定义mex(S) 为求出不处于集合S的最小非负整数的运算, 即 
  mex(S) = min{x}, x属于自然数(0,1,2,3...),且不属于S
SG函数
  在有向图雨哦戏中,对于每个节点x,设从x出发共有k条有向边,分别到达节点y1,y2,...yk,定义SG(x)为x的后继节点y1,y2,...yk的SG函数值构成的集合再执行mex(X)运算结果,即: SG(x) = mex({SG(y1),SG(y2),...SG(yk)})
  特别地,整个有向图游戏G的SG函数值被定义为有向图游戏起点s的SG函数值, 即SG(G) = SG(s)
  
理解
  Mex运算和SG函数定义了可以进行的操作的衡量值(拿走石子的数量,路劲的衡量值等等)  
  
EG
  a1 -> a2 -> a3(终点)
         ->(a2 -> a4)
  a1 -> a4 -> a5(终点)
  SG(a3) = SG(a5) = 0, SG(a4) = 1,  SG(a2) = 2, SG(a1) = 0
  
  a1 -> a2 -> a3(终点)
         ->(a2 -> a4)
  a1 -> a4 -> a5(终点)
  a1 -> a6 -> a7 -> a8(终点)
  SG(a3) = SG(a5) = SG(a6) = 0, SG(a4) = SG(a7) = 1,  SG(a2) = 2, SG(a1) = 3
  
==>  SG(x) = 0  必败, SG(x) != 0 必胜

EG (nim游戏转有向图游戏)
一堆石子数目为10, 拿取石子方案{2,5}  ()内为SG函数值
  10(1) -> 5(2) -> 0(0)
          -> 3(1) -> 1(0)
     -> 8(0) -> 3(1) -> 1(0)
          -> 6(1) -> 1(0)
               -> 4(0) -> 2(1) -> 0(0)
     
  
有向图游戏的和
  设G1,G2,...Gm 是m个有向图游戏. 定义有向图游戏G,它的行动规则是任选某个有向图游戏Gi,并在Gi上行动一步. G被称为有向图游戏G1,G2,...Gm的和
  有向图游戏的和的SG函数数值等于它包含的各个子游戏SG函数值的异或和,即 
  SG(G) = SG(G1)^SG(G2)^...SG(Gm)
  
SG定理(Sprague-Grundy Theorem)
  有向图游戏的某个局面必胜,当且仅当该局面对应节点的SG函数值大于0
  有向图游戏的某个局面必胜,当且仅当该局面对应节点的SG函数值等于0
  
证明: 参考 4-8.0 博弈论 中 Bouton's Theorem的定义和证明
  最终的局面(失败的局面),SG(G) = 0(没有路径可走)
  若SG(G) = x != 0, 那么玩家必然可以行走某个路径得SG(G) = 0
    假设x的二进制中最高位1在第k位,那么在那么在SG(G1),SG(G2),…,SG(Gn)中,必然有一个数SG(Gi),它的第k为时1[SG(Gi)代表第i个有向图子游戏], 则 SG(Gi)^x < SG(Gi)
    ==> 拿走 SG(Gi)-(SG(Gi)^x) 个石子, 那么第i堆石子剩下SG(Gi)-[SG(Gi)-SG(Gi)^x] = ai^x 个石子
    ==> SG(G1)^SG(G2)^...^(SG(Gi)^x)^...SG(Gn) = x^x = 0
  若SG(G) = x = 0, 那么无论玩家怎么行走,SG(G)均不为0(x != 0)
    反证法: 假设玩家在第i个有向图子游戏中行走某个路劲,结果仍然是0.
      在此条件下,假设第i个有向图子游戏的SG函数为SG(g),题目中要求至少行走一步,所以0<=SG(g)<SG(Gi) 而且 SG(G1)^SG(G2)^...^(SG(g))^...SG(Gn) = 0
      ==>  SG(G1)^SG(G2)^...^(SG(g))^...SG(Gn) = SG(G1)^SG(G2)^...^(SG(Gi))^...SG(Gn), 根据异或的满足消除率, 则 SG(g) = SG(Gi), 与 SG(g)<SG(Gi) 矛盾
  


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
        if(x >= s[i]) S.insert(sg(x-s[i]));//递归调用, 先延申至边界计算边界的SG值,然后从边界往回计算出所有局面的SG值
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
