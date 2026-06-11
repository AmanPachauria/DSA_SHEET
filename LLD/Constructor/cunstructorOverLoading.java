//  You have two contructor java chosse one of 
//  them based on the parameters you are passing while creating an object of the class.
//  if you create same constructor with same parameters then it will give you compilation error
class Car{
    
    String brand;
    int speed;
    
    
    Car(String brand){
        this.brand = brand;
        this.speed = 0;
    }
    
    Car(String brand, int speed){
        this.brand = brand;
        this.speed = speed;
    }
    
    void displaySpeed(){
        System.out.println("Current speed of " + brand + " " + speed + " KM/H");
    }
    
    void accelerate(){
        speed += 10;
    }
    
    void brake(){
        if( speed >= 5) speed -= 5;
    }
}

public class Main{
    public static void main(String[] args){
        
        Car car1 = new Car("Mercedes");
        Car car2 = new Car("porshe", 400);
        
        car1.accelerate();
        car1.accelerate();
        
        car1.brake();
        
        car1.displaySpeed();
        car2.displaySpeed();
        
    }
}