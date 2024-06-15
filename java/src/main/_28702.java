import java.io.*;
import java.util.*;

public class _28702 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static String a,b,c;

    public static void main(String[] args) throws IOException {
        a = br.readLine();
        b = br.readLine();
        c = br.readLine();

        try {
            int ai = Integer.parseInt(a);

            print(ai+3);
        } catch (Exception e1){
            try {
                int bi = Integer.parseInt(b);

                print(bi+2);
            } catch (Exception e2){
                int next = Integer.parseInt(c) + 1;

                print(next);
            }
        }

    }

    private static void print(int n){
        if(n%3==0 && n%5==0){
            System.out.println("FizzBuzz");
        } else if (n%3==0 && n%5 != 0) {
            System.out.println("Fizz");
        } else if(n%3!=0 && n%5==0){
            System.out.println("Buzz");
        } else {
            System.out.println(n);
        }
    }
}