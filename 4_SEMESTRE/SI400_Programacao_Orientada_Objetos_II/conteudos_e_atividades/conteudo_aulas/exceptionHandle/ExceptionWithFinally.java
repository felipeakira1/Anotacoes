package exceptionHandle;

public class ExceptionWithFinally
   {
   public static void main(String[] args)
      {
      try
         {
         int result = 10 / 0;
         System.out.println("Result: " + result);
         }
      catch (ArithmeticException e)
         {
         System.out.println("An error occurred: " + e.getMessage());
         }
      finally
         {
         System.out.println("Finally block executed.");
         }
      }
   }
