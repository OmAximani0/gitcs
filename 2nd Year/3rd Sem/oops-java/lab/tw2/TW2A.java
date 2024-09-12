// package tw2;

import java.util.Scanner;

public class TW2A {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter first word: ");
        String s1 = input.next().toLowerCase();

        System.out.print("Enter second word: ");
        String s2 = input.next().toLowerCase();

        if (isAnagram(s1, s2)) {
            System.out.println("Anagram");
        } else {
            System.out.println("Not Anagram");
        }
    }

    static boolean isAnagram(String s1, String s2) {
        char[] c1 = s1.toCharArray();
        char[] c2 = s2.toCharArray();
        String s3 = sort(c1);
        String s4 = sort(c2);
        return s3.equals(s4);
    }

    static String sort(char[] arr) {
        for (int i = 0; i < arr.length; ++i) {
            for (int j = 0; j < arr.length - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    char tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }

        return new String(arr);
    }
}
