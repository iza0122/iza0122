/*
test case 1:
input:
6 10
0 1 5
0 2 2
0 3 1
0 4 6
2 1 4
2 5 3
2 4 1
4 3 4
4 5 2
1 5 3

output:
0 3
2 4
0 2
4 5
1 5

/*
test case 2:
input:
6 9
0 1 4
0 2 3
1 2 1
1 3 2
2 4 4
3 4 2
3 5 6
4 5 3
2 3 5
output:
MST:
1 2
1 3
3 4
0 2
4 5

test case 3:
input:
5 7
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9
output:
MST:
0 1
1 2
1 4
0 3
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

graph input(int sodinh, int socanh)
{
    graph result(sodinh, vector<int>(sodinh, 0));
    for (int i = 0; i < socanh; i++)
    {
        int x, y, weight;
        cin >> x >> y;
        cin >> weight;
        result[x][y] = weight;
        result[y][x] = weight;
    }
    return result;
}

bool haveCycle(graph a)
{
    DSU dsu(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i; j < a.size(); j++)
        {
            if (i < j && a[i][j] >= 1)
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

typedef tuple<int, int, int> edge; //(u, v, weight)
typedef vector<edge> edges;

edges convertToList(graph a)
{
    edges result;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i; j < a.size(); j++)
        {
            if (i < j && a[i][j] >= 1)
                result.push_back({i, j, a[i][j]});
        }
    }
    return result;
}

void sortList(edges &a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        edge key = a[i];
        int j = i - 1;
        while (j >= 0 && get<2>(a[j]) > get<2>(key))
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

vector<pair<int, int>> Kruskal(graph a)
{
    edges list = convertToList(a);
    sortList(list);
    DSU dsu(a.size());
    vector<pair<int, int>> ET;
    for (edge e : list)
    {
        int u = get<0>(e);
        int v = get<1>(e);
        if (dsu.find(u) != dsu.find(v))
        {
            dsu.join(u, v);
            ET.push_back({u, v});
        }
    }
    return ET;
}

int main()
{
    int n, m;
    cout << "Nhap so dinh va so canh: ";
    cin >> n >> m;
    graph g = input(n, m);

    vector<pair<int, int>> mst = Kruskal(g);
    cout << "MST: " << endl;
    for (pair<int, int> edge : mst)
    {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}