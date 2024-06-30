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
        int aIdx;
        int bIdx;

        public Pair(int num, int aIdx, int bIdx) {
            this.num = num;
            this.aIdx = aIdx;
            this.bIdx = bIdx;
        }
    }

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M;
    public static int[] a = new int[101];
    public static int[] b = new int[101];
    public static List<Integer> list = new ArrayList<>();
    public static PriorityQueue<Pair> pq = new PriorityQueue<>(
            (p1, p2) -> {
                if(p1.num != p2.num){
                    return p1.num < p2.num ? 1 : -1;
                } else if(p1.aIdx != p2.aIdx) {
                    return p1.aIdx > p2.aIdx ? 1 : -1;
                } else {
                    return p1.bIdx > p2.bIdx ? 1 : -1;
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

        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                if(a[i] == b[j]){
                    pq.add(new Pair(a[i],i,j));
                }
            }
        }

        int aIdxNow = -1;
        int bIdxNow = -1;
        while(!pq.isEmpty()){
            Pair pair = pq.poll();

            if(aIdxNow < pair.aIdx && bIdxNow < pair.bIdx){
                list.add(pair.num);
                aIdxNow = pair.aIdx;
                bIdxNow = pair.bIdx;
            }
        }

        System.out.println(list.size());
        for(int i=0; i<list.size(); i++){
            System.out.printf(list.get(i) + " ");
        }
    }
}

