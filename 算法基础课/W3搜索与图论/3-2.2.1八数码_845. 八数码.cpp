#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;
int vectorX[4] ={-1,0,1,0}, vectorY[4] = {0,1,0,-1};
//string target = "12345678x";
//const char target[] = "12345678x";
const char *target = "12345678x";
int bfs(string state){
    queue<string> q; q.push(state);
    unordered_map<string, int> d; d[state] = 0;
    while(q.size()){
        auto t = q.front();
        q.pop();
        if(t == target) return d[t];
        int distance = d[t];
        int k = t.find('x'); int x = k/3, y = k%3;
        for(int i = 0; i < 4; ++i){
            int a = x + vectorX[i], b = y + vectorY[i];
            if(a >= 0 && a < 3 && b >= 0 && b < 3){
                swap(t[k], t[a*3+b]);
                if(!d.count(t)){
                    d[t] = distance + 1;
                    q.push(t);
                }
                swap(t[k], t[a*3+b]);
            }
        }
    }
    return -1;
}
int main(){
    char s[2]; string state;
    for(int i = 0; i < 9; ++i){
        cin >> s;
        state += *s;
    }
    cout << bfs(state) <<endl;
    return 0;
}
