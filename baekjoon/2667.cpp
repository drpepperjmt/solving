#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int v[26][26];
vector<int> complex;
int nHouse;
int n;

void go(int a, int b)
{
    if (v[a][b] != 1)
    {
        return;
    }
    v[a][b] = 0;
    nHouse += 1;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (a + i >= 0 && a + i < n)
            {
                if (b + j >= 0 && b + j < n)
                {
                    if (i != j && i != j * -1)
                    {
                        // cout << "test: " << a + i << ", " << b + i << endl;
                        go(a + i, b + j);
                    }
                }
            }
        }
    }

    return;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a;
            scanf("%1d", &a);
            v[i][j] = a;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 1)
            {
                go(i, j);
                complex.push_back(nHouse);
                nHouse = 0;
            }
        }
    }
    sort(complex.begin(), complex.end());

    cout << complex.size() << endl;
    for (auto &elem : complex)
    {
        cout << elem << endl;
    }
}