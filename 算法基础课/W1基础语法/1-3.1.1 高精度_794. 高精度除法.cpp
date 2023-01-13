#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> divide(vector<int> &A, int B, int &R){
    vector<int> C;
    R = 0;
    for(int i = A.size() - 1; i >= 0; --i){
        R = R * 10 + A[i];
        C.push_back(R / B);
        R %= B;
    }
    reverse(C.begin(), C.end());
    while(C.size() != 1 && C.back() == 0) C.pop_back();
    return C;
}

int main(){
    int b; string a;
    cin >> a >> b;
    vector<int> A;
    for(int i = a.size() - 1; i >= 0; --i) A.push_back(a[i] - '0');
    int r = 0;
    auto C = divide(A, b, r);
    for(int i = C.size() - 1; i >= 0; --i) printf("%d", C[i]);
    printf("\n");
    printf("%d\n", r);
    return 0;
}
