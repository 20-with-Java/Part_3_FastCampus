import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int n, m, v;
    static int[][] graph;
    static boolean[] visited;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        v = sc.nextInt();

        graph = new int[n+1][n+1];
        visited = new boolean[n+1];

        for(int i = 0; i < m; i++) {
            int src = sc.nextInt();
            int dst = sc.nextInt();
            graph[src][dst] = 1;
            graph[dst][src] = 1;
        }

        dfs(v);
        System.out.println();
        visited = new boolean[n+1];
        bfs(v);
    }
    public static void dfs(int node) {
        visited[node] = true;
        System.out.print(node + " ");
        for(int i = 1; i <= n; i++) {
            if(graph[node][i] == 1 && !visited[i]) {
                dfs(i);
            }
        }
    }

    Queue<Integer> q = new LinkedList<>();
    public static void bfs(int node) {
        Queue<Integer> q = new LinkedList<>();
        q.add(node);
        visited[node] = true;
        while(!q.isEmpty()) {
            int now = q.poll();
            System.out.print(now + " ");
            for(int i = 1; i <= n; i++) {
                if(graph[now][i] == 1 && !visited[i]) {
                    q.offer(i);
                    visited[i] = true;
                }
            }
        }
    }
}
