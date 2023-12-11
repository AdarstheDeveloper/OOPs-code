import java.util.Scanner;

class Program1 {
    static int n, comp;
    static int ar[];

    static void bubbleSort() {
        comp = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (ar[j] > ar[j + 1]) {
                    int temp = ar[j];
                    ar[j] = ar[j + 1];
                    ar[j + 1] = temp;
                    comp++;
                }
            }
        }
    }

    static void insertionSort() {
        comp = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j > 0; j--) {
                if (ar[j] < ar[j - 1]) {
                    int temp = ar[j];
                    ar[j] = ar[j - 1];
                    ar[j - 1] = temp;
                    comp++;
                } else {
                    break;
                }
            }
        }
    }

    static void selectionSort() {
        comp = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (ar[i] > ar[j]) {
                    int temp = ar[j];
                    ar[j] = ar[i];
                    ar[i] = temp;
                    comp++;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the number of elements in the array: ");
        n = s.nextInt();
        ar = new int[n];
        System.out.print("Enter the elements of the array: ");
        for (int i = 0; i < n; i++) {
            ar[i] = s.nextInt();
        }
        System.out.println("Bubble sort(1), Insertion sort(2), Selection sort(3)");
        System.out.print("Enter your choice: ");
        int choice = s.nextInt();
        switch (choice) {
            case 1:
                bubbleSort();
                break;
            case 2:
                insertionSort();
                break;
            case 3:
                selectionSort();
                break;
        }
        System.out.print("The Sorted Array is: ");
        for (int i = 0; i < n - 1; i++) {
            System.out.print(ar[i] + ",");
        }
        System.out.println(ar[n - 1]);
        System.out.println("Number of comparisons are: " + comp);
        s.close();
    }
}