// smaller the theorem, bigger the proof ~ sup3rcod3r

#include<bits/stdc++.h>

using namespace std;
 
#define SC            scanf
#define PF            printf
#define F             first
#define S             second
#define PB            push_back
#define MP            make_pair
#define FR(i,m,n)     for(i=m;i<n;i++)
#define ALL(c)        c.begin(), c.end()
#define EACH(it,v)    for(auto it = v.begin(); it != v.end(); ++it)
#define SORTA(v)      sort(ALL(v))
#define SORTD(v)      sort(ALL(v), greater<auto>())
#define BR            cout<<"\n"

typedef long long     ll;
typedef pair<int,int> pii;
typedef vector<int>   vi;

const int INF =       1e9;
const int MOD =       (INF+(1<<3)-1);
const int SZ =        300;

class Matrix
{
private:
  int m_height,m_width;
  int *arr;
  size_t index( int x, int y ) const { return x + m_width * y; }


public:
  Matrix(int x,int y)
  {
    m_height = y;
    m_width = x;
    arr = new int[ m_width * m_height ];
  }

  ~Matrix()
  {
    delete(arr);
  }

  void init(int val)
  {
    int i;
    FR(i,0,m_width * m_height)
      arr[i] = val;
  }

  int get(int x,int y)
  {
    return arr[index(x,y)];
  }

  bool set(int x,int y,int val)
  {
    if(x < 0 && x >= m_width && y >= m_height && y < 0)
      return false;
    else
      {
	arr[index(x,y)] = val;
	return true;
      }
  }

  void print()
  { int i,j;
    FR(i,0,m_height)
      {
	cout<<"\n";
	FR(j,0,m_width)
	  cout<<arr[index(i,j)]<<" ";
      }
    cout<<"\n";
  }
  
};


class Graph {

private :
  int V;
  vector<pii>* adj;
  vi visited;

public :

  Graph(int n)
  {
    V = n;
    adj = new vector<pii>[n+1];
  }

  void addEdge(int a, int b, int w, bool bi)
  {
    adj[a].PB(MP(b,w));
    if(bi)
      adj[b].PB(MP(a,w));
  }

  void dfs(int u, vi& visited)
  {
    cout<<u<<" ";
    visited[u] = 1;
    int i;
    FR(i,0,adj[u].size())
      if(visited[adj[u][i].F] == 0)
	dfs(adj[u][i].F,visited);
  }

  bool check_graph_connected_dfs(int s) { 
    vi visited(V,0);
    visited[0] = 1;
    dfs(s,visited); 
    return (find(ALL(visited), 0) == visited.end()); 
  } 

  
};


void test()
{
  int n = 6;
  Graph g(n);
  g.addEdge(1,2,1,true);
  g.addEdge(1,3,1,true);
  g.addEdge(1,4,1,true);
  g.addEdge(2,5,1,true);
  g.addEdge(2,6,1,true);
   
  vi visited(n,0);
  g.dfs(1,visited);
  BR;
  cout<<g.check_graph_connected_dfs(6);
}


int main()
{
  int t;
  SC("%d",&t);
  while(t--)
    {
    }
  test();
}
