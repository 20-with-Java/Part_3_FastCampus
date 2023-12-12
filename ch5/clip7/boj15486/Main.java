import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t[] = new int[n + 2];
        int p[] = new int[n + 2];
        int d[] = new int[n + 2];
        for(int i = 1; i <= n; i++) {
            t[i] = sc.nextInt();
            p[i] = sc.nextInt();
        }
        for(int i = 1; i <= n + 1; i++) {
            d[i] = Math.max(d[i-1], d[i]);

            if(i + t[i] > n + 1) continue;
            d[i + t[i]] = Math.max(d[i + t[i]], d[i] + p[i]);
        }
        System.out.println(d[n + 1]);
    }
}
