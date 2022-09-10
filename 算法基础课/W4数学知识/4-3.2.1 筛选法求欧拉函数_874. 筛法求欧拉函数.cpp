#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int primes[N], cnt, euler[N];
bool st[N];
void get_eulers(int n){
    euler[1] = 1;
    for(int i = 2; i <= n; ++i){
        if(!st[i]) primes[cnt++] = i, euler[i] = i -1;
        for(int j = 0; primes[j] <= n/i; ++j){
            int t = primes[j] * i;
            st[t] = true;
            if(i % primes[j] == 0){
                euler[t] = euler[i] * primes[j];
                break;
            }
            euler[t] = euler[i] * (primes[j] - 1);
        }
    }
}
int main(){
    int n; cin >> n;
    get_eulers(n);
    long long res = 0;
    for(int i = 1; i <= n; ++i) res += euler[i];
    printf("%lld\n", res);
    return 0;
}
