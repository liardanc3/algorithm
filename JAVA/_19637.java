import java.io.*;
import java.util.*;

public class _19637 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        ArrayList<String> nameList = new ArrayList<>();
        ArrayList<Integer> powerList = new ArrayList<>();
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);

        for(int i=0; i<N; i++){
            Object[] nameAndPower = br.readLine().split(" ");

            nameList.add(nameAndPower[0].toString());
            powerList.add(Integer.parseInt(nameAndPower[1].toString()));
        }

        while(M-- > 0){
            int power = Integer.parseInt(br.readLine().toString());

            int left = 0, right = N-1, idx = -1;
            while(left <= right){
                int mid = (left+right)/2;

                if(powerList.get(mid) >= power){
                    idx = mid;
                    right = mid - 1;
                }
                else{
                    left = mid+1;
                }
            }

            bw.write(nameList.get(idx) + '\n');
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
