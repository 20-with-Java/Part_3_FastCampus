import java.util.Scanner;

public class Main {
    static int[] nextNode;
    static int[] depth;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = sc.nextInt();
            nextNode = new int[n + 1];
            depth = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                nextNode[i] = sc.nextInt();
                depth[i] = 0;
            }
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (depth[i] == 0) {
                    depth[i] = 1;
                    cnt += dfs(i);
                }
            }
            System.out.println(n - cnt);
        }
    }

    public static int dfs(int nodeNum) {
        int next = nextNode[nodeNum];
        int cycleCnt = 0;
        // 첫 방문
        if (depth[next] == 0) {
            depth[next] = depth[nodeNum] + 1;
            cycleCnt = dfs(next);
        }
        // 재방문 (사이클)
        else {
            cycleCnt = depth[nodeNum] - depth[next] + 1;
        }
        // 다음 탐색을 위해 재귀 안에서 초기화
        depth[nodeNum] = 100001;
        // 사이클이 아니면(음수) 0을 리턴
        return cycleCnt < 0 ? 0 : cycleCnt;
    }
}