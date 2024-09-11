// package tw1;

import java.util.Scanner;

public class TW1 {
    public static void main(String[] args) {
        int TOTAL_STUDENTS = 5;
        int TOTAL_IA = 3;

        int[][] marks = new int[TOTAL_STUDENTS][TOTAL_IA];
        int[] total = new int[TOTAL_STUDENTS];
        int[] avg = new int[TOTAL_STUDENTS];

        Scanner input = new Scanner(System.in);

        for (int i = 0; i < TOTAL_STUDENTS; ++i) {
            System.out.print("Enter marks for student " + (i + 1) + " : ");
            for (int j = 0; j < TOTAL_IA; ++j) {
                marks[i][j] = input.nextInt();
                total[i] += marks[i][j];
            }
        }
        System.out.println();

        for (int i = 0; i < TOTAL_STUDENTS; ++i)
            avg[i] = computeAVG(marks[i][0], marks[i][1], marks[i][2]);

        for (int i = 0; i < TOTAL_STUDENTS; ++i) {
            System.out.println("Total marks of student " + (i + 1) + " is " + total[i]);
            System.out.println("Average marks of student " + (i + 1) + " is " + avg[i]);
            System.out.println();
        }

    }

    public static int computeAVG(int m1, int m2, int m3) {
        int min = m1;

        if (min > m2)
            min = m2;
        if (min > m3)
            min = m3;

        int total = (m1 + m2 + m3 - min);
        int avg = (int) Math.ceil(total / 2);
        return avg;
    }
}
