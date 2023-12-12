import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        final int NONE = 0;
        final int LEFT = 1;
        final int RIGHT = 2;

        int n  = sc.nextInt();
        int[][] d = new int[3][n + 1];

        d[LEFT][1] = 1;
        d[RIGHT][1] = 1;
        d[NONE][1] = 1;

        for (int i = 2; i <= n; i++) {
            d[LEFT][i] = (d[RIGHT][i - 1] + d[NONE][i - 1]) % 9901;
            d[RIGHT][i] = (d[LEFT][i - 1] + d[NONE][i - 1]) % 9901;
            d[NONE][i] = (d[LEFT][i - 1] + d[RIGHT][i - 1] + d[NONE][i - 1]) % 9901;
        }
        System.out.println((d[LEFT][n] + d[RIGHT][n] + d[NONE][n]) % 9901);
    }
}
