/*
You are tasked with implementing a dynamic segment tree to handle Range Minimum Queries (RMQ) on an initially empty array. Your segment tree should support dynamic insertions of values and range queries.
Input Format
• The first line contains an integer q, representing the number of operations.
• The next q lines contain either 1 idx val (insert val at index idx) or 2 LR (find the minimum in the range [L, R]).
Output Format
• For each RMQ query, output a single integer representing the minimum value in the specified range [L, R].
• Print Invalid input, if n is negative.
Constraints
1 ≤ q ≤ 10^5
0 ≤ idx ≤ n
1 ≤ val ≤ 10^9
0≤L≤R<n
*/

