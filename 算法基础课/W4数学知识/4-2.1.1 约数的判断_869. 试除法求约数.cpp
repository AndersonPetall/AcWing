//EDITION 1
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> get_divisors(int x){
    vector<int> res;
    for(int i = 1; i <= x/i; ++i)
        if(x % i == 0) {
            res.push_back(i);
            if(i < x / i) res.push_back(x/i);
        }
    sort(res.begin(), res.end());
    return res;
}
int main(){
    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        auto res = get_divisors(x);
        for(auto x : res) printf("%d ", x);
        puts("");
    }
    return 0;
}


//EDITION 2
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void get_divisors(int x){
    vector<int> res;
    for(int i = 1; i <= x/i; ++i)
        if(x % i == 0){
            res.push_back(i);
            if(i != x/i) res.push_back(x/i);
        }
    sort(res.begin(), res.end());
    for(auto x : res)printf("%d ", x);
    puts("");
}
int main(){
    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        get_divisors(x);
    }
    return 0;
}
