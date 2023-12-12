import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Main {
    static int n, m;
    static char[][] maze;
    static int[][][] distance;
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};
    static final int DOOR = 1;
    static final int KEY = 2;
    static final int EXIT = 3;
    static final int WALL = 4;
    static final int NONE = 5;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        maze = new char[n][m];
        distance = new int[n][m][1 << 6];
        Queue<Point> q = new LinkedList<>();
        for (int r = 0; r < n; r++) {
            String line = sc.next();
            for (int c = 0; c < m; c++) {
                char temp = line.charAt(c);
                maze[r][c] = temp;
                if (temp == '0') {
                    q.add(new Point(r, c, 0));
                    distance[r][c][0] = 1;
                }

            }
        }
        while (!q.isEmpty()) {
            Point now = q.poll();
            for (int i = 0; i < 4; i++) {
                int nr = now.r + dr[i];
                int nc = now.c + dc[i];
                if (isOutOfRange(nr, nc)) continue;
                int next = maze[nr][nc];
                switch (getType(next)) {
                    case WALL -> {
                        continue;
                    }
                    case NONE -> {
                        if (distance[nr][nc][now.key] == 0) {
                            distance[nr][nc][now.key] = distance[now.r][now.c][now.key] + 1;
                            q.add(new Point(nr, nc, now.key));
                        }
                    }
                    case EXIT -> {
                        System.out.println(distance[now.r][now.c][now.key]);
                        return;
                    }
                    case KEY -> {
                        int nextKey = now.key | (1 << (next - 'a'));
                        if (distance[nr][nc][nextKey] == 0) {
                            distance[nr][nc][nextKey] =
                                    distance[now.r][now.c][now.key] + 1;
                            q.add(new Point(nr, nc, nextKey));
                        }
                    }
                    case DOOR -> {
                        if ((now.key & (1 << (next - 'A'))) == 0) continue;
                        if (distance[nr][nc][now.key] == 0) {
                            distance[nr][nc][now.key] =
                                    distance[now.r][now.c][now.key] + 1;
                            q.add(new Point(nr, nc, now.key));
                        }
                    }
                }
            }
        }
        System.out.println(-1);
    }

    static boolean isOutOfRange(int r, int c) {
        return r < 0 || r >= n || c < 0 || c >= m;
    }

    static int getType(int c) {
        if (c == '#') return WALL;
        else if (c == '.' || c == '0') return NONE;
        else if (c >= 'a' && c <= 'f') return KEY;
        else if (c >= 'A' && c <= 'F') return DOOR;
        else if (c == '1') return EXIT;
        else return -1;
    }
}

class Point {
    int r, c, key;

    Point(int r, int c, int k) {
        this.r = r;
        this.c = c;
        this.key = k;
    }
}