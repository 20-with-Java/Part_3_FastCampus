import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] wine = new int[n + 1];
        int[][] d = new int[3][n + 1];
        for (int i = 1; i <= n; i++) {
            wine[i] = sc.nextInt();
        }
        d[0][1] = 0;
        d[1][1] = wine[1];
        d[2][1] = wine[1];
        for(int i = 2; i <= n; i++) {
            d[0][i] = Math.max(d[0][i - 1], Math.max(d[1][i - 1], d[2][i - 1]));
            d[1][i] = d[0][i - 1] + wine[i];
            d[2][i] = d[1][i - 1] + wine[i];
        }
        System.out.println(Math.max(d[0][n], Math.max(d[1][n], d[2][n])));
    }
}
