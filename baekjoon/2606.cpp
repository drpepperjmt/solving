#include <iostream>
#include <vector>

using namespace std;

bool visited[101];
vector<int> v[101];

int dfs(int src)
{
    if (visited[src])
    {
        return 0;
    }
    visited[src] = true;
    int ret = 1;
    for (auto &dst : v[src])
    {
        ret += dfs(dst);
    }

    return ret;
}

int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cout << dfs(1) - 1 << endl;

    return 0;
}