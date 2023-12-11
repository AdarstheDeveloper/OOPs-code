import java.util.*;

class Program2 {
    static int n, item;
    static int ar[];

    static void linearSearch() {
        for (int i = 0; i < n; i++) {
            if (item == ar[i]) {
                System.out.println("Element " + item + " found at location " + (i + 1));
                return;
            }
        }
        System.out.println("Element " + item + " is not present in the array");
    }

    static void binarySearch() {
        int beg = 0, end = n - 1;
        int mid = (beg + end) / 2;
        while ((beg <= end) && (ar[mid] != item)) {
            if (item < ar[mid]) {
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
            mid = (beg + end) / 2;
        }
        if (item == ar[mid]) {
            System.out.println("Element " + item + " found at location " + (mid + 1));
        } else {
            System.out.println("Element " + item + " is not present in the array");
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
        System.out.print("Enter the element to search: ");
        item = s.nextInt();
        System.out.println("Linear search(1), Binary search(2)");
        System.out.print("Enter your choice: ");
        int choice = s.nextInt();
        switch (choice) {
            case 1:
                linearSearch();
                break;
            case 2:
                binarySearch();
                break;
        }
    }
}