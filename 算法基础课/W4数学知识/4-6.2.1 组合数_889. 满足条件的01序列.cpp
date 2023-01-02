//EDITION self
#include<iostream>
using namespace std;
using LL = long long;
const int mod = 1e9+7;
LL qmi(LL a,LL b,LL c){
    if(!b) return 1;
    LL res = qmi(a*a%c,b>>1,c);
    return b&1 ? res*a%c : res;
}
int main(){
    int n; cin>>n;
    LL res = 1;
    for(int i=2*n;i>n;--i)res =res*i%mod;
    for(int i=1;i<=n;++i)res=res*qmi(i,mod-2,mod)%mod;
    printf("%lld\n",res*qmi(n+1,mod-2,mod)%mod);
    return 0;
}


//EDITION　ACwing
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10,mod=1e9+7;
using LL = long long;
LL qmi(LL a, LL b, LL c){
    if(!b) return 1;
    LL res = qmi(a*a%c,b>>1,c);
    return b&1 ? res*a%c : res;
}
int main(){
    int n;cin>>n;
    LL res=1;
    //(2*n)! / n!
    for(int i=2*n;i>n;--i)res=res*i%mod;
    //n! 关于mod的逆元
    for(int i=1;i<=n;++i)res=res*qmi(i,mod-2,mod)%mod;
    //n+1 关于mod的逆元
    res=res*qmi(n+1,mod-2,mod)%mod;
    printf("%d\n",res);
    return 0;
}
