import java.io.*;
import java.util.*;

public class _1541 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static String input, now="";
    public static int answer, tmp;
    public static boolean minus = false;

    public static void main(String[] args) throws IOException {
        input = br.readLine();

        for(int i=0; i<input.length(); i++){
            if(input.charAt(i) != '-' && input.charAt(i) != '+'){
                now = now + input.charAt(i);
            } else if (input.charAt(i) == '+') {
                answer = answer + (minus ? -Integer.parseInt(now) : Integer.parseInt(now));
                now = "";
            } else {
                answer = answer + (minus ? -Integer.parseInt(now) : Integer.parseInt(now));
                now = "";
                minus = true;
            }
        }

        if(!now.equals("")){
            answer = answer + (minus ? -Integer.parseInt(now) : +Integer.parseInt(now));
        }

        System.out.println(answer);

    }
}