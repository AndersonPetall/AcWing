#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<unordered_map>
using namespace std;
stack<int> num; stack<char> op;
void evaluate(){
    auto b = num.top(); num.pop();
    auto a = num.top(); num.pop();
    auto c = op.top(); op.pop();
    int sum;
    if(c == '+') sum = a + b;
    if(c == '-') sum = a - b;
    if(c == '*') sum = a * b;
    if(c == '/') sum = a / b;
    num.push(sum);
}
int main(){
    unordered_map<char, int> pr{{'+', 1}, {'-',1}, {'*', 2}, {'/',2}};
    string str; cin >> str;
    for(int i = 0; i < str.size(); ++i){
        
        auto c = str[i];
        if(isdigit(c)){
            int number = 0;
            while(i < str.size() && isdigit(str[i])) number = number * 10 + str[i++] - '0';
            --i; num.push(number);
            
        }
        else if(c == '(') {
            op.push(c);
        }
        else if(c == ')'){
            while(op.top() != '(') evaluate();
            op.pop();
        }
        else{
            while(op.size() && op.top() != '(' && pr[op.top()] >= pr[c]) evaluate();
            op.push(c);
        }
    }
    while(op.size()) evaluate();
    printf("%d", num.top());
    return 0;
}
