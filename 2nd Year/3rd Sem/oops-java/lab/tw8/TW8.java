// package tw8;

import java.util.Scanner;

class UnderAgeException extends Exception {
    public UnderAgeException(String message) {
        super(message);
    }

    @Override
    public String toString() {
        return "You are too young!";
    }
}

class InvalidLearnerLicenseException extends Exception {
    public InvalidLearnerLicenseException(String message) {
        super(message);
    }

    @Override
    public String toString() {
        return "Invalid LLR!";
    }
}

class AccidentCasesException extends Exception {
    public AccidentCasesException(String message) {
        super(message);
    }

    @Override
    public String toString() {
        return "You have previous accident records! So not eligible for license.";
    }
}

class License {
    String name;
    int age;
    String gender;
    char validLearnerLicense;
    int numberOfCases;

    void readData() {
        Scanner in = new Scanner(System.in);

        System.out.print("Enter your name: ");
        this.name = in.next();

        System.out.print("Enter your age: ");
        this.age = in.nextInt();

        System.out.print("Enter your gender: ");
        this.gender = in.next();

        System.out.print("Do you have a valid learner license: ");
        this.validLearnerLicense = in.next().charAt(0);

        System.out.print("Enter your number of accident cases in last year: ");
        this.numberOfCases = in.nextInt();

        in.close();
    }
}

class TW8 {
    public static void main(String[] args) {
        License l1 = new License();
        l1.readData();

        try {
            if (l1.age < 18) {
                throw new UnderAgeException(null);
            }
            if (l1.numberOfCases > 0) {
                throw new AccidentCasesException(null);
            }
            if (l1.validLearnerLicense != 'y' && l1.validLearnerLicense != 'Y') {
                throw new InvalidLearnerLicenseException(null);
            }
            System.out.println("Congratulations! You are eligible for licese.");
        } catch (UnderAgeException e) {
            System.out.println(e);
        } catch (InvalidLearnerLicenseException e) {
            System.out.println(e);
        } catch (AccidentCasesException e) {
            System.out.println(e);
        } catch (Exception e) {
            System.out.println(e);
        }

    }
}
