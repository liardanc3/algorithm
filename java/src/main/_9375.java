import java.io.*;
import java.util.*;

public class _9375 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int T, n, multiply = 1, cnt;
    public static Map<String, Integer> map = new HashMap<>();

    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();

        T = Integer.parseInt(br.readLine());
        while(T-- > 0){
            n = Integer.parseInt(br.readLine());

            for(int i=0; i<n; i++){
                String[] input = br.readLine().split(" ");

                map.compute(input[1], (key, value) -> (value == null) ? 1 : value + 1);
            }

            Set<String> keySet = map.keySet();
            for (String key : keySet) {
                multiply *= (map.get(key) + 1);
                cnt++;
            }

            sb.append(multiply-1).append("\n");

            map.clear();
            multiply = 1;
        }

        System.out.println(sb.toString());
    }
}
