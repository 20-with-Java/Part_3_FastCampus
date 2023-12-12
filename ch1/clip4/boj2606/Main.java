import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int v, e;
    static int[][] graph;
    static boolean[] visited;
    static int cnt = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        v = sc.nextInt();
        e = sc.nextInt();

        graph = new int[v + 1][v + 1];
        visited = new boolean[v + 1];

        for (int i = 0; i < e; i++) {
            int src = sc.nextInt();
            int dst = sc.nextInt();
            graph[src][dst] = 1;
            graph[dst][src] = 1;
        }

//        dfs(1);
        bfs(1);
        System.out.println(cnt - 1);
    }

    public static void dfs(int node) {
        visited[node] = true;
        cnt++;
        for (int i = 1; i <= v; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                dfs(i);
            }
        }
    }
    static Queue<Integer> q = new LinkedList<>();
    public static void bfs(int node) {
        q.add(node);
        visited[node] = true;
        while (!q.isEmpty()) {
            int now = q.poll();
            cnt++;
            for (int i = 1; i <= v; i++) {
                if (graph[now][i] == 1 && !visited[i]) {
                    q.offer(i);
                    visited[i] = true;
                }
            }
        }
    }
}
