import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        for (int t = 0; t < tc; t++) {
            int in = sc.nextInt();
            int out = sc.nextInt();
            boolean[] check = new boolean[10000];
            char[] cmd = {'D', 'S', 'L', 'R'};

            Queue<Register> q = new LinkedList<>();
            q.add(new Register(in, new StringBuilder()));
            check[in] = true;
                while (!q.isEmpty()) {
                    Register now = q.poll();
                    if (now.num == out) {
                        System.out.println(now.cmd);
                        break;
                    }
                    int[] next = {now.calcD(), now.calcS(), now.calcL(), now.calcR()};
                    for (int i = 0; i < 4; i++) {
                        if (!check[next[i]]) {
                            check[next[i]] = true;
                            q.add(new Register(next[i], new StringBuilder(now.cmd).append(cmd[i])));
                        }
                    }
                }

        }
    }
}

class Register {
    int num;
    StringBuilder cmd;
    Register(int num, StringBuilder cmd) {
        this.num = num;
        this.cmd = cmd;
    }
    public int calcD() {
        return (num * 2) % 10000;
    }
    public int calcS() {
        return (num - 1) < 0 ? 9999 : num - 1;
    }
    public int calcL() {
        return (num % 1000) * 10 + num / 1000;
    }
    public int calcR() {
        return (num % 10) * 1000 + num / 10;
    }
}
