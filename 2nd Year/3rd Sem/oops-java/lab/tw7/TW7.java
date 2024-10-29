// package tw7;

interface IPrime {
    boolean isPrime(int n);
}

class PrimeTester implements IPrime {
    @Override
    public boolean isPrime(int n) {
        for (int i = 2; i < n - 1; i++)
            if (n % i == 0)
                return false;
        return true;
    }
}

class ImprPrimeTester implements IPrime {
    @Override
    public boolean isPrime(int n) {
        for (int i = 2; i < n / 2; i++)
            if (n % i == 0)
                return false;
        return true;
    }
}

class FasterPrimeTester implements IPrime {
    @Override
    public boolean isPrime(int n) {
        for (int i = 2; i < Math.sqrt(n); i++)
            if (n % i == 0)
                return false;
        return true;
    }
}

class FastestPrimeTester implements IPrime {
    @Override
    public boolean isPrime(int n) {
        int a = 2;
        if (Math.pow(a, n-1) % n == 1)
            return true;
        return false;
    }
}

public class TW7 {
    public static void main(String[] args) {
        PrimeTester pt = new PrimeTester();
        System.out.println(pt.isPrime(4));
        System.out.println(pt.isPrime(7));

        ImprPrimeTester ipt = new ImprPrimeTester();
        System.out.println(ipt.isPrime(12));
        System.out.println(ipt.isPrime(13));

        FasterPrimeTester fpt = new FasterPrimeTester();
        System.out.println(fpt.isPrime(15));
        System.out.println(fpt.isPrime(13));

        FastestPrimeTester fspt = new FastestPrimeTester();
        System.out.println(fspt.isPrime(24));
        System.out.println(fspt.isPrime(13));
    }
}
