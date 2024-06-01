import java.io.*;
import java.util.*;

public class _2475 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static long answer = 0;

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        for(int i=0; i<5; i++){
            answer += Long.parseLong(input[i]) * Long.parseLong(input[i]);
            answer %= 10;
        }

        System.out.println(answer);
    }
}