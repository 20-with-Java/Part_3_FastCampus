import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        final int MAX_VALUE = 1000000;
        int input = 0;
        int dmx[] = new int[5];
        int dmn[] = new int[5];
        int tmx[] = new int[5];
        int tmn[] = new int[5];
        dmx[0] = dmx[4] = 0;
        dmn[0] = dmn[4] = MAX_VALUE;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 3; j++) {
                input = sc.nextInt();
                tmx[j] = Math.max(dmx[j - 1], Math.max(dmx[j], dmx[j + 1])) + input;
                tmn[j] = Math.min(dmn[j - 1], Math.min(dmn[j], dmn[j + 1])) + input;
            }
            for(int j = 1; j <= 3; j++) {
                dmx[j] = tmx[j];
                dmn[j] = tmn[j];
            }
        }
        int max = 0;
        int min = MAX_VALUE;
        for(int i = 1; i <= 3; i++) {
            max = Math.max(max, dmx[i]);
            min = Math.min(min, dmn[i]);
        }
        System.out.println(max + " " + min);
    }
}


