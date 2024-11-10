#include<iostream>
using namespace std;
int const N = 1e6+10;
int n,m,q[N];
int sl(int q[], int l, int r, int x){
    while(l<r){//左边<=， 右边>
        int mid=l+r>>1;
        q[mid]>=x? r=mid : l=mid+1;
    }
    return q[l]==x? l:-1;
}
int sr(int q[], int l, int r, int x){
    while(l<r){//左边<， 右边>=
        int mid=l+r+1>>1;
        x>=q[mid]? l=mid:r=mid-1;
    }
    return q[r]==x? r:-1;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;++i)scanf("%d", &q[i]);
    while(m--){
        int x;scanf("%d", &x);;
        int l=0,r=n-1;
        printf("%d %d\n", sl(q,0,n-1,x),sr(q,0,n-1,x));
    }
    return 0;
}




#include<iostream>
using namespace std;
int const N = 1e6+10;
int n,m,q[N];
int sl(int q[], int l, int r, int x){
    while(l+1<r){//左边<， 右边>=
        int mid=l+r>>1; q[mid] >= x ? r=mid: l=mid;
    }
    return q[r]==x? r:-1;
}
int sr(int q[], int l, int r, int x){
    while(l+1<r){//左边<=， 右边>
        int mid=l+r>>1; q[mid] <= x ? l=mid : r=mid;
    }
    return q[l]==x? l:-1;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;++i)scanf("%d", &q[i]);
    while(m--){
        int x;scanf("%d", &x);;
        int l=0,r=n-1;
        printf("%d %d\n", sl(q,0,n-1,x),sr(q,0,n-1,x));
    }
    return 0;
}
