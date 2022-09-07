#include<iostream>
#include<unordered_map>
using namespace std;
const int mod = 1e9 + 7;
int main(){
    int n; scanf("%d", & n);
    unordered_map<int, int> primes;
    while(n--){
        int x; scanf("%d", &x);
        for(int i = 2; i <= x/i; ++i)
            while(x % i == 0) x /= i, primes[i]++;
        if(x > 1) primes[x]++;
    }
    long long res = 1;
    for(auto x : primes) res = res * (x.second + 1) % mod;
    printf("%lld\n", res);
    return 0;
}
