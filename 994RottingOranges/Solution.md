# First Idea: Nx BFS/Djkstra's
This problem asks for the minimum time to wait such that ALL oranges have rotten. An immediate idea for how to solve this is to run Djkstra's shortest path n-times, one time from each initial rotten orange. 

Neighbours are defined by 4-directional adjacency, and this just becomes a graph problem.

This is implemented in SolOne.cpp