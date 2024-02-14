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

    // Static method to add two complex numbers
    public static Complex add(Complex complex1, Complex complex2) {
        double realSum = complex1.real + complex2.real;
        double imaginarySum = complex1.imaginary + complex2.imaginary;
        return new Complex(realSum, imaginarySum);
    }

    // Example usage:
    public static void main(String[] args) {
        Complex complex1 = new Complex(3, 5);
        Complex complex2 = new Complex(2, -1);

        complex1.display(); // Output: 3.0 + 5.0i
        complex2.display(); // Output: 2.0 + -1.0i

        Complex sum = Complex.add(complex1, complex2);
        sum.display(); // Output: 5.0 + 4.0i
    }
}
