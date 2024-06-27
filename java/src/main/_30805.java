package src.main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class _30805 {

    public static class Pair {
        int num;
        int idx;

        public Pair(int num, int idx) {
            this.num = num;
            this.idx = idx;
        }
    }

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M, top, topIdx;
    public static int[] a = new int[101];
    public static int[] b = new int[101];
    public static int[] pick = new int[101];
    public static int[][] arr = new int[101][101];
    public static List<Integer> answer = new ArrayList<>();
    public static PriorityQueue<Pair> pq = new PriorityQueue<>(
            (p1, p2) -> {
                if(p1.num != p2.num) {
                    return p1.num < p2.num ? 1 : -1;
                } else {
                    return p1.idx > p2.idx ? 1 : -1;
                }
            }
    );

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        String[] input = br.readLine().split(" ");
        for (int i = 1; i <= N; i++) {
            a[i] = Integer.parseInt(input[i - 1]);
        }

        M = Integer.parseInt(br.readLine());

        input = br.readLine().split(" ");
        for (int i = 1; i <= M; i++) {
            b[i] = Integer.parseInt(input[i - 1]);
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if(a[i] == b[j]) {
                    arr[i][j] = Math.max(Math.max(arr[i-1][j-1], arr[i][j-1]), arr[i-1][j-1] + 1);
                    pick[j] = 1;
                } else {
                    arr[i][j] = Math.max(arr[i][j-1], arr[i-1][j]);
                }
            }
        }

        int now = 0;
        int nowMx = 0;
        for(int i = 1; i <= M; i++) {
            if(arr[N][i] == now && arr[N][i] != 0 && pick[i] == 1){
                nowMx = Math.max(nowMx, b[i]);
            }
            if(arr[N][i] > now){
                pq.add(new Pair(nowMx, now));
                nowMx = b[i];
                now = arr[N][i];

                if(i == M){
                    pq.add(new Pair(nowMx, now));
                }
            }
        }
        
        while(!pq.isEmpty()){
            Pair p = pq.poll();

            int num = p.num;
            int idx = p.idx;

            if(topIdx < idx){
                answer.add(num);
                topIdx = idx;
            }
        }

        sb.append(answer.size()).append("\n");
        for (Integer num : answer) {
            sb.append(num).append(" ");
        }

        System.out.println(sb);
    }
}

