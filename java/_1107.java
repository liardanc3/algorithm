import java.io.*;
import java.util.*;

public class _1107 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int N, M;
    public static int[] broken = new int[10];
    public static List<Integer> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        String[] input = new String[M];
        if(M != 0){
            input = br.readLine().split(" ");
        }
        if(M == 10){
            System.out.println(Math.abs(100 - N));
            System.exit(0);
        }
        for(int i=0; i<M; i++){
            broken[Integer.parseInt(input[i])] = 1;
        }

        int tmp = 0;
        for (int i=0; i<=9; i++) {
            if (broken[i] == 0 || (tmp == 0 && i == 0)) {
                tmp += i * 100000;
                for(int j=0; j<=9; j++){
                    if(broken[j] == 0 || (tmp == 0 && j == 0)){
                        tmp += j * 10000;
                        for(int k=0; k<=9; k++){
                            if(broken[k] == 0 || (tmp == 0 && k == 0)){
                                tmp += k * 1000;
                                for(int s=0; s<=9; s++){
                                    if(broken[s] == 0 || (tmp == 0 && s == 0)){
                                        tmp += s * 100;
                                        for(int t=0; t<=9; t++){
                                            if(broken[t] == 0 || (tmp == 0 && t == 0)){
                                                tmp += t * 10;
                                                for(int r=0; r<=9; r++){
                                                    if(broken[r] == 0){
                                                        tmp += r;
                                                        list.add(tmp);
                                                        tmp -= r;
                                                    }
                                                }
                                                tmp -= t * 10;
                                            }
                                        }
                                        tmp -= s * 100;
                                    }
                                }
                                tmp -= k * 1000;
                            }
                        }
                        tmp -= j * 10000;
                    }
                }
                tmp -= i * 100000;
            }
        }
        list.sort(Integer::compareTo);

        System.out.println(Math.min(Math.abs(100-N), get()));
    }

    private static int get(){
        int idx = Collections.binarySearch(list, N);

        if(idx < 0){
            if(-idx-2 >= 0 && -idx-1 < list.size()){
                int left = list.get(-idx-2);
                int right = list.get(-idx-1);

                return Math.min(
                        String.valueOf(left).length() + Math.abs(left - N),
                        String.valueOf(right).length() + Math.abs(right - N)
                );
            } else if(-idx-2 >= 0){
                int left = list.get(-idx-2);

                return String.valueOf(left).length() + Math.abs(left - N);
            } else {
                int right = list.get(-idx-1);

                return String.valueOf(right).length() + Math.abs(right - N);
            }
        } else {
            return String.valueOf(list.get(idx)).length();
        }
    }
}