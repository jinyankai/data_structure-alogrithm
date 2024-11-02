//
// Created by 21077 on 2024/11/2.
//
#include<bits/stdc++.h>
using namespace std;
int cnt = 0;

vector<vector<int>> visited;
vector<vector<char>> board;
vector<pair<int,int>> steps = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool inboard(int i, int j){
    return i >= 0 && i < board.size() && j >= 0 && j < board[0].size();
}

void dfs(int i ,int j){
    if(board[i][j] == '@') return;
    visited[i][j] ++;
    if(board[i][j] == 'P') cnt--;
    for(auto [dx,dy] : steps) {
        int x = i + dx;
        int y = j + dy;
        if (inboard(x, y) && !visited[x][y] && board[x][y] != '@') {
            dfs(x, y);
        }
    }
}

int main(){
    int q;
    cin >> q;
    for(int d = 0 ; d < q; d++){
        bool flag = true;
        int a,b;
        cnt = 0;
        cin >> a >> b;
        board = vector<vector<char>>(a, vector<char>(b));
        visited = vector<vector<int>>(a, vector<int>(b,0));
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++){
                cin >> board[i][j];
                if(board[i][j] == 'P') cnt++;
            }
        }
        for(int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (board[i][j] == 'E') {
                    for (auto [dx, dy]: steps) {
                        int x = i + dx;
                        int y = j + dy;
                        if(inboard(x,y)){
                            switch (board[x][y]) {
                                case '-':
                                    board[x][y] = '@';
                                    break;
                                case 'P':
                                    //board[x][y] = '@';
                                    flag = false;
                                    break;
                            }
                        }
                    }
                }
            }
        }
        if(flag){
            dfs(a-1,b-1);
            flag = (cnt == 0);
        }
        string ans = flag ? "Pac-Man Win" : "Pac-Man Lose";
        cout<<ans<<endl;

    }

    return 0;
}



