import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class _11047 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int N,K,A, count = 0;
    public static List<Integer> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        K = Integer.parseInt(input[1]);

        for(int i=0; i<N; i++){
            A = Integer.parseInt(br.readLine());

            list.add(A);
        }

        list.sort((a, b) -> {
            return a < b ? 1 : a > b ? -1 : 0;
        });

        for(int i=0; i<list.size(); i++){
            int now = list.get(i);

            count += (K/now);
            K -= (K/now) * now;
        }

        System.out.println(count);
    }
}
