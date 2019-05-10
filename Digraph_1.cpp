#include <iostream>
using namespace std;


class AdjacencyMatrix {

private:
	int v; //vertices
	int ** adj; // list of pointers, each pointer points to a pointer(array)
	int **visited; // visited vertices

public:
	AdjacencyMatrix(int ver)
	{
		this->v = ver;
		adj = new int *[ver];
		visited = new int *[ver];
		for (int i = 0; i < ver; i++)
		{
			adj[i] = new int[ver];
			visited[i] = new int[ver];

			for (int j = 0; j < ver; j++)
			{
				adj[i][j] = 0; // initialize them to 0
				visited[i][j] = 0; // initialize them to 0
			}
		}
	}

	void addEgde(int src, int dest)
	{
		/*if (src > v || dest > v || src < 0 || dest < 0)
		{
			cout << "Invalid edge!\n";
		}
		else
		{*/
			adj[src][dest] = 1; // try this adj[src - 1][dest - 1] = 1;
		//}
	}

	void is_Directed(int edges)
	{
		int dir = 0;
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < v; j++)
			{
				if ((i != j) && (visited[i][j] == 0) && (visited[j][i] == 0))
				{
					if (adj[i][j] == 1 && adj[j][i] == 1)
					{
						visited[i][j] = 1;
						visited[j][i] = 1;

						dir += 2;
					}

				}
			}
		}
		if (dir == edges)
		{
			cout << "BOTH";
		}
		else
		{
			cout << "DIR";
		}
	}

	void display()
	{
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < v; j++)
				cout << adj[i][j] << "  ";
			cout << endl;
		}
	}
};

int main()
{
	int vertices, edges, src, dest;
	// cout<<"Enter number of nodes: ";
	cin >> vertices;
	cin >> edges;
	AdjacencyMatrix AM(vertices);
	//max_edges = nodes * (nodes - 1);
	for (int i = 0; i < edges; i++)
	{
		//cout<<"Enter edge (-1 -1 to exit): ";
		cin >> src >> dest;
		AM.addEgde(src, dest);
	}

	//AM.display();
	AM.is_Directed(edges);
	return 0;

}
