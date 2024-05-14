# -*- coding: utf-8 -*-
"""
Python program to implement
Depth-First-Search (DFS) algorithm
@author: Siddhartha
"""

# Adjacency List for Graph
GRAPH = {
        'S': ['A', 'B', 'C'],
        'A': ['D'],
        'B': ['E'],
        'C': ['F'],
        'D': ['G'],
        'E': [],
        'F': [],
        'G': []
}


# Recursive Depth-First-Search
def recursive_dfs(node):
    if node not in VISITED:                 # Check if node is already visited
        print(node)
        VISITED.add(node)                   # Add node to set of visited nodes
        for adjacent in GRAPH[node]:        # For adjacent nodes perform DFS
            recursive_dfs(adjacent)


# Depth-First-Search using Stack
def iterative_dfs(start):
    STACK.append(start)                     # Start with starting node
    VISITED.add(start)
    print(start)
    while len(STACK) != 0:
        flag = False                        # For checking of unvisited nodes
        for adjacent in GRAPH[STACK[-1]]:   # For all adjacent nodes
            if adjacent not in VISITED:
                print(adjacent)
                STACK.append(adjacent)      # New unvisited node is pushed
                VISITED.add(adjacent)
                flag = True
                break
        if not flag:                        # All adjacent nodes are visited
            STACK.pop()                     # Remove from stack


VISITED = set()
print('Recursive Depth First Search')
recursive_dfs('S')                      # Recursive function call with start

STACK = []
VISITED = set()
print('\nIterative Depth First Search using Stack')
iterative_dfs('S')                      # Iterative function call with start
