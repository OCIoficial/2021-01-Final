import java.io.*;

class cripto {
  public static void main(String[] args) throws Exception {
    double freq[] = { 0.1224, 0.0147, 0.0361, 0.0532, 0.1397, 0.0046, 0.0105, 0.0122, 0.0547, 0.0065, 0.0, 0.0543,
        0.0272, 0.0687, 0.0991, 0.0216, 0.0199, 0.0615, 0.0767, 0.0376, 0.0486, 0.0109, 0.00001, 0.0002, 0.0153,
        0.0040 };

    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(in.readLine());

    int total = 0;
    int counts[] = new int[26];
    for (int i = 0; i < N; ++i) {
      int c = in.read();
      if ('A' <= c && c <= 'Z') {
        counts[c - 'A'] += 1;
        total += 1;
      }
    }

    int argmin = 0;
    double min = Double.MAX_VALUE;
    for (int k = 0; k < 26; ++k) {
      double err = 0;
      for (int i = 0; i < 26; ++i) {
        err += Math.abs(1.0 * counts[i] / total - freq[(i - k + 26) % 26]);
      }
      if (err < min) {
        min = err;
        argmin = k;
      }
    }

    System.out.println(argmin);
  }
}
