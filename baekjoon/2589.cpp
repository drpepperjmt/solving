#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

int n, m;
char treasureMap[51][51];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int go(pair<int, int> start)
{
    int dist = 0;
    bool visited[51][51] = {
        false,
    };
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(start, 0));
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        dist = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (treasureMap[nx][ny] == 'L' && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push(make_pair(make_pair(nx, ny), dist + 1));
                }
            }
        }
    }

    return dist;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            treasureMap[i][j] = c;
        }
    }

    vector<int> dists;
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (treasureMap[i][j] == 'L')
            {
                dists.push_back(go(make_pair(i, j)));
            }
        }
    }

    sort(dists.begin(), dists.end(), [](int a, int b) { return a > b; });

    cout << dists.front() << endl;
}