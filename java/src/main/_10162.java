import java.io.*;
import java.util.*;

public class _10162 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();

    public static int a,b,c;
    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(br.readLine());

        // a= 300 b=60 c=10
        a = N/300;
        N%=300;
        b = N/60;
        N%=60;
        c = N/10;

        if(N%10 != 0){
            System.out.println(-1);
        } else {
            System.out.println(a + " " +b  + " " + c);
        }



    }
}