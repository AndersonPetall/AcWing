#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; ++i)scanf("%d", &arr[i]);
    vector<int> stk;
    stk.push_back(arr[0]);
    for(int i=1; i<n; ++i){
        if(arr[i] >stk.back()) stk.push_back(arr[i]);
        else *lower_bound(stk.begin(),stk.end(), arr[i]) = arr[i];
    }
    printf("%d", stk.size());
    return 0;
}
