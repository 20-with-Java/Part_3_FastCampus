
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] examStatic = new long[n + 1];
        long[] examDynamic = new long[n + 1];

        for(int i = 1; i <= n; i++) {
            examStatic[i] = sc.nextInt();
        }
        for(int i = 1; i < n; i++) {
            examDynamic[i] = sc.nextInt();
        }

        final int CASE1 = 0;
        final int CASE2 = 1;
        final int CASE3 = 2;
        final int MOD = 1000000007;
        long[][] d = new long[3][n + 1];

        d[CASE1][0] = 1;
        d[CASE2][0] = 0;
        d[CASE3][0] = 0;

        d[CASE1][1] = examStatic[1];
        d[CASE2][1] = examDynamic[1];
        d[CASE3][1] = 0;

        for(int i = 2; i <= n; i++) {
            // 난이도가 고정된 문제만 사용하는 경우
            d[CASE1][i] = ((d[CASE1][i-1] + d[CASE2][i-1] + d[CASE3][i-1]) * examStatic[i]) % MOD;
            // 난이도가 변동되는 문제를 {i}로 사용하는 경우
            d[CASE2][i] = ((d[CASE1][i-1] + d[CASE2][i-1] + d[CASE3][i-1]) * examDynamic[i]) % MOD;
            // 난이도가 변동되는 문제를 {i+1}로도 사용하는 경우
            d[CASE3][i] =
                    (d[CASE1][i-1] + d[CASE3][i-1]) * examDynamic[i-1] % MOD +
                    (examDynamic[i-1] * (examDynamic[i-1] - 1) % MOD)
                            * (d[CASE1][i-2] + d[CASE2][i-2] + d[CASE3][i-2])  % MOD;
        }
        long sum = d[CASE1][n] + d[CASE2][n] + d[CASE3][n];
        System.out.println(sum % MOD);
    }
}
