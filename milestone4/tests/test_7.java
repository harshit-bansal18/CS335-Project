class Knapsack {
 
    // A utility function that returns
    // maximum of two integers
    int max(int a, int b) { return (a > b) ? a : b; }

    int wt[] = new int[3];
    int val[] = new int[3];
 
    // Returns the maximum value that
    // can be put in a knapsack of
    // capacity W
    int knapSack(int W, int n)
    {
        // Base Case
        if (n == 0 || W == 0)
            return 0;
 
        // If weight of the nth item is
        // more than Knapsack capacity W,
        // then this item cannot be included
        // in the optimal solution
        if (wt[n - 1] > W)
            return knapSack(W, n - 1);
 
        // Return the maximum of two cases:
        // (1) nth item included
        // (2) not included
        else
            return max(val[n - 1]
                           + knapSack(W - wt[n - 1], n - 1),
                       knapSack(W, n - 1));
    }
}

class MainClass{

    // Driver code
    public static void main(int args)
    {   
        Knapsack knap = new Knapsack();

        knap.wt[0] = 10;
        knap.wt[1] = 20;
        knap.wt[2] = 30;

        knap.val[0] = 60;
        knap.val[1] = 100;
        knap.val[2] = 120;
        int W = 50;
        int n =3;
        int result = knap.knapSack(W, n);
        System.out.println(result);
    }
}