
import java.util.*;
 
public class Gfg {
 
  // Function to count ways
  public static int cntWays(List arr, int K)
  {
 
    int ans = 1;
 
    // Dp will be contain all pairs whose
    // sum is from 0 to K-1
    List dp
      = new ArrayList(Collections.nCopies(K, 0));
 
    long total = 0;
    dp.set(0, 1);
    int lessThanK = K - 1;
    for (int n : arr) {
 
      // Generate pairs for all sum
      // from 0 to K-1
      for (int i = lessThanK - n; i >= 0; i--) {
        dp.set(i + n, dp.get(i + n) + dp.get(i));
      }
 
      // Collecting all power sets
      // i.e 2^n
      ans *= 2;
      total += n;
    }
 
    if (total < 2 * K)
      return 0;
 
    // Collect groups whose sum is less
    // than K
    long sumlessthanK = 0;
    for (int i = 0; i <= lessThanK; ++i) {
      sumlessthanK += dp.get(i);
    }
 
    // A set less than k will be part of
    // either of the two groups, hence we
    // multiply by 2 for the same and
    // remove it from the power set
    ans -= 2 * sumlessthanK;
    return ans;
  }
 
  // Driver code
  public static void main(String[] args)
  {
 
    List arr = Arrays.asList(1, 2, 3, 4);
    int K = 4;
 
    // Function call
    System.out.println(cntWays(arr, K));
  }
}
 
// This code is contributed by hkdass001.