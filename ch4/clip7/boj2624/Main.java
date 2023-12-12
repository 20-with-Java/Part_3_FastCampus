import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int k = sc.nextInt();
//        int dp[][] = new int[k + 1][t + 1];
//
//        dp[0][0] = 1;
//        for (int i = 1; i <= k; i++) {
//            int coinPrice = sc.nextInt();
//            int coinCount = sc.nextInt();
//            for (int value = 0; value <= t; value++) {
//                for (int cnt = 0; cnt <= coinCount; cnt++) {
//                    int nextValue = value + coinPrice * cnt;
//                    if (nextValue > t) break;
//                    dp[i][nextValue] += dp[i - 1][value];
//                }
//            }
//        }
//        System.out.println(dp[k][t]);
        int[] dp = new int[t + 1];
        dp[0] = 1;
        for (int i = 0; i < k; i++) {
            int coinPrice = sc.nextInt();
            int coinCount = sc.nextInt();
            for (int j = t; j >= 0; j--) {
                for (int cnt = 1; cnt <= coinCount; cnt++) {
                    int nextValue = j + coinPrice * cnt;
                    if (nextValue > t) break;
                    dp[nextValue] += dp[j];
                }
            }
        }
        System.out.println(dp[t]);
    }
}
