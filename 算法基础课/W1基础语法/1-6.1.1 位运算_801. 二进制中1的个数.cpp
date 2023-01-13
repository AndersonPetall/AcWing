#include<iostream>
using namespace std;
int n;
int lowbit(int x){
    return x & (~x + 1);
}
int main(){
    cin>> n;
    int m;
    while(n--){
        cin >> m;
        int temp = 0;
        while(m){
            temp ++;
            m -= lowbit(m);
        }
        printf("%d ", temp);
    }
    return 0;
}




#include<iostream>
using namespace std;
int n, m;
int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d", &m);
        int temp = 0;
        for(int i = m; m; m -= m & -m) temp++;
        printf("%d ", temp);
    }
    return 0;
}
