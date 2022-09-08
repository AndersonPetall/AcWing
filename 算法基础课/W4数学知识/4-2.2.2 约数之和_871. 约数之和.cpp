#include<iostream>
#include<unordered_map>
using namespace std;
using LL = long long;
const int mod = 1e9 + 7;
int main(){
    int n; scanf("%d", &n);
    unordered_map<int, int> primes;
    while(n--){
        int x; scanf("%d", &x);
        for(int i = 2; i <= x/i; ++i)
            while(x % i == 0) x /= i, primes[i]++;
        if(x > 1) primes[x]++;
    }
    LL res = 1;
    for(auto x : primes){
        LL a = x.first, b = x.second, total = 1;
        while(b--) total = (total * a + 1) % mod;  //防止数据溢出变为负数
        res = res * total % mod;
    }
    printf("%lld\n", res);
    return 0;
}
