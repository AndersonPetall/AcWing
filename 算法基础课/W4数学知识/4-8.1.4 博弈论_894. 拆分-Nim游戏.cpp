题意: 每堆石子可以变成小于原来那堆的任意大小的两堆
a[i] -> (b[i],b[j]),若规定b[i]>=b[j], 则原题意满足 a[i] > b[i]>=b[j]
根据SG函数理论(详见 )
    多个独立局面的SGSG值,等于这些局面SGSG值的异或和
  因此需要存储的状态就是sg(b[i])^sg(b[j])

PS:因为这题中原堆拆分成的两个较小堆小于原堆即可,因此任意一个较小堆的拆分情况会被完全包含在较大堆中,因此SS可以开全局


//EDITION self
#include<iostream>
#include<cstring>
#include<set>
using namespace std;
const int N=1e2+10;
int f[N];
set<int> S;
int sg(int x){
    if(f[x]!=-1) return f[x];
    for(int i=0;i<x;++i)for(int j=0;j<=i;++j)S.insert(sg(i)^sg(j));
    for(int i=0;;++i)if(!S.count(i))return f[x]=i;
}
int main(){
    memset(f,-1,sizeof f);
    int n; cin>>n;
    int res =0;
    while(n--){
        int x;cin>>x;
        res ^=sg(x);
    }
    res ? puts("Yes") : puts("No");
    return 0;
}


//EDITION　ACwing
#include<iostream>
#include<cstring>
#include<unordered_set>
using namespace std;
const int N=1e2+10;
int n, f[N];
unordered_set<int> S;
int sg(int x){
    if(f[x]!=-1) return f[x];
    for(int i=0;i<x;++i)for(int j=0;j<=i;++j)S.insert(sg(i)^sg(j));
    for(int i=0;;++i)if(!S.count(i))return f[x]=i;
}
int main(){
    memset(f,-1,sizeof f);
    cin>>n;
    int res =0;
    while(n--){
        int x;cin>>x;
        res ^=sg(x);
    }
    res ? puts("Yes") : puts("No");
    return 0;
}
