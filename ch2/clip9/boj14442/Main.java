
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Main {
    static int n, m, k;
    static int[][] board;
    static int[][][] visited;

    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        k = sc.nextInt();
        board = new int[n + 1][m + 1];
        visited = new int[n + 1][m + 1][k + 1];
        for (int i = 1; i <= n; i++) {
            String line = sc.next();
            for (int j = 1; j <= m; j++) {
                board[i][j] = line.charAt(j - 1) - '0';
            }
        }
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(1, 1 ,0));
        visited[1][1][0] = 1;
        while (!q.isEmpty()) {
            Point now = q.poll();
            if(now.r == n && now.c == m) {
                System.out.println(visited[now.r][now.c][now.isBroken]);
                return;
            }
            for(int i = 0; i < 4; i++) {
                int nr = now.r + dr[i];
                int nc = now.c + dc[i];
                if(nr <= 0 || nr > n || nc <= 0 || nc > m) continue;
                if(visited[nr][nc][now.isBroken] == 0) {
                    // 일반적인 상황의 탐색
                    if(board[nr][nc] == 0) {
                        visited[nr][nc][now.isBroken] = visited[now.r][now.c][now.isBroken] + 1;
                        q.add(new Point(nr, nc, now.isBroken));
                    }
                    // 벽을 부술수있다면 부수고 가보는 탐색
                    else if(board[nr][nc] == 1 && now.isBroken < k && visited[nr][nc][now.isBroken + 1] == 0) {
                        visited[nr][nc][now.isBroken + 1] = visited[now.r][now.c][now.isBroken] + 1;
                        q.add(new Point(nr, nc, now.isBroken + 1));
                    }
                }
            }
        }
        System.out.println(-1);
    }
}

class Point {
    int r, c;
    int isBroken;

    public Point(int r, int c, int b) {
        this.r = r;
        this.c = c;
        this.isBroken = b;
    }
}
