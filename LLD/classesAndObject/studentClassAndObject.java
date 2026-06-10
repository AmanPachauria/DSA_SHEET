
class Student{
      // Instance variables to store the name and age of the student
      String name; 
      int age;
      
      
      void display(){
          // Method to display the name and age of the student
          System.out.println("Name :-" + name); 
          System.out.println("Age  :-" + age);
      }
      
      void action(){
          System.out.println(name + "  studing");
      }
}

public class Main{
    public static void main(String[] args){
        
        // Creating an object of the Student class and assigning values to the instance variables
        Student s1 = new Student(); 
        s1.name = "Aman";
        s1.age = 24;
        
        Student s2 = new Student();
        s2.name = "Anushka";
        s2.age = 20;
        
        Student s3 = new Student();
        s3.name = "Ajay";
        s3.age = 24;
        
        // Calling the display and action methods for each student object to show their details and actions
        s1.display(); 
        s1.action();
        s2.display();
        s2.action();
        s3.display();
        s3.action();
    }
}


