import java.util.Scanner;

public class Main {
    static int[] nextNode;
    static boolean[] visited;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        for(int t = 0; t < tc; t++) {
            int n = sc.nextInt();
            nextNode = new int[n+1];
            visited = new boolean[n+1];
            for(int i = 1; i <= n; i++) {
                nextNode[i] = sc.nextInt();
            }
            int cnt = 0;
            for(int i = 1; i <= n; i++) {
                if(!visited[i]) {
                    dfs(i);
                    cnt++;
                }
            }
            System.out.println(cnt);
        }
    }
    public static void dfs(int node) {
        visited[node] = true;
        if(!visited[nextNode[node]]) {
            dfs(nextNode[node]);
        }
    }
}
