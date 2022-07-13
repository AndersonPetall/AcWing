#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int p[N];
int find(int idx)
{
    if(p[idx] != idx) p[idx] = find(p[idx]);
    return p[idx];
}
int main(){
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) p[i] = i;
    while(m--)
    {
        char op[2]; int a, b;
        scanf("%s%d%d", op, &a, &b);
        if(*op == 'M') p[find(a)] = find(b);
        if(*op == 'Q')
        {
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
