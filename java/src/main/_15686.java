import java.io.*;
import java.util.*;

public class _15686 {

    public static class Pair {
        int y;
        int x;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M, answer;
    public static int[][] arr = new int[51][51];
    public static int[][] visited = new int[51][51];
    public static List<List<Integer>> bhcList = new ArrayList<>();
    public static int[] bhc = new int[13];
    public static int[] dy = new int[]{-1, 0, 0, 1};
    public static int[] dx = new int[]{0, -1, 1, 0};
    public static List<Pair> list = new ArrayList<>();
    public static Queue<Pair> q = new ArrayDeque<>();
    public static PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> a > b ? 1 : -1);

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        for(int i=1; i<=N; i++){
            input = br.readLine().split(" ");

            for(int j=1; j<=N; j++){
                arr[i][j] = Integer.parseInt(input[j-1]);
                if(arr[i][j] == 2){
                    list.add(new Pair(i, j));
                }
            }
        }

        makeBhc(0, 0);
        for(int m=0; m<bhcList.size(); m++) {
            bfs(m);

            for(int i=1; i<=N; i++){
                Arrays.fill(visited[i], 0);
            }
            q.clear();
        }

        System.out.println(pq.poll());
    }

    private static void bfs(int c){
        List<Integer> cl = bhcList.get(c);
        for (Integer i : cl) {
            q.add(new Pair(list.get(i).y, list.get(i).x));
            visited[list.get(i).y][list.get(i).x] = 1;
        }

        int totalDist = 0;
        int dist = 0;

        while(!q.isEmpty()){
            int size = q.size();

            while(size-- > 0){
                Pair p = q.poll();

                if(arr[p.y][p.x] == 1){
                    totalDist += dist;
                }

                for(int i=0; i<4; i++){
                    int ddy = p.y + dy[i];
                    int ddx = p.x + dx[i];

                    if(1 <= ddy && ddy <= N && 1 <= ddx && ddx <= N && visited[ddy][ddx] == 0){
                        visited[ddy][ddx] = 1;
                        q.add(new Pair(ddy, ddx));
                    }
                }
            }

            dist++;
        }

        pq.add(totalDist);
    }

    private static void makeBhc(int now, int len){
        if(len == M){
            List<Integer> list = new ArrayList<>();
            for(int i=0; i<M; i++){
                list.add(bhc[i]);
            }
            bhcList.add(list);
            return;
        }

        for(int i=now; i<list.size(); i++){
            bhc[len] = i;
            makeBhc(i+1, len+1);
        }
    }
}
