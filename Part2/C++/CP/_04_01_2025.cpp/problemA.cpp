cpp

/*

One day, the schoolboy Mark misbehaved, so the teacher Sasha called him to the whiteboard.

Sasha gave Mark a table with n
rows and m columns. His task is to arrange the numbers 0,1,…,n⋅m−1 in the table (each number must be used exactly once) in such a way as to maximize the sum of MEX∗ across all rows and columns. More formally, he needs to maximize
∑i=1nmex({ai,1,ai,2,…,ai,m})+∑j=1mmex({a1,j,a2,j,…,an,j}),
where ai,j is the number in the i-th row and j

-th column.

Sasha is not interested in how Mark arranges the numbers, so he only asks him to state one number — the maximum sum of MEX across all rows and columns that can be achieved.

∗
The minimum excluded (MEX) of a collection of integers c1,c2,…,ck is defined as the smallest non-negative integer x which does not occur in the collection c

.

For example:

    mex([2,2,1])=0

, since 0
does not belong to the array.
mex([3,1,0,1])=2
, since 0 and 1 belong to the array, but 2
does not.
mex([0,3,1,2])=4
, since 0, 1, 2, and 3 belong to the array, but 4 does not. 

The question revolves around arranging numbers in a grid (table) in such a way as to maximize a specific mathematical property. Here's a breakdown:
Key Concepts:

Grid Dimensions:
The table has nn rows and mm columns, creating a grid with n×mn×m cells.

Numbers to Arrange:
The numbers 0,1,2,…,(n⋅m−1)0,1,2,…,(n⋅m−1) are to be arranged in the grid. Each number must appear exactly once.

MEX (Minimum Excluded Value):
For a given set of numbers, the MEX is the smallest non-negative integer that does not appear in the set.

*/