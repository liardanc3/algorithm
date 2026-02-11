package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class _11444 {

    public static class Matrix {
        long a1;
        long a2;
        long b1;
        long b2;

        public Matrix(long a1, long a2, long b1, long b2) {
            this.a1 = a1;
            this.a2 = a2;
            this.b1 = b1;
            this.b2 = b2;
        }
    }

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringBuilder sb = new StringBuilder();
    public static long n;
    public static long DIV = 1000000007;

    public static void main(String[] args) throws IOException {
        n = Long.parseLong(br.readLine());

        Matrix ret = power(new Matrix(1,1,1,0), n);

        System.out.println(ret.b1);
    }

    private static Matrix multiply(Matrix a, Matrix b) {
        long aa1 = ((a.a1 * b.a1)%DIV + (a.a2 * b.b1)%DIV)%DIV;
        long aa2 = ((a.a1 * b.a2)%DIV + (a.a2 * b.b2)%DIV)%DIV;
        long bb1 = ((a.b1 * b.a1)%DIV + (a.b2 * b.b1)%DIV)%DIV;
        long bb2 = ((a.b1 * b.a2)%DIV + (a.b2 * b.b2)%DIV)%DIV;

        return new Matrix(aa1, aa2, bb1, bb2);
    }

    private static Matrix power(Matrix a, long p) {
        if(p<=1){
            return new Matrix(1,1,1,0);
        }

        Matrix half = power(a, p/2);

        if(p%2==1){
            return multiply(multiply(half, half), a);
        } else {
            return multiply(half, half);
        }
    }
}

