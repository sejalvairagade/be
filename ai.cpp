#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<omp.h>

using namespace std;

vector<int> graph[100];
bool visited[100];

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "\nBFS Traversal: ";

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        #pragma omp parallel for
        for(int i = 0; i < graph[node].size(); i++)
        {
            int adj = graph[node][i];

            if(!visited[adj])
            {
                visited[adj] = true;

                #pragma omp critical
                q.push(adj);
            }
        }
    }
}

void DFS(int start)
{
    stack<int> s;
    s.push(start);

    for(int i = 0; i < 100; i++)
        visited[i] = false;

    cout << "\nDFS Traversal: ";

    while(!s.empty())
    {
        int node = s.top();
        s.pop();

        if(!visited[node])
        {
            visited[node] = true;
            cout << node << " ";

            #pragma omp parallel for
            for(int i = 0; i < graph[node].size(); i++)
            {
                int adj = graph[node][i];

                if(!visited[adj])
                {
                    #pragma omp critical
                    s.push(adj);
                }
            }
        }
    }
}

int main()
{
    int n, e, u, v, start;

    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    cout << "Enter edges:\n";

    for(int i = 0; i < e; i++)
    {
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << "Enter starting node: ";
    cin >> start;

    for(int i = 0; i < 100; i++)
        visited[i] = false;

    BFS(start);
    DFS(start);

    return 0;
}


