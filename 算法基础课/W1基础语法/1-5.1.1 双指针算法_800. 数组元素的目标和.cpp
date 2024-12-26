//和纯暴力的O(n2) 算法的区别就在于    j指针不会回退

#include<iostream>
using namespace std;
const int N = 1e5+10;
int n,m,k,a[N],b[N];
#define read(x) scanf("%d",&x);
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;++i)read(a[i]);
    for(int j=0;j<m;++j)read(b[j]);
    for(int i=0,j=m-1;i<n;++i){
        while(j>=0&&a[i]+b[j]>k)j--;
        if(j>=0&&a[i]+b[j]==k)printf("%d %d\n",i,j);
    }
    return 0;
}
