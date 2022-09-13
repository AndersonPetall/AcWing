//EDITION self
#include<iostream>
using namespace std;
using LL = long long;
LL qmi(int a, int b, int c){
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
        LL a, b, c; scanf("%lld%lld%lld", &a, &b, &c);
        printf("%lld\n",qmi(a,b,c));
    }
    return 0;
}



//EDITION　ACwing
#include<iostream>
using namespace std;
using LL = long long;
LL qmi(int a, int b, int c){
    LL res = 1;
    while(b){
        if(b&1) res = res * a % c;
        a = a * (LL)a % c;
        b >>= 1;
    }
    return res;
}
int main(){
    int n; scanf("%d", &n);
    while(n--){
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        printf("%lld\n", qmi(a,b,c));
    }
    return 0;
}
