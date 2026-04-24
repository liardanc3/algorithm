package main;

import java.io.*;

public class _2493 {

    static FastScanner fs = new FastScanner(System.in);
    static FastOutput out = new FastOutput();

    public static void main(String[] args) throws Exception {
        int n = fs.nextInt();
        int[] stack = new int[500001];
        int[] idx = new int[500001];
        int right = 0;

        stack[0] = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            int now = fs.nextInt();

            if (stack[right] <= now) {
                int left = 0;
                int stackIndex = 0;

                while (left <= right) {
                    int mid = (left + right) >>> 1;
                    if (stack[mid] > now) {
                        stackIndex = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                right = stackIndex;
            }

            out.writeIntSpace(idx[right]);

            stack[++right] = now;
            idx[right] = i + 1;
        }

        out.flush();
    }

    static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;

        FastScanner(InputStream is) {
            in = is;
        }

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }

        int nextInt() throws IOException {
            int c;
            do {
                c = read();
            } while (c <= 32);

            int val = 0;
            while (c > 32) {
                val = val * 10 + (c - '0');
                c = read();
            }
            return val;
        }
    }

    static class FastOutput {
        private final OutputStream out = System.out;
        private final byte[] buffer = new byte[1 << 16];
        private final byte[] numBuffer = new byte[12];
        private int ptr = 0;

        private void drain() throws IOException {
            out.write(buffer, 0, ptr);
            ptr = 0;
        }

        void writeIntSpace(int x) throws IOException {
            if (x == 0) {
                if (ptr + 2 > buffer.length) drain();
                buffer[ptr++] = '0';
                buffer[ptr++] = ' ';
                return;
            }

            int len = 0;
            while (x > 0) {
                numBuffer[len++] = (byte) ('0' + (x % 10));
                x /= 10;
            }

            if (ptr + len + 1 > buffer.length) drain();
            for (int i = len - 1; i >= 0; i--) {
                buffer[ptr++] = numBuffer[i];
            }
            buffer[ptr++] = ' ';
        }

        void flush() throws IOException {
            if (ptr > 0) out.write(buffer, 0, ptr);
            out.flush();
        }
    }
}