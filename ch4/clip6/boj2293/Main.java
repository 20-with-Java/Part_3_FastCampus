import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        int[] coin = new int[n];
        int[] dp = new int[k + 1];
        for(int i = 0; i < n; i++) {
            coin[i] = sc.nextInt();
        }
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j + coin[i] <= k; j++) {
                dp[j + coin[i]] += dp[j];
            }
        }
        System.out.println(dp[k]);
    }
}
