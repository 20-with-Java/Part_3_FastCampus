import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n + 1];
        int d[] = new int[n + 1];

        for(int i = 1; i <= n; i++) {
            arr[i] = sc.nextInt();
        }
        int max = 1;
        for(int i = 1; i <= n; i++) {
            d[i] = 1;
            for(int j = 1; j < i; j++) {
                if(arr[j] < arr[i]) {
                    if(d[j] + 1 < d[i]) continue;
                    d[i] = d[j] + 1;
                    max = Math.max(max, d[i]);
                }
            }
        }
        System.out.println(max);
    }
}
