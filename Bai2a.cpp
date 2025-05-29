/*
test case 1:
input:
5 5
1 2
2 3
3 4
4 5
5 1
output:
1: 2 5
2: 1 3
3: 2 4
4: 3 5
5: 4 1
Isolated vertices:
Pendant vertices:
Pendant edges:
Loop edges:
Multi edges:
Is multi: Khong
Is simple: Co
Is null: Khong
Is regular: Co

test case 2:
input:
4 4
1 2
2 2
2 3
3 4
output:
1: 2
2: 1 2 3
3: 2 4
4: 3
Isolated vertices:
Pendant vertices: 1 4
Pendant edges: (1, 2) (4, 3)
Loop edges: (2, 2)
Multi edges:
Is multi: Khong
Is simple: Khong
Is null: Khong
Is regular: Khong

test case 3:
input:
3 0
output:
1:
2:
3:
Isolated vertices: 1 2 3
Pendant vertices:
Pendant edges:
Loop edges:
Multi edges:
Is multi: Khong
Is simple: Co
Is null: Co
Is regular: Co
*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> graph;

graph input(int sodinh, int socanh)
{
    if (sodinh <= 0 || socanh < 0)
    {
        return graph();
    }
    graph result(sodinh + 1);
    for (int i = 0; i < socanh; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
        {
            result[x].push_back(x);
            continue;
        }
        result[x].push_back(y);
        result[y].push_back(x);
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
    if (a.empty())
    {
        return 0;
    }
    int loopCount = 0;
    for (int j : a[dinh])
    {
        if (j == dinh)
            loopCount++;
    }
    return a[dinh].size() + loopCount;
}

void printIsolatedvertices(graph a, int sodinh)
{
    cout << "Isolated vertices: ";
    for (int i = 1; i <= sodinh; i++)
    {
        if (a[i].empty())
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void printpendantvertices(graph a, int sodinh)
{
    cout << "Pendant vertices: ";
    for (int i = 1; i <= sodinh; i++)
    {
        if (undirectedDeg(a, i) == 1)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void printPendantEdges(graph a, int sodinh)
{
    cout << "Pendant edges: ";
    for (int i = 1; i <= sodinh; i++)
    {
        if (undirectedDeg(a, i) == 1)
        {
            cout << "(" << i << ", " << a[i][0] << ") ";
        }
    }
    cout << endl;
}

void printLoopEdges(graph a, int sodinh)
{
    cout << "Loop edges: ";
    for (int i = 1; i <= sodinh; i++)
    {
        for (int j : a[i])
        {
            if (j == i)
            {
                cout << "(" << i << ", " << j << ") ";
            }
        }
    }
    cout << endl;
}

void printMultiEdges(graph a, int sodinh)
{
    cout << "Multi edges: ";
    for (int i = 1; i <= sodinh; i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            for (int k = j + 1; k < a[i].size(); k++)
            {
                if (a[i][j] == a[i][k])
                {
                    cout << "(" << i << ", " << a[i][j] << ") ";
                }
            }
        }
    }
    cout << endl;
}

bool isLoop(graph a, int dinh)
{
    for (int j : a[dinh])
    {
        if (j == dinh)
        {
            return true;
        }
    }
    return false;
}

bool isMulti(graph a, int sodinh)
{
    for (int i = 1; i <= sodinh; i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            for (int k = j + 1; k < a[i].size(); k++)
            {
                if (a[i][j] == a[i][k])
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool isSimple(graph a, int sodinh)
{
    if (a.empty())
        return false;
    for (int i = 1; i <= sodinh; i++)
    {
        for (int j : a[i])
        {
            if (j == i || isMulti(a, sodinh))
                return false;
        }
    }
    return true;
}

bool isNull(graph a, int sodinh)
{
    for (int i = 1; i <= sodinh; i++)
    {
        if (!a[i].empty())
            return false;
    }
    return true;
}

bool isRegular(graph a, int sodinh)
{
    if (a.empty())
        return false;
    int degree = undirectedDeg(a, 1);
    for (int i = 2; i <= sodinh; i++)
    {
        if (undirectedDeg(a, i) != degree)
            return false;
    }
    return true;
}

bool isComplete(graph a, int sodinh)
{
    if (a.empty())
        return false;
    for (int i = 1; i <= sodinh; i++)
    {
        if (isLoop(a, i) || undirectedDeg(a, i) != sodinh - 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int sodinh, socanh;
    cin >> sodinh >> socanh;
    graph a = input(sodinh, socanh);
    printGraph(a, sodinh);
    printIsolatedvertices(a, sodinh);
    printpendantvertices(a, sodinh);
    printPendantEdges(a, sodinh);
    printLoopEdges(a, sodinh);
    printMultiEdges(a, sodinh);

    cout << "Is multi: " << (isMulti(a, sodinh) ? "Co" : "Khong") << endl;
    cout << "Is simple: " << (isSimple(a, sodinh) ? "Co" : "Khong") << endl;
    cout << "Is null: " << (isNull(a, sodinh) ? "Co" : "Khong") << endl;
    cout << "Is regular: " << (isRegular(a, sodinh) ? "Co" : "Khong") << endl;

    return 0;
}
