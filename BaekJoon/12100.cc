#if 01

#include <bits/stdc++.h>
#define pp pair<bool, int>
#define merge first
#define data second
using namespace std;

int board[21][21];
int n;
int answer;

void move(int i) {
    deque<pp> q;

    for (int ii = 0; ii < n; ++ii) {
        if (board[i][ii] == 0)continue;
        
        if (!q.empty()) {
            if (q.back().merge == false && q.back().data == board[i][ii]) {
                q.pop_back();
                q.push_back({ true, board[i][ii] * 2 });
                continue;
            }
        }
        q.push_back({ false, board[i][ii] });
    }
    
    while (q.size() < n) {
        q.push_back({ false, 0 });
    }

    for (int ii = 0; ii < n; ++ii) {
        board[i][ii] = q.front().data;  q.pop_front();
    }
}

void rotate(int k) {
	int backup_board[21][21];

	while (k--) {
		memcpy(backup_board, board, sizeof(board));

		for (int i = 0; i < n; ++i) {
			for (int ii = 0; ii < n; ++ii) {
				board[i][ii] = backup_board[(n - 1) - ii][i];
			}
		}
	}

}

void find_max() {
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii)
            answer = max(answer, board[i][ii]);
    }
}

void dfs(int move_cnt) {
    if (move_cnt == 5) {
        find_max();
        return;
    }

    int backup_board[21][21];
    memcpy(backup_board, board, sizeof(board));

    for (int k = 0; k < 4; ++k) {
        rotate(k);
        for (int i = 0; i < n; ++i) move(i);

        dfs(move_cnt + 1);
        memcpy(board, backup_board, sizeof(board));
    }
}

void solve() {
    dfs(0);
    cout << answer << "\n";
}

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii)  cin >> board[i][ii];
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();
    solve();

    return 0;
}

#else


#include <bits/stdc++.h>
#define pp pair<int, bool>
using namespace std;

int board[21][21];
int n, answer;
deque<pp> dq;

void output() {
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii)cout << board[i][ii] << " ";
        cout << "\n";
    }
}

void fill_q(int data) {
    if (data == 0)return;
    if (!dq.empty()) {
        if (dq.back().first == data && dq.back().second == false) {
            dq.pop_back();
            dq.push_back({ data * 2, true });
            return;
        }
    }
    dq.push_back({ data, false });
}

void move(int dir) {
    if (dir == 0) {
        for (int ii = 0; ii < n; ++ii) {
            for (int i = 0; i < n; ++i) fill_q(board[i][ii]);

            while ((int)dq.size() < n)dq.push_back({ 0,true });
            for (int i = 0; i < n; ++i) {
                board[i][ii] = dq.front().first; dq.pop_front();
            }
        }
    }

    else if (dir == 1) {
        for (int ii = 0; ii < n; ++ii) {
            for (int i = n-1; i >= 0; --i) fill_q(board[i][ii]);

            while ((int)dq.size() < n)dq.push_back({ 0,true });
            for (int i = n-1; i >=0; --i) {
                board[i][ii] = dq.front().first; dq.pop_front();
            }
        }
    }

    else if (dir == 2) {
        for (int i = 0; i < n; ++i) {
            for (int ii = 0; ii < n; ++ii) fill_q(board[i][ii]);

            while ((int)dq.size() < n)dq.push_back({ 0,true });
            for (int ii = 0; ii < n; ++ii) {
                board[i][ii] = dq.front().first; dq.pop_front();
            }
        }
    }

    else if (dir == 3) {
        for (int i = 0; i < n; ++i) {
            for (int ii = n-1; ii >= 0; --ii) fill_q(board[i][ii]);

            while ((int)dq.size() < n)dq.push_back({ 0,true });
            for (int ii = n-1; ii >= 0; --ii) {
                board[i][ii] = dq.front().first; dq.pop_front();
            }
        }
    }
}

void dfs(int move_cnt) {
    //output();
    if (move_cnt == 5) {
        for (int i = 0; i < n; ++i) {
            for (int ii = 0; ii < n; ++ii) answer = max(answer, board[i][ii]);
        }
        return;
    }

    int save_board[21][21] = { 0, };
    memcpy(save_board, board, sizeof(board));

    for (int dir = 0; dir < 4; ++dir) {
        move(dir);
        dfs(move_cnt + 1);
        memcpy(board, save_board, sizeof(board));
    }
}

void solve() {
    dfs(0);
}

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n; ++ii)   cin >> board[i][ii];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    cin.tie(NULL);  cout.tie(NULL);

    input();
    solve();
    cout << answer;
    return 0;
}

#endif