package inheritance;

interface Drawable
   {
   // It is implicit that the method is abstract and public 
   void draw();
   }

class Rectangle implements Drawable
   {
   private double width;
   private double height;

   public Rectangle(double width, double height)
      {
      this.width = width;
      this.height = height;
      }

   @Override
   public void draw()
      {
      System.out.println("Drawing a rectangle with width " + width + " and height " + height);
      }
   }

class Zebra implements Drawable
   {
   @Override
   public void draw()
      {
      System.out.println("Drawing a zebra!");
      }
   }

public final class IntrfaceDemoStart
   {
   public static void main(String[] args)
      {
      Drawable drawable[] = new Drawable[4];

      printWelcomeInterface();

      drawable[0] = new Rectangle(10, 30);
      drawable[1] = new Zebra();
      drawable[2] = new Rectangle(5, 20);
      drawable[3] = new Zebra();

      for (Drawable current : drawable)
         {
         current.draw();
         }
      }

   private static void printWelcomeInterface()
      {
      System.out.println("Interfaces:\n\n"
                         + "An interface is a collection of abstract methods that define a contract for implementing classes.\n"
                         + "Classes can implement multiple interfaces, allowing them to inherit multiple sets of behaviors.\n"
                         + "Interfaces are used to achieve multiple inheritance-like behavior while avoiding the issues associated with traditional multiple inheritance.\n");
      }
   }
