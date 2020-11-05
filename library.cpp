#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class graph
{
    private:
    int edges;
    int **m;
    public:
    graph(int noedges)//-----------constructor--------------------------------- 
    {
    edges=noedges;
    makegraph();
    addgraph();
    }//------------------------------------------------------------------------
    void makegraph();
    void addgraph();
    void showgraph();
    void BFS(int start);
    void DFS(int start);
};

void graph::BFS(int start)
{
    cout<<"BFS of the given graph ";
    queue<int> q;
    int j;
    int visited[edges]={0};
    q.push(start);
    visited[start]=1;
    while(!q.empty())
    {
        j=q.front();
        q.pop();
        cout<<j<<" ";
        for(int i=0;i<edges;i++)
        {
            if(m[j][i]==1 && visited[i]==0)
            {
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

void graph::DFS(int start)
{
    int static visited[6]={0};
    if(visited[start]==0)
    {
        cout<<start<<" ";
        visited[start]=1;
        for(int i=0;i<edges;i++)
        {
            if(m[start][i]==1 && visited[i]==0)
            {
                graph::DFS(i);
            }
        }
    }
}

void graph::makegraph()
{
    m = new int*[edges];
    for(int i = 0; i < edges; ++i)
    m[i] = new int[edges];
    for(int i=0;i<edges;i++)
    for(int j=0;j<edges;j++)
    m[i][j]=0;
}

void graph::addgraph()
{
    vector<int> v;
    vector<int> :: iterator it;
    int temp;
    for(int i=0;i<edges;i++)
    {
        v.clear();
        cout<<"Enter the edges connected to edge"<<i<<endl;
        cout<<"Enter -1 for next edge/Exit";
        do{
        cin>>temp;
        if(temp==-1)
        break;
        v.push_back(temp);
        }while(temp!=-1);
        it=v.begin();         
        while(it!=v.end())
        {
        m[i][*it]=1;
        it++;
        }
    }
}

void graph::showgraph()
{
    for(int i=0;i<edges;i++)
    {
        for(int j=0;j<edges;j++)
        {
            cout<<m[i][j]<<" ";
        }
    cout<<endl;
    }
}

int main()
{
    graph g(6);
    g.showgraph();
    g.DFS(0);
    return 0;
}