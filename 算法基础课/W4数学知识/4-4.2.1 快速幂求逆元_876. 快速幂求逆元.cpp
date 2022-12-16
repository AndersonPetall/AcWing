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
        if(a % b ) printf("%lld\n",qmi(a,b-2,b));
        else puts("impossible");
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
