## Dynamic Programming 

### Solving DP problems, steps
1. Recursive method
> 1. Brute force method
> 2. Try all possible ways
> 3. Get the base cases
> 4. Get the recurrence relation
> 5. take its count, min/max acc to statement

2. Memoization (Top-Down Approach)
> 1. Try starting whichever ans is required till base case
> 2. See overlaping problems
> 3. create a dp to store calculated values
> 4. store the calculated values in dp (converts recursion in memoization)
> 5. if subproblems are already solved, just return that value

3. Tabulation (Bottom up approach)
> 1. create a dp of indexes
> 2. Builds solution from base case to recurrence relation
> 3. solve base case from recursion
> 4. solve recurrence relation from recursion
> 5. return dp[0] or dp[n] as your method approaches the solution

4. Space optimization
> 1. try to reduce the space used by dp in one or two arrays only 
> 2. if see a pattern where only just previous values are required, then use two arrays 
> 3. if it is possible, then using 2 or 3 variable can also be space optimized.

## Shortcut way to DP
1. Try to repersent any problem in terms of indexes(1st to last and vice versa).
2. Do all possible stuffs on that index according to problem statement.
3. if problem states count all -> sum of all stuffs.
4. if min/max -> take min/max of your stuffs.

## Example

```java
/*

Maximum number of Non adjacent Elements

* You are given an array/list of ‘N’ integers.
* You are supposed to return the maximum sum of the subsequence with the
* constraint
* that no two elements are adjacent in the given array/list.
* 
* Note: A subsequence of an array/list is obtained by deleting some number of
* elements (can be zero) from the array/list,
* leaving the remaining elements in their original order.
* 
* e.g [1 2 4]
* => cannot pick 1,2 or 2,4 as they are adjacent
* => can pick 1,4 as not adjacent
* 
* e.g [2 1 1 2] [0 1 2 3]
* => cannot pick index 0-1 1-2 2-3
* => can pick 0-2 0-3 1-3
*/

public static void main(String args[]){
    int n=sc.nextInt();

    int arr[] = new int[n];
    for(int i=0;i<n;i++) {
        arr[i] = sc.nextInt();
    }        
    int maxSum = maxSumAdjElementsRecursion_1(arr,n-1);
    System.out.println("Brute Force 1:"+maxSum);
    
    int dp[] = new int[arr.length+1];
    for(int i=0;i<arr.length+1;i++) dp[i]=-1;
    maxSum = maxSumAdjElementsMemoization(arr, n-1, dp);
    System.out.println("DP Memoization:"+maxSum);
    
    maxSum = maxSumAdjElementsTabulation(arr);
    System.out.println("DP Tabulation:"+maxSum);
    
    maxSum = maxSumAdjElementsDPOptimized(arr);
    System.out.println("DP Optimized:"+maxSum);
}
```

### Recursion Method
```java
// Brute force: T.C:O(2^n), S.C: O(N) recursive stack 
public static int maxSumAdjElementsRecursion_1(int arr[],int n){
    // base cases
    if(n==0) return arr[n]; // if chosen 2nd index, then 0th is picked and 1st index is not picked
    if(n<0) return 0;   // if negative index, return 0

    // if picked current index, cannot pick adj element (n-1), but element next to adj can be picked i.e (n-2) 
    int picked = arr[n] + maxSumAdjElementsRecursion_1(arr, n-2);

    // if current not picked, then 0 is added to max sum, can pick adj element (n-1)
    int notPicked = 0 + maxSumAdjElementsRecursion_1(arr, n-1); 

    // return max of picked and not picked elements
    return Math.max(picked, notPicked);              
}
```

### DP Memoization Method
```java
// DP: better-> Memoization (required answer to base case then back)
// T.C: O(N), S.C: O(N)+O(N)
public static int maxSumAdjElementsMemoization(int arr[],int n,int dp[]){
    // base cases
    if(n==0) return arr[0];
    if(n<0) return 0;

    // check if there is a solution for subproblem
    if(dp[n]!=-1) return dp[n];

    // calculate the value of subproblem
    int pick = arr[n]+maxSumAdjElementsMemoization(arr, n-2, dp);
    int nonPick = 0 + maxSumAdjElementsMemoization(arr, n-1, dp);

    // store value in dp
    dp[n] = Math.max(pick,nonPick);
    return dp[n];
}
```

### DP Tabulation Method
```java
// DP Tabulation-> base case to required answer
// T.C: O(N), S.C: O(N);
public static int maxSumAdjElementsTabulation(int arr[]){
    int dp[] = new int[arr.length+1];

    // base case
    dp[0]=arr[0];

    for(int i=1;i<arr.length;i++){
        // if picked, then this cannot add prev, but i-2 yes, but if not out of bounds
        int pick = arr[i];
        if(i>1) pick+=dp[i-2];
        // if dont pick current, then can pick prev
        int nonPick = 0+dp[i-1];

        dp[i]= Math.max(pick,nonPick);
    }
    return dp[arr.length-1];
}
```

### Space Optimization
```java
// DP optimized
// T.C: O(N), S.C : O(1)
public static int maxSumAdjElementsDPOptimized(int arr[]){
    int prev = arr[0], prev2=0;

    for(int i=1;i<arr.length;i++){
        // if picked, then this cannot add prev, but i-2 yes, but if not out of bounds
        int pick = arr[i];
        if(i>1) pick+=prev2;
        // if dont pick current, then can pick prev
        int nonPick = 0+prev;

        int curri = Math.max(pick,nonPick);
        prev2=prev;
        prev=curri;
    }
    return prev;
}
```


### DP partition patterns

### Rules
> 1. Start with entire block 
> 2. Try all partitions(run a loop to try)
> 3. Return best possible 2 partitions

### Example
```java
/*

* Matrix Chain Multiplication
* 
* Given a sequence of matrices, find the most efficient way to multiply these
* matrices together. The efficient way is the one that involves the least
* number of multiplications.
* 
* The dimensions of the matrices are given in an array arr[] of size N (such
* that N = number of matrices + 1) where the ith matrix has the dimensions
* (arr[i-1] x arr[i]).
* 
* Input: N = 5
* arr = {40, 20, 30, 10, 30}
* Output: 26000
* Explanation: There are 4 matrices of dimension
* 40x20, 20x30, 30x10, 10x30. Say the matrices are
* named as A, B, C, D. Out of all possible combinations,
* the most efficient way is (A*(B*C))*D.
* The number of operations are -
* 20*30*10 + 40*20*10 + 40*10*30 = 26000.
*/

```