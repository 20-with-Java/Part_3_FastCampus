import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc. nextInt();
        int[][] d = new int[n + 1][5];
        final int R = 1, G = 2, B = 3;
        for (int i = 1; i <= n; i++) {
            int r = sc.nextInt();
            int g = sc.nextInt();
            int b = sc.nextInt();
            d[i][R] = Math.min(d[i - 1][G], d[i - 1][B]) + r;
            d[i][G] = Math.min(d[i - 1][R], d[i - 1][B]) + g;
            d[i][B] = Math.min(d[i - 1][R], d[i - 1][G]) + b;
        }
        System.out.println(Math.min(d[n][R], Math.min(d[n][G], d[n][B])));
    }
}
