import java.util.PriorityQueue;
import java.util.Comparator;

class HuffmanNode {
    int item;
    char c;
    HuffmanNode left;
    HuffmanNode right;
}

class ImplementComparator implements Comparator<HuffmanNode> {
    public int compare(HuffmanNode x, HuffmanNode y) {
        return x.item - y.item;
    }
}

public class Program6a {
    public static void printCode(HuffmanNode root, String s) {
        if (root.left == null && root.right == null && Character.isLetter(root.c)) {
            System.out.println(root.c + " | " + s);
            return;
        }
        printCode(root.left, s + "0");
        printCode(root.right, s + "1");
    }

    public static void main(String[] args) {
        int n = 4;
        char[] charArray = { 'A', 'B', 'C', 'D' };
        int[] charfreq = { 5, 1, 6, 3 };
        PriorityQueue<HuffmanNode> q = new PriorityQueue<HuffmanNode>(n, new ImplementComparator());
        for (int i = 0; i < n; i++) {
            HuffmanNode hn = new HuffmanNode();
            hn.c = charArray[i];
            hn.item = charfreq[i];
            hn.left = null;
            hn.right = null;
            q.add(hn);
        }
        HuffmanNode root = null;
        while (q.size() > 1) {
            HuffmanNode x = q.peek();
            q.poll();
            HuffmanNode y = q.peek();
            q.poll();
            HuffmanNode f = new HuffmanNode();
            f.item = x.item + y.item;
            f.c = '-';
            f.left = x;
            f.right = y;
            root = f;
            q.add(f);
        }
        System.out.println("Char | Huffman code ");
        System.out.println("--------------------");
        printCode(root, "");
    }
}
// Source Code (Minimum Spanning Tree):
import java.util.*;

class Prim {
    Prim() {
        int graph[][] = new int[][] { { 0, 2, 0, 6, 0 },
                { 2, 0, 3, 8, 5 },
                { 0, 3, 0, 0, 7 },
                { 6, 8, 0, 0, 9 },
                { 0, 5, 7, 9, 0 } };
        primMST(graph);
    }

    private static final int V = 5;

    int minKey(int key[], Boolean mstSet[]) {
        int min = Integer.MAX_VALUE, min_index = -1;
        for (int v = 0; v < V; v++) {
            if (mstSet[v] == false && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        }
        return min_index;
    }

    void printMST(int parent[], int graph[][]) {
        System.out.println("Edge | Weight");
        System.out.println("----------------");
        for (int i = 1; i < V; i++)
            System.out.println(parent[i] + " - " + i + " | " + graph[i][parent[i]]);
    }

    void primMST(int graph[][]) {
        int parent[] = new int[V];
        int key[] = new int[V];
        Boolean mstSet[] = new Boolean[V];
        for (int i = 0; i < V; i++) {
            key[i] = Integer.MAX_VALUE;
            mstSet[i] = false;
        }
        key[0] = 0;
        parent[0] = -1;
        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0 && mstSet[v] == false && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }
        printMST(parent, graph);
    }
}

class Kruskal {
    Kruskal() {
        int V = 4;
        List<Edge> graphEdges = new ArrayList<Edge>(
                List.of(new Edge(0, 1, 10), new Edge(0, 2, 6),
                        new Edge(0, 3, 5), new Edge(1, 3, 15),
                        new Edge(2, 3, 4)));
        graphEdges.sort(new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                return o1.weight - o2.weight;
            }
        });
        kruskals(V, graphEdges);
    }

    static class Edge {
        int src, dest, weight;

        public Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }
    }

    static class Subset {
        int parent, rank;

        public Subset(int parent, int rank) {
            this.parent = parent;
            this.rank = rank;
        }
    }

    private static void kruskals(int V, List<Edge> edges) {
        int j = 0;
        int noOfEdges = 0;
        Subset subsets[] = new Subset[V];
        Edge results[] = new Edge[V];
        for (int i = 0; i < V; i++) {
            subsets[i] = new Subset(i, 0);
        }
        while (noOfEdges < V - 1) {
            Edge nextEdge = edges.get(j);
            int x = findRoot(subsets, nextEdge.src);
            int y = findRoot(subsets, nextEdge.dest);
            if (x != y) {
                results[noOfEdges] = nextEdge;
                union(subsets, x, y);
                noOfEdges++;
            }
            j++;
        }
        System.out.println("Following are the edges of the constructed MST:");
        System.out.println("-----------------------------------------------");
        int minCost = 0;
        for (int i = 0; i < noOfEdges; i++) {
            System.out.println(results[i].src + " - " + results[i].dest + " --> " + results[i].weight);
            minCost += results[i].weight;
        }
        System.out.println("Total cost of MST: " + minCost);
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

public class Program6b {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        boolean b = true;
        while (b) {
            System.out.println("\nPrim(1) Kruskal(2) Exit(0)");
            System.out.print("Enter your choice: ");
            int choice = s.nextInt();
            if (choice == 1) {
                Prim t = new Prim();
            } else if (choice == 2) {
                Kruskal k = new Kruskal();
            } else if (choice == 0) {
                System.out.println("See you later!");
                b = false;
            } else {
                System.out.println("Invalid Input");
                b = false;
            }
        }
    }
}