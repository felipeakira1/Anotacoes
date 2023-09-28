package inheritance;

import java.util.ArrayList;

interface Employee {
   // Constant field
   String COMPANY_NAME = "ABC Corporation";

   // Abstract methods
   void calculateSalary();

   void displayInfo();
}

abstract class AbstractEmployee {
   protected String name;
}

class FullTimeEmployee extends AbstractEmployee implements Employee {
   private double monthlySalary;

   public FullTimeEmployee(String name, double monthlySalary) {
      this.name = name;
      this.monthlySalary = monthlySalary;
   }

   @Override
   public void calculateSalary() {
      double annualSalary = monthlySalary * 12;
      System.out.println(name + "'s annual salary: $" + annualSalary);
   }

   @Override
   public void displayInfo()
      {
      System.out.println("Full-time employee: " + name);
      }
   }

class PartTimeEmployee extends AbstractEmployee implements Employee
   {
   private static final int WORKHOURS = 8;
   private static final int WORKDAYS  = 20;
   private double           hourlyRate;

   public PartTimeEmployee(String name, double hourlyRate)
      {
      this.name = name;
      this.hourlyRate = hourlyRate;
      }

   @Override
   public void calculateSalary()
      {
      double monthlySalary = hourlyRate * WORKDAYS * WORKHOURS;
      System.out.println(name + "'s monthly salary: $" + monthlySalary);
      }

   @Override
   public void displayInfo()
      {
      System.out.println("Part-time employee: " + name);
      }
   }

// Dog slave work ???
class Dog implements Employee
   {
   private String name;
   private int    age;

   public Dog(String name, int age)
      {
      this.name = name;
      this.age = age;
      }

   @Override
   public void calculateSalary()
      {
      System.out.println("Dogs don't receive salaries!");
      }

   @Override
   public void displayInfo()
      {
      System.out.println("Dog: " + name + ", Age: " + age);
      }
   }

public final class InterfaceEmployeeDemoStart
   {
   public static void main(String[] args)
      {
      ArrayList<Employee> employees = new ArrayList<>();

      employees.add(new FullTimeEmployee("Ana Maria", 5000));
      employees.add(new PartTimeEmployee("Jose Silva", 15));
      employees.add(new Dog("Thor", 3));
      employees.add(new FullTimeEmployee("Fulano de Tal", 6000));
      employees.add(new Dog("Nala", 5));

      // see that:
      System.out.println(Employee.COMPANY_NAME);
      System.out.println(Dog.COMPANY_NAME);
      System.out.println();

      for (Employee employee : employees)
         {
         employee.displayInfo();
         employee.calculateSalary();
         System.out.println();
         }
      }
   }
