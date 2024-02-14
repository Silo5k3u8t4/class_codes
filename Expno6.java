public class Complex {
    private double real;
    private double imaginary;

    // Constructor without parameters
    public Complex() {
        this.real = 0;
        this.imaginary = 0;
    }

    // Constructor with two parameters
    public Complex(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    // Method to display the complex number
    public void display() {
        System.out.println(real + " + " + imaginary + "i");
    }

    // Method to add a complex number
    public Complex add(Complex other) {
        return new Complex(this.real + other.real, this.imaginary + other.imaginary);
    }

    // Method to add two complex numbers and store the result in the current object
    public void add(Complex complex1, Complex complex2) {
        this.real = complex1.real + complex2.real;
        this.imaginary = complex1.imaginary + complex2.imaginary;
    }

    // Example usage:
    public static void main(String[] args) {
        Complex complex1 = new Complex(3, 5);
        Complex complex2 = new Complex(2, -1);

        complex1.display(); // Output: 3.0 + 5.0i

        Complex result1 = complex1.add(complex2);
        result1.display(); // Output: 5.0 + 4.0i

        Complex sum = new Complex();
        sum.add(complex1, complex2);
        sum.display(); // Output: 5.0 + 4.0i
    }
}
