// A Java program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph

class ShortestPath {

    static int graph[][]
			= new int[9][9];

    static int dist[] = new int[9];
    static boolean sptSet[] = new boolean[9];
	// A utility function to find the vertex with minimum
	// distance value, from the set of vertices not yet
	// included in shortest path tree
	static int V = 9;
    int max = 10000000;

	// A utility function to print the constructed distance
	// array
	void printSolution()
	{
		for (int i = 0; i < V; i++){
			System.out.println(i);
            System.out.println(dist[i]);
        }
	}

	// Function that implements Dijkstra's single source
	// shortest path algorithm for a graph represented using
	// adjacency matrix representation
	void dijkstra(int src)
	{
		// dist = new int[9]; // The output array.
								// dist[i] will hold
		// the shortest distance from src to i

		// sptSet[i] will true if vertex i is included in
		// shortest path tree or shortest distance from src
		// to i is finalized
		// sptSet = new boolean[9];

		// Initialize all distances as INFINITE and stpSet[]
		// as false
		for (int i = 0; i < V; i++) {
			dist[i] = max;
			sptSet[i] = false;
		}

		// Distance of source vertex from itself is always 0
		dist[src] = 0;

		// Find shortest path for all vertices
		for (int count = 0; count < V - 1; count++) {
			// Pick the minimum distance vertex from the set
			// of vertices not yet processed. u is always
			// equal to src in first iteration.
			int u = minDistance();
            // System.out.println("u: " + u);
			// Mark the picked vertex as processed
			sptSet[u] = true;

			// Update dist value of the adjacent vertices of
			// the picked vertex.
            int _count = 0;
			for (int v = 0; v < V; v++){
				// Update dist[v] only if is not in sptSet,
				// there is an edge from u to v, and total
				// weight of path from src to v through u is
				// smaller than current value of dist[v]
                
				if (!sptSet[v] && graph[u][v] != 0
					&& dist[u] != max
					&& dist[u] + graph[u][v] < dist[v]){
					dist[v] = dist[u] + graph[u][v];
                    _count++;
                }  
            }
            // System.out.println("count:" + _count);
		}

		// print the constructed distance array
		printSolution();
	}

    int minDistance()
	{
		// Initialize min value
		int min = max, min_index = -1;

		for (int v = 0; v < V; v++)
			if (sptSet[v] == false && dist[v] <= min) {
				min = dist[v];
				min_index = v;
			}

		return min_index;
	}

    static void add_edge(int num, int i, int j){
        graph[i][j] = num;
    }
	
}

class Init {
    // Driver's code
	public static void main(int[] args)
	{
		/* Let us create the example graph discussed above
		*/
        ShortestPath t = new ShortestPath();

        t.add_edge(4, 0, 1);
        t.add_edge(8, 0, 7);
        t.add_edge(4, 1, 0);
        t.add_edge(8, 1, 2);
        t.add_edge(11, 1, 7);
        t.add_edge(8, 2, 1);
        t.add_edge(7, 2, 3);
        t.add_edge(4, 2, 5);
        t.add_edge(2, 2, 8);
        t.add_edge(7, 3, 2);
        t.add_edge(9, 3, 4);
        t.add_edge(14, 3, 5);
        t.add_edge(9, 4, 3);
        t.add_edge(10, 4, 5);
        t.add_edge(4, 5, 2);
        t.add_edge(14, 5, 3);
        t.add_edge(10, 5, 4);
        t.add_edge(2, 5, 6);
        t.add_edge(2, 6, 5);
        t.add_edge(1, 6, 7);
        t.add_edge(6, 6, 8);
        t.add_edge(8, 7, 0);
        t.add_edge(11, 7, 1);
        t.add_edge(1, 7, 6);
        t.add_edge(7, 7, 8);
        t.add_edge(2, 8, 2);
        t.add_edge(6, 8, 6);
        t.add_edge(7, 8, 7);

        
		// Function call
		t.dijkstra(0);
	}
}
// This code is contributed by Aakash Hasija
