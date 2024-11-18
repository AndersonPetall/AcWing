//高精度 * 低精度
#include<iostream>
#include<vector>
using namespace std;
vector<int> mul(vector<int>&A, int b){
    vector<int>C;
    for(int i=0,t=0;i<A.size()||t;i++){
        if(i<A.size())t+=A[i]*b;
        C.push_back(t%10);
        t/=10;
    }
    while(C.size()>1&&C.back()==0)C.pop_back();
    return C;
}
int main(){
    string a;int b;cin>>a>>b;
    vector<int>A,C;
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    C=mul(A,b);
    for(int i=C.size()-1;i>=0;i--)printf("%d", C[i]);
    return 0;
}

//高精度 * 高精度
#include<iostream>
#include<vector>
using namespace std;
vector<int> mul(vector<int>&A, vector<int>&B){
    vector<int> C(A.size() + B.size() + 7, 0);// 不可以使用vector<int>C，必须初始化C，否则空指针异常   
    for(int i=0;i<A.size();i++)
        for(int j=0;j<B.size();j++) 
            C[i+j]+=A[i]*B[j];
    for(int i=0,t=0;i<C.size();++i){
        t+=C[i];
        C[i]=t%10;
        t/=10;
    }
    while(C.size()>1&&C.back()==0)C.pop_back();
    return C;
}
int main(){
    string a,b;cin>>a>>b;
    vector<int>A,B,C;
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
    C=mul(A,B);
    for(int i=C.size()-1;i>=0;i--)printf("%d", C[i]);
    return 0;
}


//https://www.acwing.com/solution/content/13694/
