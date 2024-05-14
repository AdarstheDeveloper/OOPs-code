# -*- coding: utf-8 -*-
"""
Python program to implement
Breadth-First-Search (BFS) algorithm
@author: Siddhartha
"""


class Queue:
    '''
    Queue data structure using an array for BFS.
    Supported operations: isEmpty, enqueue, dequeue.
    '''
    def __init__(self):
        self.queue = []

    def isEmpty(self):
        if len(self.queue) == 0:
            return True
        else:
            return False

    def enqueue(self, element):
        self.queue += [element]

    def dequeue(self):
        if self.isEmpty:
            front = self.queue[0]
            self.queue = self.queue[1:]
            return front
        else:
            return None


# Function to perform BFS traversal
def bfs(graph, start):
    queue = Queue()                      # Initialize queue data structure
    queue.enqueue(start)
    visited = [start]                    # Initialize visited list

    while(not queue.isEmpty()):
        node = queue.dequeue()           # Get front node in queue
        print(node, end=' ')

        for adjacent in graph[node]:     # For all adjacent nodes
            if adjacent not in visited:  # Check if node is visited
                queue.enqueue(adjacent)  # Add to queue
                visited.append(adjacent) # Add node to visited


# Driver Code
if __name__ == '__main__':
    graph = {                            # Adjacency List for Graph
            'S': ['A', 'B', 'C'],
            'A': ['D'],
            'B': ['E'],
            'C': ['F'],
            'D': ['G'],
            'E': [],
            'F': [],
            'G': []
    }
    print('Breadth First Search Traversal')
    bfs(graph, 'S')                      # BFS function call
