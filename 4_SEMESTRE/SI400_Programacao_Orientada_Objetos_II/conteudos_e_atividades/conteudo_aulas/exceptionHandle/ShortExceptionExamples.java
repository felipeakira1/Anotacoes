package exceptionHandle;

public class ShortExceptionExamples
   {
   public static void main(String[] args)
      {
      // Example 1: ArrayIndexOutOfBoundsException
      try
         {
         int[] numbers = { 1, 2, 3 };
         System.out.println(numbers[5]);
         }
      catch (ArrayIndexOutOfBoundsException e)
         {
         System.out.println("Array index out of bounds.");
         }

      // Example 2: NumberFormatException
      try
         {
         String text   = "ABC";
         int    number = Integer.parseInt(text);
         System.out.println(number);
         }
      catch (NumberFormatException e)
         {
         System.out.println("Invalid number format.");
         }
      }
   }
