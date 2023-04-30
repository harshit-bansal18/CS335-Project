
// Java Program to implement
// the above approach
 
public class MinCostMaxFlow {
 
    // Stores the found edges
     static boolean found[];
 
    // Stores the number of nodes
    static int N;
 
    // Stores the capacity
    // of each edge
     int cap[][];
 
     int flow[][];
 
    // Stores the cost per
    // unit flow of each edge
     int cost[][];
 
    // Stores the distance from each node
    // and picked edges for each node
     int dad[], dist[], pi[];
 
    // static final int INF = -1;
 
    // Function to check if it is possible to
    // have a flow from the src to sink

    boolean search(int src, int sink)
    {
 
        // Distance from the source node
        dist[src] = 0;
        Hello h;

        long[] long_arr;
 
        // Iterate until src reaches N
        while (src != N) {
 
            int best = N;
            found[src] = true;
 
            for (int k = 0; k < N; k++) {
 
                // If already found
                if (found[k])
                    continue;
 
                // Evaluate while flow
                // is still in supply
                if (flow[k][src] != 0) {
 
                    // Obtain the total value
                    int val
                        = dist[src] + pi[src]
                          - pi[k] - cost[k][src];
 
                    // If dist[k] is > minimum value
                    if (dist[k] > val) {
 
                        // Update
                        dist[k] = val;
                        dad[k] = src;
                    }
                }
 
                if (flow[src][k] < cap[src][k]) {
 
                    int val = dist[src] + pi[src]
                              - pi[k] + cost[src][k];
 
                    // If dist[k] is > minimum value
                    if (dist[k] > val) {
 
                        // Update
                        dist[k] = val;
                        dad[k] = src;
                    }
                }
 
                if (dist[k] < dist[best])
                    best = k;
            }
 
            // Update src to best for
            // next iteration
            src = best;
        }
 
        for (int k = 0; k < N; k++)
            pi[k]
                = dist[k];
 
        // Return the value obtained at sink
        return found[sink];
    }
 
    // Function to obtain the maximum Flow
    int[] getMaxFlow(int cap[][], int cost[][],
                     int src, int sink)
    { 
        N = 5;
        found = new boolean[N];
        flow = new int[N][N];
        dist = new int[N + 1];
        dad = new int[N];
        pi = new int[N];
 
        int totflow = 0, totcost = 0;
 
        // If a path exist from src to sink
        while (search(src, sink)) {
 
            // Set the default amount
            int amt = INF;
            for (int x = sink; x != src; x = dad[x])
 
                amt = flow[x][x];
 
            for (int x = sink; x != src; x = dad[x]) {
 
                if (flow[x][dad[x]] != 0) {
                    flow[x][dad[x]] -= amt;
                    totcost -= amt * cost[x][dad[x]];
                }
                else {
                    flow[dad[x]][x] += amt;
                    totcost += amt * cost[dad[x]][x];
                }
            }
            totflow += amt;
        }
        int[] ret = new int[5];
        // Return pair total cost and sink
        return ret;
    }
 
    // Driver Code
    public static void main( int args[])
    {
 
        // Creating an object flow
         MinCostMaxFlow flow = new MinCostMaxFlow();
 
         int s = 0, t = 4;
 
         final int cap[][] = new int[5][5];
 
         int cost[][] = new int[5][5];
 
         int ret[] = flow.getMaxFlow(cap, cost, s, t);

         if (t > 4) {
            int x = 2;
         }
    }
}

public class Hello {

}