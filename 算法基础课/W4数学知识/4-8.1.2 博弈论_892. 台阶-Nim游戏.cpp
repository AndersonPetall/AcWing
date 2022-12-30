问题关键: 只用考虑奇数台阶
  当玩家1从偶数台阶i 移动一定数量到台阶i-1 的时候,玩家2可以从台阶i-1移动相同的数量到台阶i-2,相当于没有操作((i-2)-->0)
  当玩家1从奇数台阶i 移动一定数量到台阶i-1 的时候, (i-1)-->0 玩家2 可能无法操作,即失败
抽象举例: 所有奇数台阶为台阶1, 所有偶数台阶为台阶2
  
Reference Url:
  https://www.cnblogs.com/lucky-light/p/16512304.html

#include<iostream>
using namespace std;
int main(){
    int n, res=0;cin>>n;
    for(int i=1;i<=n;++i){
        int x; cin>>x;
        if(i&1) res^=x;
    }
    res ? puts("Yes") : puts("No");
    return 0;
}
