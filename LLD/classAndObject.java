class Student{
    String name;
    int age;
    
    void display(){
        System.out.println("name : " + name);
        System.out.println("age : " + age);
    }
}


public class Main {
    public static void main(String[] args){
        Student student1 = new Student();
        student1.name = "Rahul";
        student1.age = 29;
        student1.display();
    }
}
