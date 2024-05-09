import java.io.*;
import java.util.*;

public class _20529 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int T, N;
    public static int[] count = new int[16];
    public static int[][][] dist = new int[16][16][16];

    public static void main(String[] args) throws IOException {
        dfs("","","",1);

        T = Integer.parseInt(br.readLine());

        while(T-- > 0){
            for(int i=0; i<16; i++){
                count[i] = 0;
            }

            N = Integer.parseInt(br.readLine());
            String[] input = br.readLine().split(" ");

            if(N >= 33){
                sb.append(0).append("\n");
            } else {

                for(int i=0; i<N; i++){
                    String mbti = input[i];

                    int idx = strToIdx(mbti);
                    count[idx]++;
                }

                int answer = Integer.MAX_VALUE;
                for(int i=0; i<16; i++){
                    if(count[i] > 0){
                        count[i]--;
                        for(int j=i; j<16; j++){
                            if(count[j] > 0){
                                count[j]--;
                                for(int k=j; k<16; k++){
                                    if(count[k] > 0){
                                        count[k]--;
                                        answer = Math.min(answer, dist[i][j][k]);
                                        count[k]++;
                                    }
                                }
                                count[j]++;
                            }
                        }
                        count[i]++;
                    }
                }
                sb.append(answer).append("\n");

            }

        }

        System.out.println(sb);


    }

    private static void dfs(String s1, String s2, String s3, int now){
        if(now == 4){
            int s1Idx = strToIdx(s1);
            int s2Idx = strToIdx(s2);
            int s3Idx = strToIdx(s3);

            dist[s1Idx][s2Idx][s3Idx] = getDist(s1, s2, s3);
        } else {
            char a,b,c,d;

            for(int i=0; i<2; i++){
                a = i==0 ? 'I' : 'E';
                for(int j=0; j<2; j++){
                    b = j==0 ? 'S' : 'N';
                    for(int s=0; s<2; s++){
                        c = s==0 ? 'T' : 'F';
                        for(int t=0; t<2; t++){
                            d = t==0 ? 'P' : 'J';

                            String tmp = ""+a+b+c+d;

                            if(now == 1){
                                dfs(tmp, s2, s3, 2);
                            }
                            if(now == 2){
                                dfs(s1, tmp, s3, 3);
                            }
                            if(now == 3){
                                dfs(s1, s2, tmp, 4);
                            }
                        }
                    }
                }
            }
        }
    }

    private static int strToIdx(String mbti){
        int now = 0;

        if(mbti.charAt(0) == 'I')
            now += 8;
        if(mbti.charAt(1) == 'N')
            now += 4;
        if(mbti.charAt(2) == 'T')
            now += 2;
        if(mbti.charAt(3) == 'P')
            now += 1;

        return now;
    }

    private static int getDist(String a, String b, String c){
        int dist = 0;
        
        for(int i=0; i<4; i++){
            if(a.charAt(i) != b.charAt(i))
                dist++;
            if(a.charAt(i) != c.charAt(i))
                dist++;
            if(b.charAt(i) != c.charAt(i))
                dist++;    
        }

        return dist;
    }
}