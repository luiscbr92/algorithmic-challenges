import java.math.BigInteger;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner lee = new Scanner(System.in);
    while (lee.hasNext()) {
      BigInteger b = lee.nextBigInteger();

      int n = b.mod(new BigInteger("16")).intValue();

      if(n == 0 || n == 1 || n == 4 || n == 9)
        System.out.println("NO SE");
      else
        System.out.println("IMPERFECTO");

    }
  }
}
