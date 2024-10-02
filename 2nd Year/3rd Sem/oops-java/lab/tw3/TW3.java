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

        System.out.print("Enter account number: ");
        this.accountNumber = in.nextInt();

        System.out.print("Enter account type (SB/FD/RD): ");
        this.accontType = in.next();

        System.out.print("Enter name: ");
        this.name = in.next();

        System.out.print("Enter address: ");
        this.address = in.next();

        System.out.print("Enter account balance: ");
        this.accountBalance = in.nextDouble();

        in.close();
    }

    MyBankAccount(int accountNumber, String accountType, String name, double accountBalance) {
        this.accountNumber = accountNumber;
        this.accontType = accountType;
        this.name = name;
        this.accountBalance = accountBalance;
    }

    double computeInterest(double timeInYears) {
        double interestRate = 0;

        if (this.accontType.equals("SB")) {
            interestRate = 0.05;
        } else if (this.accontType.equals("FD")) {
            interestRate = 0.0765;
        } else if (this.accontType.equals("RD")) {
            interestRate = 0.065;
        } else {
            System.out.println("Invalid account type");
            System.exit(0);
        }

        double interestAmount = this.accountBalance * interestRate * timeInYears;
        System.out.println("Interest computed is : " + interestAmount);
        this.accountBalance += interestAmount;
        System.out.println("Balance after depositing amount: " + this.accountBalance);

        return interestAmount;
    }

    double withdrawAmount(double amount) {
        if (this.accountBalance < 1000) {
            System.out.println("Account balance is insufficient");
            return -1;
        }
        this.accountBalance -= amount;
        System.out.println("Balance after withdrawed amount: " + this.accountBalance);
        return this.accountBalance;
    }

    double depositAmount(double amount) {
        this.accountBalance += amount;
        System.out.println("Balance after depositing amount: " + this.accountBalance);
        return this.accountBalance;
    }

    void display() {
        System.out.println();
        System.out.println("Account Number: " + this.accountNumber);
        System.out.println("Account Type: " + this.accontType);
        System.out.println("Name: " + this.name);
        System.out.println("Address: " + this.address);
        System.out.println("Account Balance: " + this.accountBalance);
        System.out.println();
    }
}

public class TW3 {
    public static void main(String[] args) {

        System.out.println("------ For default constructor -------");
        MyBankAccount a1 = new MyBankAccount();
        a1.display();
        a1.computeInterest(3);
        a1.withdrawAmount(300);

        System.out.println("\n------ For parameterised constructor -------");
        MyBankAccount a2 = new MyBankAccount(1234, "FD", "Aditya", 4000);
        MyBankAccount a3 = new MyBankAccount(12345, "RD", "Xavier", 4000);

        a2.depositAmount(2000);
        a2.computeInterest(3);
        a2.withdrawAmount(1000);
        a2.display();

        a3.computeInterest(3);
        a3.depositAmount(4000);
        a3.display();
    }
}
