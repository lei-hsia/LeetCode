# LeetCode
C++, Java, Python
All problems on LeetCode

Huffman coding: categorize by frequency, then build the tree bottom-up starting from the least frequent to the most. When you have 2 leaves, pile up(only allow 2 children nodes); when the new frequency equals any of the previous sum, move up to the higher layer.

DP essence: If recursive algorithm computes the same subproblems over and over and over again, storing the answer for each subproblem in a table to look up instead of recompute

Greedy algorithm essence: making the local optimal choice at each stage with the hope to find the global optimum.

con: often the cumulative local optima does NOT lead to final globla optima.

Problems: for a greedy approach to work has 2 properties:
  a. Greedy -- choice property: A golbal optima can be arrived at by selecting a local optima.
  b. Optimal Substructure: An optima solution to the problem contains an optima solution to subproblems.
