// package tw6;

abstract class Car {
    String carName;
    String chassisNum;
    String modelName;

    Car(String carName, String chassisNum, String modelName) {
        this.carName = carName;
        this.chassisNum = chassisNum;
        this.modelName = modelName;
    }

    abstract void startCar();

    abstract void operateSteering();

    void display() {
        System.out.println("Car Name: " + carName);
        System.out.println("Chassis Num: " + chassisNum);
        System.out.println("Model Name: " + modelName);
    }
}

class Toyota extends Car {

    Toyota(String carName, String chassisNum, String modelName) {
        super(carName, chassisNum, modelName);
    }

    @Override
    void startCar() {
        System.out.println("Starting a Toyota car....");
    }

    @Override
    void operateSteering() {
        System.out.println("Toyota car is manually steered....");
    }

}

class Mahindra extends Car {

    Mahindra(String carName, String chassisNum, String modelName) {
        super(carName, chassisNum, modelName);
    }

    @Override
    void startCar() {
        System.out.println("Starting a Mahindra car....");
    }

    @Override
    void operateSteering() {
        System.out.println("Mahindra car is manually steered....");
    }
}

class Driver {
    String name;
    int age;
    String gender;

    Driver(String name, int age, String gender) {
        this.name = name;
        this.age = age;
        this.gender = gender;
    }

    void driveCar(Car currentCar) {
        System.out.println("Driver: " + this.name);
        System.out.println("Age: " + this.age);
        System.out.println("Gender: " + this.gender);
        currentCar.display();
        currentCar.startCar();
        currentCar.operateSteering();
    }
}

public class TW6 {
    public static void main(String[] args) {
        Toyota t =  new Toyota("Fortuner", "12WER", "Legender");
        Mahindra m =  new Mahindra("Mahindra", "21YIB", "S11");

        Driver siddu = new Driver("Siddu", 20, "Male");
        Driver om = new Driver("Om", 20, "Male");

        siddu.driveCar(t);
        System.out.println();
        om.driveCar(m);
    }
}
