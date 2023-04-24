#include<iostream>
using namespace std;
 const int N = 1010;
 
 int n, w[N], f[N];
 
 int main(){
     cin >> n; 
     for(int i=0; i<n; ++i)cin >>w[i];
     int mx = 1;
     for(int i=0; i<n; ++i){
         f[i]=1;
         for(int j=0; j<i; ++j){
             if(w[i]>w[j]) f[i] = max(f[i],f[j]+1);
         }
         mx = max(mx, f[i]);
     }
     printf("%d",mx);
     return 0;
 }




#include<iostream>
using namespace std;
 const int N = 1010;
 
 int n, cnt, w[N], f[N];
 
 int main(){
     cin >> n; 
     for(int i=0; i<n; ++i)cin >>w[i];
     f[cnt++] = w[0];
     for(int i=0; i<n; ++i){
         if(w[i] > f[cnt-1]) f[cnt++] = w[i];
         else{
             int l=0, r=cnt-1;
             while(l<r){
                 int mid=(l+r)>>1;
                 if(f[mid] >= w[i]) r = mid;
                 else l = mid + 1;
             }
             f[r] = w[i];
         }
     }
     printf("%d",cnt);
     return 0;
 }
