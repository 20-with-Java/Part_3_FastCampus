import java.util.Scanner;

class Main {
    static long[] memo = new long[91];

    static long fibo(int n) {
        if (n == 1 || n == 2) return 1;
        if (memo[n] != 0) return memo[n];
        memo[n] = fibo(n - 1) + fibo(n - 2);
        return memo[n];
    }

    static long[] dp = new long[91];

    static long fibo2(int n) {
        dp[1] = dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    static long[] d = new long[93];

    static long fibo3(int n) {
        d[1] = 1;
        for (int i = 1; i <= n; i++) {
            d[i + 1] += d[i];
            d[i + 2] += d[i];
        }
        return dp[n];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(fibo3(n));
    }
}