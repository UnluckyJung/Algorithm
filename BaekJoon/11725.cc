#include <bits/stdc++.h>
using namespace std;

vector<int> node[100002];
int p[100002];
bool visit[100002];

int n;
const int root = 1;

#if 0

//  방문 하려는것이 이전에 방문한 노드인 경우.
void dfs(int cur){
    if(visit[cur]) return;
    visit[cur] = true;
    
    for(int nxt : node[cur]){
        if(p[nxt] == 0) p[nxt] = cur;
        dfs(nxt);
    }
}

#else if

//  방문 하려는것이 부모인 경우
void dfs(int cur) {

    for (int nxt : node[cur]) {
        if (nxt == p[cur])  continue;
        if (p[nxt] == 0) p[nxt] = cur;
        dfs(nxt);
    }
}

#endif


void solve() {
    dfs(root);

    for(int i = 2; i <= n; ++i){
        cout << p[i] << "\n";
    }
}

void input() {
    cin >> n;
    int a, b;
    for(int i = 0; i < n - 1 ; ++i){
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
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