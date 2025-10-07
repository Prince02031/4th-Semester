import java.util.Scanner;

public class Main
{
     // Create a Student class
    public class Student {
    // Declaring attributes
        String name;
        int rollNo;
        String section;
        // initialize attributes in constructor
        Student(String name, int rollNo, String section){
        this.name= name;
        this.rollNo = rollNo;
        this.section = section;
    }
    public String getName() {
        return this.name;
        }
        public int getRoll() {
        return this.rollNo;
        }
        public String getSection() {
        return this.section;
        }
        // print details
        public void printDetails() {
        System.out.println("Student Details:");
        System.out.println(this.getName());
        System.out.println(this.getRoll());
        System.out.println(this.getSection());
        }
        }

    public static void main(String[] args)
    {
        int x=123;
        double y=3.14;
        boolean z= true;
        char symbol= '@';
        //String name= "Quint";

        Scanner sc= new Scanner(System.in);

        System.out.println("your name: ");
        String name=sc.nextLine();
        System.out.println("hello "+name);

        sc.close();
    }
    
}