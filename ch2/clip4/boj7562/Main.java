import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Main {
    static int n;
    static int[][] board;
    static int[][] visited;
    static int[] dr = {-2, -1, 1, 2, 2, 1, -1, -2};
    static int[] dc = {1, 2, 2, 1, -1, -2, -2, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int tc = sc.nextInt();
        for (int t = 0; t < tc; t++) {
            n = sc.nextInt();
            board = new int[n][n];
            visited = new int[n][n];
            Point start = new Point(sc.nextInt(), sc.nextInt());
            Point end = new Point(sc.nextInt(), sc.nextInt());
            Queue<Point> q = new LinkedList<>();
            q.add(start);
            visited[start.r][start.c] = 1;
            while (!q.isEmpty()) {
                Point now = q.poll();
                if (now.r == end.r && now.c == end.c) {
                    System.out.println(visited[end.r][end.c] - 1);
                    break;
                }
                for (int i = 0; i < 8; i++) {
                    int nr = now.r + dr[i];
                    int nc = now.c + dc[i];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                    if (visited[nr][nc] == 0) {
                        visited[nr][nc] = visited[now.r][now.c] + 1;
                        q.add(new Point(nr, nc));
                    }
                }
            }
        }
    }
}

class Point {
    int r, c;

    public Point(int r, int c) {
        this.r = r;
        this.c = c;
    }

}