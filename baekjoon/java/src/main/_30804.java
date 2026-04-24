import java.io.*;
import java.util.*;

public class _30804 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, answer;
    public static String[] input;

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        input = br.readLine().split(" ");

        for(int i=1; i<9; i++){
            for(int j=i+1; j<=9; j++){
                answer = Math.max(answer, fun1(i, j));
            }
        }

        System.out.println(answer);
    }

    private static int fun1(int a, int b){
        boolean isStart = false;
        int result = 0;
        int tmp = 0;
        for (int i=0; i<input.length; i++) {
            int now = Integer.parseInt(input[i]);

            if(now == a || now == b){
                tmp++;
                if(!isStart){
                    isStart = true;
                }
            } else {
                if(isStart){
                    result = Math.max(result, tmp);
                    tmp = 0;
                    isStart = false;
                }
                tmp = 0;
            }
        }

        return Math.max(result, tmp);
    }


}