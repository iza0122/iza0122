/*
test case 1:
input:
4 3
0 1
1 2
2 3
output:
Khong chua chu trinh

test case 2:
input:
4 4
0 1
1 2
2 3
3 0
output:
Co chua chu trinh

test case 3:
input:
6 5
0 1
1 2
3 4
4 5
5 3
output:
Co chua chu trinh
*/
#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> graph;
typedef vector<int> set;
struct DSU
{
    set parent;
    DSU(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int v)
    {
        if (v == parent[v])
            return v;
        return find(parent[v]);
    }

    void join(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
            parent[b] = a;
    }
};

bool haveCycle(graph a)
{
    DSU dsu(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i; j < a.size(); j++)
        {
            if (i < j && a[i][j] == 1)
            {
                if (dsu.find(i) != dsu.find(j))
                    dsu.join(i, j);
                else
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    graph a;
    int sodinh, socanh;
    cin >> sodinh >> socanh;
    a.resize(sodinh, vector<int>(sodinh, 0));
    for (int i = 0; i < socanh; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    if (haveCycle(a))
        cout << "Co chua chu trinh" << endl;
    else
        cout << "Khong chua chu trinh" << endl;
    return 0;
}