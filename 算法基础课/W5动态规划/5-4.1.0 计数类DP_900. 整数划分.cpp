#include<iostream>
using namespace std;
const int N = 1e3 + 7, mod = 1e9 + 7;
int f[N][N];
int main(){
   int n; scanf("%d", &n);
   for(int i=0; i<=n; ++i) f[i][0] = 1;
   for(int i=1; i<=n; ++i){
       for(int j=0; j<=n; ++j){
           f[i][j] = f[i-1][j]%mod;
           if(j >= i)f[i][j] = (f[i-1][j] + f[i][j-i]) % mod;
       }
   }
   printf("%d\n", f[n][n]);
   return 0;
}






#include<iostream>
using namespace std;
const int N = 1e3 + 7, mod = 1e9 + 7;
int f[N];
int main(){
   int n; scanf("%d", &n);
   f[0] = 1;
   for(int i=1; i<=n; ++i)  for(int j=i; j<=n; ++j)  f[j] = (f[j] + f[j-i]) % mod;
   printf("%d\n", f[n]);
   return 0;
}
