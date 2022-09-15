//EDITION 精简版
#include<iostream>
using namespace std;
int exgcd(int a, int b, int &x, int &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}
int main(){
    int n; scanf("%d", &n);
    while(n--){
        int a, b, x, y, m, d; scanf("%d%d%d", &a, &b, &m);
        b%(d = exgcd(a,m,x,y)) ? puts("impossible") : printf("%lld\n", (long long)b/d*x%m);
        
    }
}



//EDITION  理解版
#include<iostream>
using namespace std;
using LL = long long;
int exgcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    int gcd = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return gcd;
}
int main(){
    int n; scanf("%d", &n);
    while(n--){
        int a, b, m, x, y; scanf("%d%d%d", &a, &b, &m);
        int d =exgcd(a,m,x,y);
        if(b%d) puts("impossible");  //若不能被整除
        else printf("%lld\n", (LL)b/d*x%m);  //题目要求在 int范围内,所以 %m
    }
    return 0;
}
