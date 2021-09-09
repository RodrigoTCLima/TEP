#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

enum State { NOT_FOUND, FOUND, PROCESSED };
const int MAX { 200010 };

vector<int> adj[MAX];

bool dfs(int u, vector<int>& o, vector<int>& state)
{
    if (state[u] == PROCESSED)
        return true;

    if (state[u] == FOUND)
        return false;

    state[u] = FOUND;

    for (auto v : adj[u])
        if (not dfs(v, o, state))
            return false;

    state[u] = PROCESSED;
    o.emplace_back(u);

    return true;
}

vector<int> topological_sort(int N)
{
    vector<int> o, state(N + 1, NOT_FOUND);

    
    for (int u = 1; u <= N; ++u)
        if (state[u] == NOT_FOUND and not dfs(u, o, state))
            return { };

    reverse(o.begin(), o.end());

    return o;
}

int main()
{
    vector<ii> es { { 1, 3 }, { 2, 1 }, { 2, 3 }, { 2, 4 }, { 3, 4 }, { 3, 8 }, { 4, 5 }, { 4, 7 },
        { 4, 8 }, { 5, 6 }, { 6, 9 }, { 7, 8 }, { 7, 9 }, { 8, 9 } };

    for (auto [u, v] : es)
        adj[u].emplace_back(v);

    auto o = topological_sort(9);

    for (auto u : o)
        cout << u << ' ';
    cout << '\n';

    return 0;
}
