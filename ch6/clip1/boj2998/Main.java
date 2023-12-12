import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String binary = sc.next();
        if(binary.length() % 3 == 1)
            binary = "00" + binary;
        else if(binary.length() % 3 == 2)
            binary = "0" + binary;

        change(binary);
    }
    public static int o2d(String binary) {
        final String[] octal = {
            "000", "001", "010",
            "011", "100", "101",
            "110", "111"
        };
        for (int i = 0; i < 8; i++) {
            if(binary.equals(octal[i])) return i;
        }
        return -1;
    }
    public static void change (String binary) {
        int length = binary.length();
        if(length == 0) return;

        change(binary.substring(0, length - 3));
        int d = o2d(binary.substring(length - 3));
        System.out.print(d);
    }
}
