//package tw4;

class Employee {
	String name;
	int age;
	String address;
	double salary;
	String gender;

	public Employee(String name, int age, String address, String gender) {
		this.name = name;
		this.age = age;
		this.address = address;
		this.gender = gender;
	}

	void show() {
		System.out.println("Employee Name: " + this.name);
		System.out.println("Employee Age: " + this.age);
		System.out.println("Employee Address: " + this.address);
		System.out.println("Employee Salary: "+ this.salary);
		System.out.println("Employee Gender: " + this.gender);
	}
}

class FullTimeEmployee extends Employee {
	double DA;
	double HRA;
	double IT;
	double basicSalary;

	public FullTimeEmployee(String name, int age, String address, String gender, double basicSalary) {
		super(name, age, address, gender);
		this.basicSalary = basicSalary;
		this.DA = (basicSalary * 0.75);
		this.HRA = (basicSalary * 0.075);
		this.IT = (basicSalary * 0.1);
	}

	public void calculateSalary() {
		this.salary = this.basicSalary + this.DA + this.HRA - this.IT;
		System.out.println("Full Time Salary for " + this.name + " is " + this.salary);
	}
}

class PartTimeEmployee extends Employee {
	String qualification;
	int experience;
	double ratePerHour;
	double workingHours;
	
	public PartTimeEmployee(
		String name,
		int age,
		String address,
		String gender,
		String qualification,
		int experience,
		int workingHours
	) {
		super(name, age, address, gender);
		this.qualification = qualification;
		this.experience = experience;
		this.workingHours = workingHours;
	}

	public void calculateSalary() {
		switch(this.qualification) {
		case "BE":
			if(this.experience <= 5) this.ratePerHour = 300;
			else if(this.experience <= 10) this.ratePerHour = 400;
			else this.ratePerHour = 500;
			break;
		case "MTech":
			if(this.experience <= 5) this.ratePerHour = 500;
			else if(this.experience <= 10) this.ratePerHour = 700;
			else this.ratePerHour = 1000;
			break;
		case "PhD":
			if(this.experience <= 5) this.ratePerHour = 800;
			else if(this.experience <= 10) this.ratePerHour = 1200;
			else this.ratePerHour = 1500;
			break;
		}
		this.salary = this.workingHours * this.ratePerHour;
		System.out.println("Part Time Salary for " + this.name + " is " + this.salary);
	}
}

public class TW4 {
	public static void main(String[] args) {
		FullTimeEmployee f1 = new FullTimeEmployee(
			"Om", 20, "Belgaum", "Male", 5000
		);

		PartTimeEmployee p1 = new PartTimeEmployee(
			"Siddhant", 20, "Belgaum", "Male", "BE", 4, 8
		);
		PartTimeEmployee p2 = new PartTimeEmployee(
			"Xavier", 20, "Belgaum", "Male", "MTech", 4, 8
		);
		PartTimeEmployee p3 = new PartTimeEmployee(
			"Suraj", 20, "Belgaum", "Male", "PhD", 4, 8
		);

		f1.calculateSalary();
		p1.calculateSalary();
		p2.calculateSalary();
		p3.calculateSalary();
	}
}
