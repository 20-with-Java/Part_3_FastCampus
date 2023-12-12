import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int bTime = sc.nextInt();
        int rTime = sc.nextInt();
        int n = sc.nextInt();
        Deque<Integer> blueQueue = new LinkedList<>();
        Deque<Integer> redQueue = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            int time = sc.nextInt();
            char color = sc.next().charAt(0);
            int cnt = sc.nextInt();

            switch (color) {
                case 'B' -> {
                    if (!blueQueue.isEmpty() && blueQueue.getLast() + bTime > time) {
                        time = blueQueue.getLast() + bTime;
                    }
                    for (int j = 0; j < cnt; j++) {
                        blueQueue.offer(time);
                        time += bTime;
                    }
                }
                case 'R' -> {
                    if (!redQueue.isEmpty() && redQueue.getLast() + rTime > time) {
                        time = redQueue.getLast() + rTime;
                    }
                    for (int j = 0; j < cnt; j++) {
                        redQueue.offer(time);
                        time += rTime;
                    }
                }
            }
        }
        List<Integer> blueOrder = new LinkedList<>();
        List<Integer> redOrder = new LinkedList<>();
        int orderNumber = 0;
        while (!blueQueue.isEmpty() && !redQueue.isEmpty()) {
            if(blueQueue.peek() <= redQueue.peek()) {
                blueOrder.add(++orderNumber);
                blueQueue.poll();
            }
            else {
                redOrder.add(++orderNumber);
                redQueue.poll();
            }
        }

        while(!blueQueue.isEmpty()) {
            blueOrder.add(++orderNumber);
            blueQueue.poll();
        }

        while(!redQueue.isEmpty()) {
            redOrder.add(++orderNumber);
            redQueue.poll();
        }


        System.out.println(blueOrder.size());
        for (Integer integer : blueOrder) {
            System.out.print(integer + " ");
        }
        System.out.println();
        System.out.println(redOrder.size());
        for (Integer integer : redOrder) {
            System.out.print(integer + " ");
        }
    }
}
