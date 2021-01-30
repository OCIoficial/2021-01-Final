import java.util.*;

class catalonia {
  public static void main(String[] args) throws Exception {
    Scanner in = new Scanner(System.in);
    Pair a = locate(in.nextLong());
    Pair b = locate(in.nextLong());

    System.out.println(dist(a, b));
  }

  static long dist(Pair s, Pair t) {
    long dx = Math.abs(t.x - s.x);
    long dy = Math.abs(t.y - s.y);
    long dz = Math.abs((t.x - s.x) - (t.y - s.y));
    return Math.min(Math.min(dx + dy, dy + dz), dz + dx);
  }

  static Pair locate(long n) {
    long r, x, y;
    r = (long) Math.ceil(Math.sqrt(n / 3.0 + 0.25) - 0.5);

    n -= 3 * r * (r - 1);
    x = r;
    y = 0;

    int dirx[] = { 0, -1, -1, 0, 1, 1 };
    int diry[] = { 1, 0, -1, -1, 0, 1 };
    for (int i = 0; i < 6; ++i) {
      if (n > r) {
        x += r * dirx[i];
        y += r * diry[i];
        n -= r;
      } else {
        x += n * dirx[i];
        y += n * diry[i];
        break;
      }
    }
    return new Pair(x, y);
  }
}

class Pair {
  long x, y;

  public Pair(long x, long y) {
    this.x = x;
    this.y = y;
  }
}
