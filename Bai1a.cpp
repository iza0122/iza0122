/*
test case 1:
input:
4 3
1 2
2 3
3 4
output:
1: 2
2: 3
3: 4
4:
Bac cua dinh 1: 1
Bac cua dinh 2: 1
Bac cua dinh 3: 1
Bac cua dinh 4: 0

test case 2:
input:
5 5
1 2
1 3
2 3
3 4
5 1
output:
1: 2 3
2: 3
3: 4
4:
5: 1
Bac cua dinh 1: 2
Bac cua dinh 2: 1
Bac cua dinh 3: 1
Bac cua dinh 4: 0
Bac cua dinh 5: 1

test case 3:
input:
3 0
output:
1:
2:
3:
Bac cua dinh 1: 0
Bac cua dinh 2: 0
Bac cua dinh 3: 0
*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> graph;

graph input(int sodinh, int socanh, bool isDirected)
{
    graph result(sodinh + 1);
    if (!isDirected)
    {
        for (int i = 0; i < socanh; i++)
        {
            int x, y;
            cin >> x >> y;
            result[x].push_back(y);
            result[y].push_back(x);
        }
    }
    else
    {
        for (int i = 0; i < socanh; i++)
        {
            int x, y;
            cin >> x >> y;
            result[x].push_back(y);
        }
    }
    return result;
}

void printGraph(graph a, int sodinh)
{
    for (int i = 1; i <= sodinh; i++)
    {
        cout << i << ": ";
        for (int j : a[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int undirectedDeg(graph a, int dinh)
{
    return a[dinh].size();
}

int outdirectedDeg(graph a, int dinh)
{
    return a[dinh].size();
}

int indirectedDeg(graph a, int dinh)
{
    int deg = 0;
    for (int i = 1; i < a.size(); i++)
    {
        for (int j : a[i])
        {
            if (j == dinh)
            {
                deg++;
            }
        }
    }
    return deg;
}

int main()
{
    int n, m;
    cin >> n >> m;
    graph a = input(n, m, true);
    printGraph(a, n);
    for (int i = 1; i <= n; i++)
    {
        cout << "Bac cua dinh " << i << ": " << outdirectedDeg(a, i) << endl;
    }
    return 0;
}