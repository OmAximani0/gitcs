// package tw3;

import java.util.Scanner;

class MyBankAccount {
    int accountNumber;
    String accontType;
    String name;
    String address;
    double accountBalance;

    MyBankAccount() {
        Scanner in = new Scanner(System.in);

        System.out.println("Enter account number: ");
        this.accountNumber = in.nextInt();

        System.out.println("Enter account type: ");
        this.accontType = in.next();

        System.out.println("Enter name: ");
        this.accontType = in.nextLine();

        System.out.println("Enter address: ");
        this.accontType = in.nextLine();

        System.out.println("Enter account balance: ");
        this.accountBalance = in.nextDouble();

        in.close();
    }

    MyBankAccount(int accountNumber, String accountType, String name, double accountBalance) {
        this.accountNumber = accountNumber;
        this.accontType = accountType;
        this.name = name;
        this.accountBalance = accountBalance;
    }

    double computeInterest(int timeInYears) {
        return 0.0;
    }

    double withdrawAmount(double amount) {
        return 0.0;
    }

    double depositAmount(double amount) {
        return 0.0;
    }
}

public class TW3 {
    public static void main(String[] args) {
        MyBankAccount b = new MyBankAccount();
        System.out.println(b);
    }
}
