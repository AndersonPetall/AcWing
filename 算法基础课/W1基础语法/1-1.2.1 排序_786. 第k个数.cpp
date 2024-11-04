//j为分割版
#include<iostream>
using namespace std;
const int N =1e5+10;
int n,k,q[N];
int quick_sort(int q[], int l, int r, int k){
    if(l>=r) return q[l]; //递归结束标志
    int i=l-1,j=r+1,x=q[l+r>>1];//边界问题
    while(i<j){
        do ++i;while(q[i]<x);do --j;while(x<q[j]);
        if(i<j) swap(q[i],q[j]);
    }
    if(k<=j+1-l) return quick_sort(q,l,j,k); else return quick_sort(q,j+1,r,k-(j+1-l));//边界问题
}
int main(){
    scanf("%d%d", &n, &k);
    for(int i=0;i<n;++i)scanf("%d", &q[i]);
    printf("%d", quick_sort(q ,0,n-1,k));
    return 0;
}


//i为分割版
#include<iostream>
using namespace std;
const int N =1e5+10;
int n,k,q[N];
int quick_sort(int q[], int l, int r, int k){
    if(l>=r) return q[l]; //递归结束标志
    int i=l-1,j=r+1,x=q[l+r+1>>1];//边界问题
    while(i<j){
        do ++i;while(q[i]<x);do --j;while(x<q[j]);
        if(i<j) swap(q[i],q[j]);
    }
    if(k<=i-l) return quick_sort(q,l,i-1,k); else return quick_sort(q,i,r,k-(i-l));//边界问题
}
int main(){
    scanf("%d%d", &n, &k);
    for(int i=0;i<n;++i)scanf("%d", &q[i]);
    printf("%d", quick_sort(q ,0,n-1,k));
    return 0;
}
