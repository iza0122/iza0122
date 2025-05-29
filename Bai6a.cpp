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
0 2
2 4
4 5
5 1

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
0 2
2 1
1 3
3 4
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
#define INF 1e7
using namespace std;

typedef vector<vector<int>> graph;

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

vector<pair<int, int>> primMST(graph a)
{
    vector<int> MST;
    vector<pair<int, int>> edges;
    vector<bool> inMST(a.size(), false);
    MST.push_back(0);
    inMST[0] = true;
    while (MST.size() < inMST.size())
    {
        int min = INF;
        int id1 = -1, id2 = -1;
        for (int u : MST)
        {
            for (int v = 0; v < inMST.size(); v++)
            {
                if (inMST[v] == false && a[u][v] < min && a[u][v] != 0)
                {
                    min = a[u][v];
                    id1 = u;
                    id2 = v;
                }
            }
        }
        if (id2 != -1)
        {
            MST.push_back(id2);
            inMST[id2] = true;
            edges.push_back({id1, id2});
        }
        else
            break;
    }
    return edges;
}

int main()
{
    int sodinh, socanh;
    cin >> sodinh >> socanh;
    graph a = input(sodinh, socanh);

    vector<pair<int, int>> mstEdges = primMST(a);

    cout << "MST: " << endl;
    for (pair<int, int> edge : mstEdges)
    {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}