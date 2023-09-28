package inheritance;

abstract class AbstractShape
   {
   public AbstractShape()
      {
      super();
      System.out.println("Abstract Classes:\n" + "\n"
                         + "An abstract class is a class that cannot be instantiated directly.\n"
                         + "It can have both abstract and concrete methods.\n"
                         + "Subclasses of an abstract class must provide implementations for its abstract methods.\n");
      }

   abstract double calculateArea();
   }

class Circle extends AbstractShape
   {
   private double radius;

   public Circle(double radius)
      {
      this.radius = radius;
      }

   @Override
   double calculateArea()
      {
      return Math.PI * radius * radius;
      }
   }

public final class AbstractClassDemoStart
   {
   public static void main(String[] args)
      {
      AbstractShape abstractShape = new Circle(1.0);
      System.out.println("Area of the shape is: "+abstractShape.calculateArea());
      }
   }
