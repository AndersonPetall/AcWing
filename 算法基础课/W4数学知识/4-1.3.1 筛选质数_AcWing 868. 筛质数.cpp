//
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int primes[N];
bool st[N];
int get_primes(int x){
    int cnt = 0;
    for(int i = 2; i <= x; ++i){
        if(st[i]) continue;
        primes[cnt++] = i;
        for(int j = i + i; j <= x; j += i) st[j] = true;
    }
    return cnt++;
}
int main(){
    int n; cin >> n;
    printf("%d\n", get_primes(n));
    return 0;
}


//
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int primes[N];
bool st[N];
int get_primes(int x){
    int cnt = 0;
    for(int i = 2; i <= x; ++i)
        if(!st[i]) {
            primes[cnt++] = i;
            for(int j = i + i; j <= x; j += i) st[j] = true;
        }
    return cnt++;
}
int main(){
    int n; cin >> n;
    printf("%d\n", get_primes(n));
    return 0;
}
