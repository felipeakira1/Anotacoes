package exceptionHandle;

public class SimpleExceptionExample
   {
   public static void main(String[] args)
      {
      try
         {
         int result = 10 / 0; // This will throw an ArithmeticException
         System.out.println("Result: " + result);
         }
      catch (ArithmeticException e)
         {
         System.out.println("An error occurred: " + e.getMessage());
         }
      }
   }
