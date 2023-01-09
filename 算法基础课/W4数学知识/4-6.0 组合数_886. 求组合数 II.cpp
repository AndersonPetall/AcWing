//EDITION self
#include<iostream>
using namespace std;
using LL = long long;
const int N = 1e5+10,mod=1e9+7;
LL fact[N],infact[N];
LL qmi(LL a, LL b, LL c){
    if(!b) return 1;
    LL res = qmi(a*a%c,b>>1,c);
    return b&1 ? res*a%c : res;
}
int main(){
    fact[0]=infact[0]=1;
    for(int i=1;i<N;++i){
        fact[i]=fact[i-1]*i%mod;
        infact[i]=infact[i-1]*qmi(i,mod-2,mod)%mod;
    }
    int n;cin>>n;
    while(n--){
        int a,b;scanf("%d%d",&a,&b);
        printf("%lld\n",fact[a]*infact[b]%mod*infact[a-b]%mod);
    }
    
    return 0;
}




//EDITION　ACwing
#include<iostream>
using namespace std;
using LL = long long;
const int N = 1e5+10,mod=1e9+7;
int fact[N],infact[N];
LL qmi(LL a, LL b, LL c){
    if(!b) return 1;
    LL res = qmi(a*a%c,b>>1,c);
    return b&1 ? res*a%c : res;
}
int main(){
    fact[0]=infact[0]=1;
    for(int i=1;i<N;++i){
        fact[i]=(LL)fact[i-1]*i%mod;  //预处理出乘阶数组 n*(n-1)*(n-2)...
        infact[i]=(LL)infact[i-1]*qmi(i,mod-2,mod)%mod;  //预处理出逆元数组  n^(-1)*(n-1)^(-1)*(n-2)^(-1)...
    }
    int n;cin>>n;
    while(n--){
        int a,b;scanf("%d%d",&a,&b);
        printf("%lld\n",(LL)fact[a]*infact[b]%mod*infact[a-b]%mod);
    }
    
    return 0;
}
