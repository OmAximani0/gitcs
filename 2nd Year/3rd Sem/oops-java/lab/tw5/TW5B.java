// package tw5;

class Rectangle {
    double length;
    double width;

    public Rectangle() {
        this.length = 1;
        this.width = 1;
    }

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    double computeArea() {
        return this.length * this.width;
    }

    double computePerimeter() {
        return 2 * (this.length + this.width);
    }
}

class Cuboid extends Rectangle {
    double height;

    public Cuboid() {
        super();
        this.height = 1;
    }

    public Cuboid(double length, double width, double height) {
        super(length, width);
        this.height = height;
    }

    double volume() {
        return this.length * this.width * this.height;
    }

    @Override
    double computeArea() {
        return 2 * ((this.length * this.width) + (this.width * this.height) + (this.length * this.height));
    }

    @Override
    double computePerimeter() {
        return 4 * (this.length + this.width + this.height);
    }
}

class TW5B {
    public static void main(String[] args) {
        Rectangle r1 = new Rectangle();
        System.out.println("Rectangle 1:");
        System.out.println("Area: " + r1.computeArea());
        System.out.println("Perimeter: " + r1.computePerimeter());

        Rectangle r2 = new Rectangle(30, 40);
        System.out.println("\nRectangle 2:");
        System.out.println("Area: " + r2.computeArea());
        System.out.println("Perimeter: " + r2.computePerimeter());

        Cuboid c1 = new Cuboid();
        System.out.println("\nCuboid 1:");
        System.out.println("Area: " + c1.computeArea());
        System.out.println("Perimeter: " + c1.computePerimeter());
        System.out.println("Volume: " + c1.volume());

        Cuboid c2 = new Cuboid(30, 40, 50);
        System.out.println("\nCuboid 2:");
        System.out.println("Area: " + c2.computeArea());
        System.out.println("Perimeter: " + c2.computePerimeter());
        System.out.println("Volume: " + c2.volume());
   }
}
