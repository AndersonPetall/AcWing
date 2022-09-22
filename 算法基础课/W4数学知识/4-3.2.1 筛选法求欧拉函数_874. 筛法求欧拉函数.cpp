//EDITION SELF
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int primes[N], cnt, eulers[N], t;
bool st[N];
void get_euler(int x){
    eulers[1] = 1;
    for(int i = 2; i <= x; ++i){
        if(!st[i]) primes[cnt++] = i, eulers[i] = i - 1;
        for(int j = 0; primes[j] <= x/i; ++j){
            st[t = primes[j]*i] = true;
            if(i%primes[j]) eulers[t] = eulers[i]*(primes[j]-1);
            else{
                eulers[t] = eulers[i]*primes[j];
                break;
            }
        }
    }
}
int main(){
    int n; scanf("%d", &n); get_euler(n);
    long long res = 0;
    for(int i = 1; i <= n; ++i) res += eulers[i];
    printf("%lld\n", res);
    return 0;
}



//EDITION ACwing1
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int primes[N], cnt, eulers[N];
bool st[N];
void get_euler(int x){
    eulers[1] = 1;
    for(int i = 2; i <= x; ++i){
        if(!st[i]) primes[cnt++] = i, eulers[i] = i -1;
        for(int j =0; primes[j] <= x/i; ++j){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0){
                eulers[primes[j] * i] = eulers[i] * primes[j];
                break;
            }
            else eulers[primes[j] * i] = eulers[i] * (primes[j] - 1);
        }
    }
}
int main(){
    int n; cin >> n; get_euler(n);
    long long res = 0;
    for(int i = 1; i <= n; ++i)res += eulers[i];
    printf("%lld\n", res);
    return 0;
}



//EDITION ACwing2
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
