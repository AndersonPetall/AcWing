#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 1e5 + 10;
int h[N], ph[N], hp[N], cnt, n, se;
char op[5];
void heap_swap(int a, int b){
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}
void down(int idx){
    int t = idx;
    if(idx*2 <= cnt && h[idx*2] < h[t]) t = idx*2;
    if(idx*2+1 <= cnt && h[idx*2+1] < h[t]) t = idx*2 + 1;
    if(idx != t){
        heap_swap(idx, t);
        down(t);
    }
}
void up(int idx){
    while(idx/2 && h[idx] < h[idx/2]){
        heap_swap(idx, idx/2);
        idx >>= 1;
    }
}

int main()
{
    scanf("%d", &n);
    while (n -- )
    {
        int k, x;
        scanf("%s", op);
        if(!strcmp(op, "I")){
            scanf("%d", &x);
            ++cnt; ++se;
            ph[se] = cnt, hp[cnt] = se, h[cnt] = x;
            up(cnt);
            
        }
        if(!strcmp(op, "PM")) {
            printf("%d\n", h[1]);
        }
        if(!strcmp(op, "DM")){
            heap_swap(1, cnt--);
            down(1);
        }
        if(!strcmp(op, "D")){
            scanf("%d", &k);
            int idx = ph[k];
            heap_swap(idx, cnt--);
            up(idx); down(idx);
        }
        if(!strcmp(op, "C")){
            scanf("%d%d", &k, &x);
            int idx = ph[k]; h[idx] = x;
            up(idx); down(idx);
        }
    }
    return 0;
}
