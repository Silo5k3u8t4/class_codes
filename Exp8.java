import java.util.Scanner;

class Student {
    int regno,mark1,mark2,mark3,total;

    // Parameterized constructor
    Student(int r, int m1, int m2, int m3) {
        this.regno = regno;
        this.mark1 = mark1;
        this.mark2 = mark2;
        this.mark3 = mark3;
        this.total = mark1 + mark2 + mark3;
    }

    // Method to display the result
    void display() {
        System.out.println("Reg No: " + regno);
        System.out.println("Mark 1: " + mark1);
        System.out.println("Mark 2: " + mark2);
        System.out.println("Mark 3: " + mark3);
        System.out.println("Total: " + total);
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of students (N): ");
        int N = scanner.nextInt();

        // Create an array of N students
        Student[] students = new Student[N];

        // Input data for each student
        for (int i = 0; i < N; i++) {
            System.out.println("Enter details for Student " + (i + 1) + ":");
            System.out.print("Registration Number: ");
            int r = scanner.nextInt();
            System.out.print("Mark 1: ");
            int m1 = scanner.nextInt();
            System.out.print("Mark 2: ");
            int m2 = scanner.nextInt();
            System.out.print("Mark 3: ");
            int m3 = scanner.nextInt();

            // Create a Student object and store it in the array
            students[i] = new Student(r, m1, m2, m3);
        }

        // Display results for each student
        for (Student s1 : students) {
            s1.display();
        }
    }
}
