#include<iostream>
using namespace std;
bool is_primes(int x){
    if(x < 2) return false;
    for(int i = 2; i <= x / i; ++i)
        if(x % i == 0) return false;
    return true;
}
int main(){
    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        is_primes(x) ? puts("Yes") : puts("No");
    }
    return 0;
}
