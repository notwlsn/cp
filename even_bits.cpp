package google_kickstarter_2018;
import java.util.Scanner;

public class Even_Digits {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int t = scn.nextInt();
        int [] ns = new int [t];
        for (int i = 0;i< t; i++) {
            ns[i] = scn.nextInt();
        }
        for (int i = 0;i< t; i++) {
            System.out.println ("Case #"+(i+1)+": "+smallestValue(ns[i]));
        }

        }

    public static boolean allEven(int n) {
        String sn = Integer.toString(n);
        for (int i = 0 ; i < sn.length() ; i++) {
            int d = Integer.parseInt(Character.toString(sn.charAt(i)));

            if (d%2!= 0) return false;
        }
        return true;
    }

    public static int smallestValue(int n) {
        int add = 0;
        int sub = 0;


        boolean isOdd= n%2!=0;
        if (isOdd) n+=1;
        int nadd = n;
        int nsub = n;

        while (!allEven (nadd)&&!allEven(nsub)) {
            nsub-=2;
            nadd+=2;
            add+=2;
            sub+=2;
    }

        if (allEven (nsub)) {
            if (isOdd) sub--;
            return sub;
        }
        else {
            if (isOdd) add++;
            return add;
        }

    }
}
