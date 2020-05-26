#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int box[1001][1001];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
bool visited[1001][1001];

typedef struct
{
    int x;
    int y;
    int len;
} Node;

int main()
{
    int m, n;
    cin >> n >> m;
    queue<Node> q;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;

            if (a == 1)
            {
                Node node;
                node.x = i;
                node.y = j;
                node.len = 0;
                q.push(node);
            }
            else if (a == -1)
            {
                visited[i][j] = true;
            }
            box[i][j] = a;
        }
    }

    int len = 0;
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int nowLen = q.front().len;
        q.pop();

        if (visited[x][y])
        {
            continue;
        }

        visited[x][y] = true;
        len = nowLen;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                if (!visited[nx][ny])
                {
                    Node node;
                    node.x = nx;
                    node.y = ny;
                    node.len = nowLen + 1;
                    q.push(node);
                }
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!visited[i][j])
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << len << endl;

    return 0;
}