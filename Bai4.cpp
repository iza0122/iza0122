/*
test case 1:
input:
5 4
0 1
1 2
3 4
2 0
output:
So thanh phan lien thong: 2

test case 2:
input:
6 3
0 1
2 3
4 5
output:
So thanh phan lien thong: 3

test case 3:
input:
4 6
0 1
0 2
0 3
1 2
1 3
2 3
output:
So thanh phan lien thong: 1
*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> graph;

void DFSAssign(graph a, int dinh, vector<int> &lable, int lableid)
{
    lable[dinh] = lableid;
    for (int i = 0; i < a[dinh].size(); i++)
    {
        if (lable[a[dinh][i]] == 0)
        {
            DFSAssign(a, a[dinh][i], lable, lableid);
        }
    }
}

int countConnectedComponents(graph a)
{
    int count = 0;
    vector<int> lable(a.size(), 0);
    for (int i = 0; i < a.size(); i++)
    {
        if (lable[i] == 0)
        {
            count++;
            DFSAssign(a, i, lable, count);
        }
    }
    return count;
}

int main()
{
    int sodinh, socanh;
    cin >> sodinh >> socanh;
    graph a(sodinh);
    for (int i = 0; i < socanh; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int c = countConnectedComponents(a);
    cout << "So thanh phan lien thong: " << c << endl;
    return 0;
}