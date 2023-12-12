import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // 정점의 개수와 간선의 개수 입력
        int v = sc.nextInt();
        int e = sc.nextInt();
        // 인접 리스트 예시
        List<Integer> graph[] = new List[v+1];
        for(int i = 1; i <= v; i++) {
            graph[i] = new ArrayList<>();
        }
        for(int i = 0; i < e; i++) {
            int src = sc.nextInt();
            int dst = sc.nextInt();
            graph[src].add(dst);
        }
    }
}
