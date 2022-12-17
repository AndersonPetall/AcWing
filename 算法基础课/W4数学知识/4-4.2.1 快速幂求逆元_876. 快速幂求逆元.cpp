//EDITION self
#include<iostream>
using namespace std;
using LL = long long;
LL qmi(LL a, LL b, LL c){
    LL res = 1;
    while(b){
        if(b&1) res = res * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return res;
}
int main(){
    int n; scanf("%d", &n);
    while(n--){
        LL a, b; scanf("%lld%lld", &a, &b);
        a%b ? printf("%lld\n",qmi(a,b-2,b)):puts("impossible");
    }
    return 0;
}



//EDITION　ACwing
#include <iostream>
using namespace std;
using LL = long long;
LL qmi(int a, int b, int c){
    LL res = 1;
    while (b){
        if (b&1) res = res * a % c;
        a = a * (LL)a % c;
        b >>= 1;
    }
    return res;
}
int main(){
    int n; scanf("%d", &n);
    while (n -- ){
        int a, b; scanf("%d%d", &a, &b);
        if (a % b == 0) puts("impossible");
        else printf("%lld\n", qmi(a, b - 2, b));
    }
    return 0;
}



//EDITION　拓展欧几里得算法  详见 4-4.3.0 补充-通解,特解与拓展欧几里德算法
#include<iostream>
using namespace std;
using LL = long long;

int exgcd(int a, int b, int &x, int &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    int d = exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
int main(){
    int n; cin>>n;
    while(n--){
        int a,b,x,y;scanf("%d%d",&a,&b);
        exgcd(a,b,x,y) == 1 ? printf("%lld\n",((long long)x+b)%b):puts("impossible");
    }
    return 0;
}
