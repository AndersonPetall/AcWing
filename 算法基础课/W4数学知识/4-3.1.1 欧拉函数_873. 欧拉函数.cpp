#include<iostream>
using namespace std;
int phi(int x){
    int res = x;
    for(int i = 2; i <= x/i; ++i)
        if(x % i == 0){
            res -= res/i;
            while(x % i == 0) x /= i;
        }
    if(x > 1) res -= res/x;
    return res;
}
int main(){
    int n; scanf("%d", &n);
    while(n--){
        int x; scanf("%d", &x);
        printf("%d\n", phi(x));
    }
    return 0;
}
