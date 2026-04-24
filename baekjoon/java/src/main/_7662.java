import java.io.*;
import java.sql.Array;
import java.util.*;

public class _7662 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static SortedSet<Integer> set = new TreeSet<>();
    public static Map<Integer, Integer> map = new HashMap<>();
    public static int T, k, n;
    public static String cmd;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());

        while(T-- > 0){
            k = Integer.parseInt(br.readLine());

            while(k-- > 0){
                String[] input = br.readLine().split(" ");

                cmd = input[0];
                n = Integer.parseInt(input[1]);

                if (cmd.equals("I")) {
                    if(set.contains(n)){
                        map.compute(n, (k, v) -> v == null ? 1 : v + 1);
                    } else {
                        set.add(n);
                    }
                } else {
                    if(!set.isEmpty()){
                        if(n == 1){
                            Integer last = set.last();
                            if(map.containsKey(last) && map.get(last) > 0){
                                map.put(last, map.get(last) - 1);
                            } else {
                                set.remove(last);
                            }
                        } else {
                            Integer first = set.first();
                            if(map.containsKey(first) && map.get(first) > 0){
                                map.put(first, map.get(first) - 1);
                            } else {
                                set.remove(first);
                            }
                        }
                    }
                }
            }

            if(set.isEmpty()){
                sb.append("EMPTY\n");
            } else {
                sb.append(set.last() + " " + set.first() + "\n");
            }

            set.clear();
            map.clear();
        }

        System.out.println(sb);
    }
}