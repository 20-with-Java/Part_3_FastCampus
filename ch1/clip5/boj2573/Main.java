import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static int n, m;
    static int[][] earth;
    static boolean[][] visited;
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1 ,1};
    static List<Ice> iceList = new ArrayList<>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();

        earth = new int[n][m];
        visited = new boolean[n][m];
        iceList = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                earth[i][j] = sc.nextInt();
                if(earth[i][j] > 0) {
                    iceList.add(new Ice(i, j, earth[i][j]));
                }
                // iceList에 있는 빙산들의 좌표를 방문처리
                visited[i][j] = true;
            }
        }
        for(int year = 1; !iceList.isEmpty(); year++) {
            // 빙산 녹이기
            for(int i = 0; i < iceList.size(); i++) {
                Ice ice = iceList.get(i);
                for(int j = 0; j < 4; j++) {
                    int nr = ice.row + dr[j];
                    int nc = ice.col + dc[j];
                    if(earth[nr][nc] == 0) ice.height--;
                }
            }

            // 빙산 녹은 후 높이 갱신
            for(int i = 0; i < iceList.size(); i++) {
                Ice ice = iceList.get(i);
                if(ice.height <= 0) {
                    earth[ice.row][ice.col] = 0;
                    iceList.set(i, iceList.get(iceList.size()-1));
                    iceList.remove(iceList.size()-1);
                    i--;
                }
                // DFS 탐색 대상 -> visited 초기화
                else {
                    visited[ice.row][ice.col] = false;
                }
            }

            // iceList 첫번째 빙산이 몇개와 연결되어있는지 카운트
            // 모든 빙산의 개수와, 첫번째 빙산과 연결된 빙산의 개수가 다르면 빙산이 분리되었다는 뜻
            if(iceList.size() > 0 && dfs(iceList.get(0).row, iceList.get(0).col) != iceList.size()) {
                System.out.println(year);
                System.exit(0);
            }
        }
        System.out.println(0);
    }
    static int dfs(int r, int c) {
        visited[r][c] = true;
        int cnt = 1;
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(visited[nr][nc]) continue;
            cnt += dfs(nr, nc);
        }
        return cnt;
    }
}

class Ice {
    int row;
    int col;
    int height;
    public Ice(int r, int c, int h) {
        this.row = r;
        this.col = c;
        this.height = h;
    }
}
