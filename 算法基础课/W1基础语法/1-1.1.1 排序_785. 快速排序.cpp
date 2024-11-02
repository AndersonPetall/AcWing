//j为分割版
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n, q[N];
void quick_sort(int q[], int l, int r){
    if(l>=r) return; //递归结束标志
    int i = l-1, j =r+1, x = q[(l+r)>>1];//边界问题
    while(i < j){
        do ++i; while(q[i] < x);
        do --j; while(x < q[j]);
        if(i<j) swap(q[i], q[j]);
    }
    quick_sort(q,l,j);quick_sort(q,j+1,r);   //边界问题
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &q[i]);
    quick_sort(q,0,n-1);
    for(int i = 0; i < n; ++i) printf("%d ", q[i]);
    return 0;
}


//i为分割版
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n, q[N];
void quick_sort(int q[], int l, int r){
    if(l>=r) return;
    int i = l-1, j =r+1, x = q[(l+r+1)>>1];//边界问题
    while(i < j){
        do ++i; while(q[i] < x);
        do --j; while(x < q[j]);
        if(i<j) swap(q[i], q[j]);
    }
    quick_sort(q,l,i-1);quick_sort(q,i,r);//边界问题
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &q[i]);
    quick_sort(q,0,n-1);
    for(int i = 0; i < n; ++i) printf("%d ", q[i]);
    return 0;
}
