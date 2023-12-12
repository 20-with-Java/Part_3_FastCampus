import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    static int n, m;
    static int[][] graph;
    static boolean[] visited;
    static int cnt = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();
        graph = new int[n+1][n+1];
        visited = new boolean[n+1];

        for(int i = 0; i < m; i++) {
            int src = sc.nextInt();
            int dst = sc.nextInt();
            graph[src][dst] = 1;
            graph[dst][src] = 1;
        }
//        for(int i = 1; i <= n; i++) {
//            if(!visited[i]) {
//                dfs(i);
//                cnt++;
//            }
//        }
         for(int i = 1; i <= n; i++) {
             if(!visited[i]) {
                 bfs(i);
                 cnt++;
             }
         }
        System.out.println(cnt);
    }
    public static void dfs(int node) {
        visited[node] = true;
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
            for(int i = 1; i <= n; i++) {
                if(graph[now][i] == 1 && !visited[i]) {
                    q.offer(i);
                    visited[i] = true;
                }
            }
        }
    }

    Stack<Integer> s = new Stack<>();
    public static void dfs2(int node) {
        Stack<Integer> s = new Stack<>();
        s.push(node);
        visited[node] = true;
        while(!s.isEmpty()) {
            int now = s.pop();
            for(int i = 1; i <= n; i++) {
                if(graph[now][i] == 1 && !visited[i]) {
                    s.push(i);
                    visited[i] = true;
                }
            }
        }
    }
}
