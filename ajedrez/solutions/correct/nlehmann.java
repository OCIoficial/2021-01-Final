import java.util.*;

class ajedrez {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int N = in.nextInt();
    int P = in.nextInt();

    int points[] = new int[N];
    for (int i = 0; i < P; ++i) {
      int a = in.nextInt();
      int b = in.nextInt();
      int c = in.nextInt();
      if (c == -1) {
        points[a] += 1;
        points[b] += 1;
      } else {
        points[c] += 2;
      }
    }
    int max = 0;
    for (int i = 0; i < N; ++i) {
      max = Math.max(max, points[i]);
    }

    for (int i = 0; i < N; ++i) {
      if (points[i] == max) {
        System.out.println(i);
      }
    }
  }
}
