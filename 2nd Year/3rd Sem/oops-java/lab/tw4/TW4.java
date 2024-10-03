//package tw4;

class Employee {
	String name;
	int age;
	String address;
	double salary;
	String gender;

	public Employee(String name, int age, String address, double salary, String gender) {
		this.name = name;
		this.age = age;
		this.address = address;
		this.salary = salary;
		this.gender = gender;
	}

	void show() {
		System.out.prinln("Employee Name: ", this.name);
		System.out.prinln("Employee Age: ", this.age);
		System.out.prinln("Employee Address: ", this.address);
		System.out.prinln("Employee Salary: ", this.salary);
		System.out.prinln("Employee Gender: ", this.gender);
	}
}

class FullTimeEmployee extends Employee {
	double DA;
	double HRA;
	double IT;
}

class PartTimeEmployee extends Employee {
}

public class TW4 {
}
