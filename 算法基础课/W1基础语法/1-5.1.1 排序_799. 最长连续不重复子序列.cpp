#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int n, q[N], s[N];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &q[i]);
    int len = 0;
    for(int i = 0, j = 0; j < n; ++j){
        s[q[j]]++;
        while(s[q[j]] == 2){
            s[q[i]] --;
            i++;
        }
        len = max(j - i + 1, len);
    }
    printf("%d", len);
    return 0;
}
