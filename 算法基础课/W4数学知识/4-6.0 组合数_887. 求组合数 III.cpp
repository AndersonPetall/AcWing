#include<iostream>
#include<algorithm>
using namespace std;
using LL = long long;
LL qmi(LL a,LL k,LL p){
    if(!b) return 1;
    LL res = qmi(a*a%c,b>>1,c);
    return b&1 ? res*a%c : res;
}
int C(int a, int b, int p){
    if(b>a)return 0;
    int res = 1;
    for(int i=1,j=a;i<=b;++i,--j){
        res = (LL)res*j%p;
        res=(LL)res*qmi(i,p-2,p)%p;
    }
    return res;
}
int lucas(LL a, LL b, int p){
    return (a<p&&b<p)?C(a, b, p):(LL)C(a%p,b%p,p)*lucas(a/p,b/p,p)%p;
}
int main(){
    int n; cin>>n;
    while(n--){
        LL a,b;int p; scanf("%lld%lld%d",&a,&b,&p);
        printf("%d\n",lucas(a,b,p));
    }
    return 0;
}



#include<iostream>
#include<algorithm>
using namespace std;
using LL = long long;
int qmi(int a,int k, int p){
    int res = 1;
     while(k){
         if(k&1) res = (LL)res*a%p;
         a = (LL)a*a%p;
         k>>=1;
     }
     return res;
}
int C(int a, int b, int p){
    if(b>a)return 0;
    int res = 1;
    for(int i=1,j=a;i<=b;++i,--j){
        res = (LL)res*j%p;
        res=(LL)res*qmi(i,p-2,p)%p;
    }
    return res;
}
int lucas(LL a, LL b, int p){
    return (a<p&&b<p)?C(a, b, p):(LL)C(a%p,b%p,p)*lucas(a/p,b/p,p)%p;
}
int main(){
    int n; cin>>n;
    while(n--){
        LL a,b;int p; scanf("%lld%lld%d",&a,&b,&p);
        printf("%d\n",lucas(a,b,p));
    }
    return 0;
}
