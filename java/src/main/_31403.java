import java.io.*;
import java.util.*;

public class _31403 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static String a, b, c;

    public static void main(String[] args) throws IOException {
        a = br.readLine();
        b = br.readLine();
        c = br.readLine();

        System.out.println(Integer.parseInt(a) + Integer.parseInt(b) - Integer.parseInt(c));
        System.out.println(Integer.parseInt(a+b) - Integer.parseInt(c));
    }
}