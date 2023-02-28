// Java program for Kruskal's algorithm to
// find Minimum Spanning Tree of a given
// connected, undirected and  weighted graph
  
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
  
public class KruskalsMST {
  
      // defines edge structure
    static class Edge {
        int src, dest, weight;
  
        public Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }
    }
      
  // defines subset element structure
    static class Subset {
        int parent, rank;
  
        public Subset(int parent, int rank) {
            this.parent = parent;
            this.rank = rank;
        }
    }
  
    // Starting point of program execution
    public static void main(String[] args) {
        /***************************************** 
         * Let us create following weighted graph
                10
           0--------1
           | -      |
          6|   5-   |15
           |      - |
           2--------3
               4       
         *****************************************/
        int V = 4;
        List graphEdges = new ArrayList(List.of(
                new Edge(0, 1, 10),                
                new Edge(0, 2, 6),    
                new Edge(0, 3, 5),
                new Edge(1, 3, 15),
                new Edge(2, 3, 4)
        ));
        
          // Step 1: sort the edges in non-decreasing order 
        // (increasing with repetition allowed)
  
        kruskals(V, graphEdges);
    }
  
  
    private static void kruskals(int V, List edges) {
        int j = 0;
        int noOfEdges = 0;
        // Allocate memory for creating V subsets
        Subset subsets[] = new Subset[V];
        
          // Allocate memory for results
        Edge results[] = new Edge[V];
  
        // Create V subsets with single elements
        for (int i = 0; i < V; i++) {
            subsets[i] = new Subset(i, 0);
        }
  
        // Number of edges to be taken is equal to V-1
        while (noOfEdges < V - 1) {
            // Step 2: Pick the smallest edge. And increment
            // the index for next iteration
            Edge nextEdge = edges.get(j);
            int x = findRoot(subsets, nextEdge.src);
            int y = findRoot(subsets, nextEdge.dest);
  
            // If including this edge doesn't cause cycle,
            // include it in result and increment the index
            // of result for next edge
            if (x != y) {
                results[noOfEdges] = nextEdge;
                union(subsets, x, y);
                noOfEdges++;
            }
  
            j++;
        }
  
        // print the contents of result[] to display the built MST
        System.out.println("Following are the edges of the constructed MST:");
        System.out.println("-----------------------------------------------");
        int minCost = 0;
        for (int i = 0; i < noOfEdges; i++) {
            System.out.println(results[i].src + " - " + results[i].dest + ": " + results[i].weight);
            minCost += results[i].weight;
        }
        System.out.println("-----------------------------------------------");
        System.out.println("Total cost of MST: "+minCost);
  
    }
  
    private static void union(Subset[] subsets, int x, int y) {
        int rootX = findRoot(subsets, x);
        int rootY = findRoot(subsets, y);
  
        if (subsets[rootY].rank < subsets[rootX].rank) {
            subsets[rootY].parent = rootX;
        } else if (subsets[rootX].rank < subsets[rootY].rank) {
            subsets[rootX].parent = rootY;
        } else {
            subsets[rootY].parent = rootX;
            subsets[rootX].rank++;
        }
    }
  
    private static int findRoot(Subset[] subsets, int i) {
        if (subsets[i].parent == i)
            return subsets[i].parent;
  
        subsets[i].parent = findRoot(subsets, subsets[i].parent);
        return subsets[i].parent;
    }
}
// This code is contributed by Salvino D'sa