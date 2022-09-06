//EDITION 1
#include<iostream>
using namespace std;
void divide(int x){
    for(int i = 2; i <= x; ++i)
        if(x % i == 0){
            int s = 0;
            while(x % i == 0) x /= i, ++s;
            printf("%d %d\n", i, s);
        }
    if(x > 1)printf("%d %d\n", x, 1);
    puts("");
}
int main(){
    int n; cin >> n;
    while(n--){
        int x; cin >>x;
        divide(x);
    }
    return 0;
}


//EDITION 2
#include<iostream>
using namespace std;
void divide(int x){
    for(int i = 2; i <= x/i; ++i)
        if(x % i == 0){
            int s = 0; 
            while(x % i == 0) x /= i, ++s;
            cout << i << ' ' << s << endl;
        }
    if(x > 1) cout << x << ' ' << 1 << endl;
    cout << endl;
}
int main(){
    int n; cin >> n;
    while(n--){
        int x; cin >>x;
        divide(x);
    }
    return 0;
}
