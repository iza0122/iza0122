/*
Test case 1:
Input:
5 5 0
0 1
0 2
1 2
3 4
4 0

Output:
DFS: 0 4 3 2 1
BFS: 0 1 2 4 3
*/

/*
Test case 2:
Input:
4 4 1
0 1
0 2
1 3
2 3

Output:
DFS: 0 2 3 1
BFS: 0 1 2 3
*/

/*
Test case 3:
Input:
6 3 0
0 1
2 3
4 5

Output:
DFS: 0 1
BFS: 0 1
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

typedef vector<vector<int>> graph;

graph input(int sodinh, int socanh, bool isDirected)
{
	graph result(sodinh, vector<int>(sodinh, 0));
	if (!isDirected)
	{
		for (int i = 0; i < socanh; i++)
		{
			int x, y;
			cin >> x >> y;
			result[x][y] = 1;
			result[y][x] = 1;
		}
	}
	else
	{
		for (int i = 0; i < socanh; i++)
		{
			int x, y;
			cin >> x >> y;
			result[x][y] = 1;
		}
	}
	return result;
}

void DFS(graph a, int dinh)
{
	vector<bool> visited(a.size(), false);
	stack<int> s;
	visited[dinh] = true;
	s.push(dinh);
	while (!s.empty())
	{
		int v = s.top();
		s.pop();
		cout << v << " ";
		for (int i = 0; i < a[v].size(); i++)
		{
			if (a[v][i] && !visited[i])
			{
				visited[i] = true;
				s.push(i);
			}
		}
	}
	cout << endl;
}

void BFS(graph a, int dinh)
{
	queue<int> q;
	vector<bool> visited(a.size(), false);
	visited[dinh] = true;
	q.push(dinh);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		cout << v << " ";
		for (int i = 0; i < a[v].size(); i++)
		{
			if (a[v][i] && !visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	int sodinh, socanh;
	bool isDirected;
	cin >> sodinh >> socanh >> isDirected;
	graph a = input(sodinh, socanh, isDirected);
	cout << "DFS: ";
	DFS(a, 0);
	cout << "BFS: ";
	BFS(a, 0);
	return 0;
}