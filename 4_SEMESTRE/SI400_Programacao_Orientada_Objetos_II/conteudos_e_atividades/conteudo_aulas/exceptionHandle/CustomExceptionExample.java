package exceptionHandle;

class MyCustomException extends Exception
   {
   public MyCustomException(String message)
      {
      super(message);
      }
   }

public class CustomExceptionExample
   {
   public static void main(String[] args)
      {
      try
         {
         int balance        = 100;
         int withdrawAmount = 200;

         if (withdrawAmount > balance)
            {
            throw new MyCustomException("Insufficient balance");
            }

         balance -= withdrawAmount;
         System.out.println("Withdrawal successful. New balance: " + balance);
         }
      catch (MyCustomException e)
         {
         System.out.println("Error: " + e.getMessage());
         }
      }
   }
