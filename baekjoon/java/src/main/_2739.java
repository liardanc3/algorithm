import java.io.*;
import java.util.*;

public class _2739 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());

        for(int i=1; i<=9; i++){
            System.out.println(n + " * " + i + " = " + n*i);
        }

    }
}
