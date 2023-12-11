import java.util.Scanner;

class Dijkstra {
    Dijkstra() {
        int graph[][] = new int[][] { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
        dijkstra(graph, 0);
    }

    static final int V = 9;

    int minDistance(int dist[], Boolean sptSet[]) {
        int min = Integer.MAX_VALUE, min_index = -1;
        for (int v = 0; v < V; v++)
            if (sptSet[v] == false && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        return min_index;
    }

    void printSolution(int dist[]) {
        System.out.println("Vertex | Distance from Source");
        System.out.println("-----------------------------");
        for (int i = 0; i < V; i++)
            System.out.println(i + " | " + dist[i]);
    }

    void dijkstra(int graph[][], int src) {
        int dist[] = new int[V];
        Boolean sptSet[] = new Boolean[V];
        for (int i = 0; i < V; i++) {
            dist[i] = Integer.MAX_VALUE;
            sptSet[i] = false;
        }
        dist[src] = 0;
        for (int count = 0; count < V - 1; count++) {
            int u = minDistance(dist, sptSet);
            sptSet[u] = true;
            for (int v = 0; v < V; v++)
                if (!sptSet[v] && graph[u][v] != 0
                        && dist[u] != Integer.MAX_VALUE
                        && dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
        }
        printSolution(dist);
    }
}

class Bellman {
    Bellman() {
        int V = 5;
        int E = 8;
        Bellman graph = new Bellman(V, E);
        graph.edge[0].src = 0;
        graph.edge[0].dest = 1;
        graph.edge[0].weight = -1;
        graph.edge[1].src = 0;
        graph.edge[1].dest = 2;
        graph.edge[1].weight = 4;
        graph.edge[2].src = 1;
        graph.edge[2].dest = 2;
        graph.edge[2].weight = 3;
        graph.edge[3].src = 1;
        graph.edge[3].dest = 3;
        graph.edge[3].weight = 2;
        graph.edge[4].src = 1;
        graph.edge[4].dest = 4;
        graph.edge[4].weight = 2;
        graph.edge[5].src = 3;
        graph.edge[5].dest = 2;
        graph.edge[5].weight = 5;
        graph.edge[6].src = 3;
        graph.edge[6].dest = 1;
        graph.edge[6].weight = 1;
        graph.edge[7].src = 4;
        graph.edge[7].dest = 3;
        graph.edge[7].weight = -3;
        graph.BellmanFord(graph, 0);
    }

    class Edge {
        int src, dest, weight;

        Edge() {
            src = dest = weight = 0;
        }
    };

    int V, E;
    Edge edge[];

    Bellman(int v, int e) {
        V = v;
        E = e;
        edge = new Edge[e];
        for (int i = 0; i < e; ++i)
            edge[i] = new Edge();
    }

    void BellmanFord(Bellman graph, int src) {
        int V = graph.V, E = graph.E;
        int dist[] = new int[V];
        for (int i = 0; i < V; ++i)
            dist[i] = Integer.MAX_VALUE;
        dist[src] = 0;
        for (int i = 1; i < V; ++i) {
            for (int j = 0; j < E; ++j) {
                int u = graph.edge[j].src;
                int v = graph.edge[j].dest;
                int weight = graph.edge[j].weight;
                if (dist[u] != Integer.MAX_VALUE
                        && dist[u] + weight < dist[v])
                    dist[v] = dist[u] + weight;
            }
        }
        for (int j = 0; j < E; ++j) {
            int u = graph.edge[j].src;
            int v = graph.edge[j].dest;
            int weight = graph.edge[j].weight;
            if (dist[u] != Integer.MAX_VALUE
                    && dist[u] + weight < dist[v]) {
                System.out.println("Graph contains negative weight cycle");
                return;
            }
        }
        printArr(dist, V);
    }

    void printArr(int dist[], int V) {
        System.out.println("Vertex | Distance from Source");
        System.out.println("-----------------------------");
        for (int i = 0; i < V; ++i)
            System.out.println(i + " | " + dist[i]);
    }
}

public class Program7 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        boolean c = true;
        while (c) {
            System.out.println("\nDijkstra(1) Bellman(2) Exit(0)");
            System.out.print("Enter your choice: ");
            int choice = s.nextInt();
            if (choice == 1) {
                Dijkstra d = new Dijkstra();
            } else if (choice == 2) {
                Bellman b = new Bellman();
            } else if (choice == 0) {
                System.out.println("See you later!");
                c = false;
            } else {
                System.out.println("Invalid Input");
                c = false;
            }
        }
    }
}