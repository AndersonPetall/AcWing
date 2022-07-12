//EDITION 1 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std; 
typedef pair<int, int> PII;
const int N = 1e2 + 10;
int n, m, path[N][N], map[N][N];
int vectorX[4] = {-1,0,1,0}, vectorY[4] = {0,1,0,-1};
int bfs(){
    queue<PII> q; q.push({0,0});
    path[0][0] = 0;
    while(q.size()){
        auto t = q.front(); q.pop();
        for(int i = 0; i < 4; ++i){
            int x = t.first + vectorX[i], y = t.second + vectorY[i];
            if(x >= 0 && x < n && y >= 0 && y < m && map[x][y] == 0 && path[x][y] == -1){
                path[x][y] = path[t.first][t.second] + 1;
                q.push({x,y});
            }
        }
    }
    return path[n-1][m-1];
}
int main(){
    memset(path, -1, sizeof path);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) cin >> map[i][j];
    cout << bfs() << endl;
    return 0;
}




//EDITION 
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int, int> PII;
const int N = 110;
int n, m, path[N][N], map[N][N];
int vectorX[4] = {-1,0,1,0}, vectorY[4] = {0,1,0,-1};
int bfs(){
    queue<PII> q; q.push({1,1});
    while(q.size()){
        auto point = q.front(); q.pop();
        map[point.first][point.second] = 1;
        for(int i = 0; i < 4; ++i){
            int x = point.first + vectorX[i], y = point.second + vectorY[i];
            if(map[x][y] == 0){
                map[x][y] = 1;
                path[x][y] = path[point.first][point.second] + 1;
                q.push({x,y});
            }
        }
    }
    return path[n][m];
}
int main(){
    memset(map, 1, sizeof map);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) scanf("%d", &map[i][j]);
    cout << bfs() << endl;
    return 0;
}
