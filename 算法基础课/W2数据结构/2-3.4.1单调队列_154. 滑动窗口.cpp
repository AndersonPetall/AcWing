#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n, k, a[N], q[N], head, tail;
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 0;i < n; ++i)scanf("%d", &a[i]);
    head = 0; tail = -1;
    for(int i = 0; i < n; ++i){
        if(head <= tail && i + 1 - k > q[head]) ++head;  //当滑动窗口不覆盖队首对应的数时候,弹出队首   i从0开始索引, 所以加上1
        while(head <= tail && a[i] <= a[q[tail]]) --tail;
        q[++tail] = i;  //队尾插入元素
        if(i+1 >= k) printf("%d ", a[q[head]]);  //当滑动窗口数字填充完毕,即开始打印最值
    }
    puts("");
    head = 0; tail = -1;
    for(int i = 0; i < n; ++i){
        if(head <= tail && i + 1 - k > q[head]) ++head;
        while(head <= tail && a[q[tail]] <= a[i]) --tail;
        q[++tail] = i;
        if(i+1 >= k) printf("%d ", a[q[head]]);
    }
    return 0;
}
