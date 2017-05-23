import java.util.Scanner;

public class HelloWorld {
    private static boolean pari(int n) {
        return (n % 2) == 0;
    }

    private static int sequenza(int n, boolean pollatz, int tCollatz) {
        int m = ((pollatz) ? 5 : 3), tot = 1;

        while(n != 1) {
            n = (pari(n)) ? n/2 : n*m+1;

            tot++;

            if(tCollatz != -1 && tot > tCollatz)
                break;
        }

        return tot;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N1 = in.nextInt(), N2 = in.nextInt(), tot = 0, collatz;

        for(int i = N1; i <= N2; i++) {
            collatz = sequenza(i, false, -1);
            if(sequenza(i, true, collatz) < collatz )
                tot++;
        }

        System.out.println(tot);
    }
}
