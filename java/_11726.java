import java.io.*;
import java.util.*;

class Matrix {
    int a,b,c,d;

    public Matrix(int a, int b, int c, int d) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
    }

    public Matrix multiply(Matrix m){
        int aa,bb,cc,dd;

        aa = a*m.a + b*m.c;
        bb = a*m.b + b*m.d;
        cc = c*m.a + d*m.c;
        dd = c*m.b + d*m.d;

        return new Matrix(aa%10007,bb%10007,cc%10007,dd%10007);
    }
}

public class _11726 {

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static int n;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        Matrix mat = fun(new Matrix(1, 1, 1, 0), n);
        System.out.println(mat.b%10007);
    }

    private static Matrix fun(Matrix m, int n){
        if(n == 0){
            return new Matrix(1,0,0,1);
        }
        if(n == 1){
            return new Matrix(1,1,1,0);
        }

        Matrix half = fun(m, n/2);

        if(n % 2 == 0){
            return half.multiply(half);
        } else{
            return half.multiply(half).multiply(new Matrix(1,1,1,0));
        }
    }
}