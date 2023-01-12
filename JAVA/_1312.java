import java.io.*;
import java.util.StringTokenizer;

public class _1312 {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        String[] input = bf.readLine().split(" ");
        int A = Integer.parseInt(input[0]);
        int B = Integer.parseInt(input[1]);
        int N = Integer.parseInt(input[2]);
        int ret = 0;

        for(int i= A<B?1:0; i<=N; i++){
            if(A<B)
                A*=10;
            ret = (A/B) % 10;
            A -= (A/B) * B;
        }

        System.out.println(ret);

        bf.close();
    }
}