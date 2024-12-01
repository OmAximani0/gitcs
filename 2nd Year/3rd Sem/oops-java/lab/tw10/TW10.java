import java.util.function.Predicate;

interface TaxCalculator {
	double calculateTax(double income);
}

public class TW10 {
	public static void main(String[] args) {
		TaxCalculator taxCal = (double income) -> {
			if (income <= 50000) {
				return income * 0.1;
			} 
			else if (income > 50000 && income <= 100000) {
				return income * 0.2;    }
			else{
				return income * 0.3;
			}
		};

		//  The Predicate interface represents a single argument function that returns a boolean value.
		Predicate<Double> isTaxLessThan1000 = (tax) -> tax < 1000;

		double[] incomes = {1000, 60000, 80000, 100000, 150000};

		for (double x : incomes) {
			double tax = taxCal.calculateTax(x);
			System.out.println("Income: " + x + ", Tax: " + tax + ", Is Tax Less than 1000: " +   isTaxLessThan1000.test(tax));
		}
	} 
}
