import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class _17219 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int N, M;
    public static Map<String, String> map = new HashMap<>();

    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();

        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        for(int i=0; i<N; i++){
            input = br.readLine().split(" ");

            map.put(input[0], input[1]);
        }

        for(int i=0; i<M; i++){
            sb.append(map.get(br.readLine())).append("\n");
        }

        System.out.println(sb.toString());

    }
}
