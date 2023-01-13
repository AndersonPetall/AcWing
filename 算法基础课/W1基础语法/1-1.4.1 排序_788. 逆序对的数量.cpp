#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int n, q[N];
long long merge_sort(int q[], int l, int r){
    if(l >= r) return 0;
    int mid = (l + r) >> 1, i = l, j = mid + 1, k = 0, temp[N];
    long long res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    while(i <= mid && j <= r)
        if(q[i] <= q[j])temp[k++] = q[i++];
        else{
            temp[k++] = q[j++];
            res += mid - i + 1;
        }
    while(i <= mid) temp[k++] = q[i++];
    while(j <= r) temp[k++] = q[j++];
    for(int i = l, j = 0; i <= r; ++i, ++j)q[i] = temp[j];
    return res;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &q[i]);
    printf("%lld", merge_sort(q, 0, n -1));
    return 0;
}
