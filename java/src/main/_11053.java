import java.io.*;
import java.util.*;

public class _11053 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, len;
    public static int[] arr = new int[1000];
    public static List<Integer> list = new ArrayList<>(1000);

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());

        String[] input = br.readLine().split(" ");
        for (int i=0; i<N; i++) {
            arr[i] = Integer.parseInt(input[i]);
            int idx = Collections.binarySearch(list, arr[i]);

            if(idx < 0){
                idx = -idx-1;
            }

            if(list.size() - 1 < idx){
                list.add(arr[i]);
            } else {
                list.set(idx, arr[i]);
            }

            len = Math.max(len, idx);
        }

        System.out.println(len+1);
    }
}