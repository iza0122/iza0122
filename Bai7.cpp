/*
test case 1:
input:
4 3
0 1
1 2
2 3
output:
Duong di Euler: 0 1 2 3

test case 2:
input:
6 9
0 1
0 2
1 2
1 3
2 4
3 4
3 5
4 5
2 3
output:
Duong di Euler: 1 0 2 3 5 4 3 1 2 4

test case 3:
input:
5 5
0 1
1 2
2 3
3 4
4 0
output:
Chu trinh Euler: 0 1 2 3 4 0
*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> graph;

graph input(int sodinh, int socanh)
{
    graph result(sodinh, vector<int>(sodinh, 0));
    for (int i = 0; i < socanh; i++)
    {
        int x, y;
        cin >> x >> y;
        result[x][y] = 1;
        result[y][x] = 1;
    }
    return result;
}

int undirectedDeg(graph a, int dinh)
{
    int deg = 0;
    for (int j = 0; j < a.size(); j++)
    {
        deg += a[dinh][j];
    }
    return deg;
}

bool haveEulerCycle(graph a)
{
    if (a.empty())
        return false;
    for (int i = 0; i < a.size(); i++)
    {
        if (undirectedDeg(a, i) % 2 != 0)
            return false;
    }
    return true;
}

bool haveEulerPath(graph a)
{
    if (a.empty())
        return false;
    int oddCount = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (undirectedDeg(a, i) % 2 != 0)
            oddCount++;
    }
    if (oddCount == 0 || oddCount == 2)
        return true;
    return false;
}

vector<int> printEuler(graph a, int start) // thuat toan Hierholzer
{
    vector<int> stack;
    vector<int> eulerPath;
    stack.push_back(start);
    while (!stack.empty())
    {
        int v = stack.back();
        bool found = false;
        for (int u = 0; u < a.size(); u++)
        {
            if (a[v][u] > 0)
            {
                stack.push_back(u);
                a[v][u]--;
                a[u][v]--;
                found = true;
                break;
            }
        }
        if (!found)
        {
            eulerPath.push_back(v);
            stack.pop_back();
        }
    }
    return eulerPath;
}

int main()
{
    int sodinh, socanh;
    cin >> sodinh >> socanh;
    graph a = input(sodinh, socanh);

    if (haveEulerCycle(a))
    {
        vector<int> eulerCycle = printEuler(a, 0);
        cout << "Chu trinh Euler: ";
        for (int v : eulerCycle)
        {
            cout << v << " ";
        }
        cout << endl;
    }
    else if (haveEulerPath(a))
    {
        int start;
        for (start = 0; start < a.size(); start++)
        {
            if (undirectedDeg(a, start) % 2 != 0)
                break;
        }
        vector<int> eulerPath = printEuler(a, start);
        cout << "Duong di Euler: ";
        for (int v : eulerPath)
        {
            cout << v << " ";
        }
    }
    return 0;
}