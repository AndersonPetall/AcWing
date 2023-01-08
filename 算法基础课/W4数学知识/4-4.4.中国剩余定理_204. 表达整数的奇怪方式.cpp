//EDITION self
#include<iostream>
using namespace std;
using LL = long long;
LL exgcd(LL a, LL b, LL &x, LL &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    LL d = exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
int main(){
    int n; cin>>n; --n;
    LL a1,m1; scanf("%lld%lld",&a1,&m1);
    while(n--){
        LL a2,m2,k1,k2;scanf("%lld%lld",&a2,&m2);
        LL d = exgcd(a1,a2,k1,k2);
        if((m2-m1)%d){puts("-1");return 0;}
        LL t = a2/d;
        k1 = (k1*(m2-m1)/d%t+t)%t;
        m1=k1*a1+m1;
        a1=abs(a1*a2/d);
    }
    printf("%lld\n",m1);
    return 0;
}


//EDITION　ACwing
#include<iostream>
using namespace std;
using LL = long long;
LL exgcd(LL a, LL b, LL &x, LL &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    LL d = exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
int main(){
    int n; cin>>n; --n;
    LL a1,m1; scanf("%lld%lld",&a1,&m1);
    while(n--){
        LL a2,m2,k1,k2;scanf("%lld%lld",&a2,&m2);
        LL d = exgcd(a1,a2,k1,k2);
        if((m2-m1)%d){puts("-1");return 0;}//判断是否有解
        LL t = abs(a2/d);//abs为求绝对值的内置方程
        k1 *= (m2-m1)/d;//求(m2-m1)下对应的k1值
        k1 = (k1%t+t)%t;//k1 = k1 + k*a2/gcd(a1,a2)  求 a2/gcd(a1,a2) 范围下的特解
        m1=k1*a1+m1;
        a1=abs(a1*a2/d);
    }
    printf("%lld\n",m1);
    return 0;
}
