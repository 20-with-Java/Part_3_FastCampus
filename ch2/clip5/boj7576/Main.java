import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Main {
    static int n, m;
    static int[][] board;
    static int[][] visited;
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        m = sc.nextInt();
        n = sc.nextInt();
        board = new int[n][m];
        visited = new int[n][m];

        Queue<Point> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = sc.nextInt();
                if (board[i][j] == 1) {
                    q.add(new Point(i, j));
                    visited[i][j] = 1;
                }
            }
        }

        while (!q.isEmpty()) {
            Point now = q.poll();
            for (int i = 0; i < 4; i++) {
                int nr = now.r + dr[i];
                int nc = now.c + dc[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if (visited[nr][nc] == 0 && board[nr][nc] == 0) {
                    visited[nr][nc] = visited[now.r][now.c] + 1;
                    q.add(new Point(nr, nc));
                }
            }
        }
        int max = 0;
        boolean yummy = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                max = Math.max(max, visited[i][j]);
                if (visited[i][j] == 0 && board[i][j] == 0) {
                    yummy = false;
                    break;
                }
            }
        }
        if (yummy) System.out.println(max - 1);
        else System.out.println(-1);
    }
}

class Point {
    int r, c;

    public Point(int r, int c) {
        this.r = r;
        this.c = c;
    }
}