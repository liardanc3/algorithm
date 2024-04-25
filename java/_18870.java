import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class _18870 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N;
    public static int[] arr = new int[1000000];
    public static List<Integer> list = new ArrayList<>();
    public static Map<Integer, Integer> toIdxMap = new HashMap<>();

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        String[] input = br.readLine().split(" ");
        for(int i=0; i<N; i++){
            arr[i] = Integer.parseInt(input[i]);
            list.add(arr[i]);
        }

        list = list.stream()
                .distinct()
                .sorted()
                .collect(Collectors.toList());

        for(int i=0; i<list.size(); i++){
            toIdxMap.put(list.get(i), i);
        }

        for(int i=0; i<N; i++){
            sb.append(toIdxMap.get(arr[i])).append(' ');
        }

        System.out.println(sb);
    }
}