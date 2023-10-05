package dataBase;

public final class DAODataBaseDemoStart
   {
   static final int MEMORY = 0;
   static final int MARIADB = 1;
   
   public static void main(String[] args)
      {
      System.out.println("Database demonstration running now...");
      
      try
         {
         (new Controller(MARIADB)).start();
         }
      catch (Exception myException)
         {
         System.out.println("Exception launched. Programa aborted.");
         System.out.println(myException.getMessage());
         myException.printStackTrace();
         System.exit(0);
         }

      System.out.println("Database demonstration stopping now...");
      }

   }
