import java.util.Scanner;

class NSMA {
    static void search(String txt, String pat) {
        int l1 = txt.length();
        int l2 = pat.length();
        int i = 0, j = l2 - 1;
        for (i = 0, j = l2 - 1; j < l1;) {
            if (pat.equals(txt.substring(i, j + 1))) {
                System.out.println("Pattern found at index " + i);
            }
            i++;
            j++;
        }
    }
}

class RKA {
    public final static int d = 256;

    static void search(String pat, String txt, int q) {
        int M = pat.length();
        int N = txt.length();
        int i, j;
        int p = 0;
        int t = 0;
        int h = 1;
        for (i = 0; i < M - 1; i++)
            h = (h * d) % q;
        for (i = 0; i < M; i++) {
            p = (d * p + pat.charAt(i)) % q;
            t = (d * t + txt.charAt(i)) % q;
        }
        for (i = 0; i <= N - M; i++) {
            if (p == t) {
                for (j = 0; j < M; j++) {
                    if (txt.charAt(i + j) != pat.charAt(j))
                        break;
                }
                if (j == M)
                    System.out.println("Pattern found at index " + i);
            }
            if (i < N - M) {
                t = (d * (t - txt.charAt(i) * h) + txt.charAt(i + M)) % q;
                if (t < 0)
                    t = (t + q);
            }
        }
    }
}

class KMPA {
    static void KMPSearch(String pat, String txt) {
        int M = pat.length();
        int N = txt.length();
        int lps[] = new int[M];
        int j = 0;
        computeLPSArray(pat, M, lps);
        int i = 0;
        while ((N - i) >= (M - j)) {
            if (pat.charAt(j) == txt.charAt(i)) {
                j++;
                i++;
            }
            if (j == M) {
                System.out.println("Pattern found at index " + (i - j));
                j = lps[j - 1];
            } else if (i < N && pat.charAt(j) != txt.charAt(i)) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
    }

    static void computeLPSArray(String pat, int M, int lps[]) {
        int len = 0;
        int i = 1;
        lps[0] = 0;
        while (i < M) {
            if (pat.charAt(i) == pat.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = len;
                    i++;
                }
            }
        }
    }
}

public class Program10 {
public static void main(String[] args) {
Scanner s = new Scanner(System.in);
boolean b=true;
while (b) {
System.out.print("\nEnter the text: ");
String txt=s.next();
System.out.print("Enter the pattern to match: ");
String pat=s.next();
System.out.println("Naive String Matching(1), Rabin Karp(2), Knuth Morris Pratt(3),
Exit(0)");
System.out.print("Enter your choice: ");
int choice=s.nextInt();
if (choice==1) {
NSMA.search(txt,pat);
}
else if (choice==2) {
RKA.search(pat,txt,101);
}
else if (choice==3) {
KMPA.KMPSearch(pat,txt);
}
else if (choice==0) {
System.out.println("Have a good day!");
b=false;
}
else {
System.out.println("Invalid Input");
b=false;
}
}
}
}