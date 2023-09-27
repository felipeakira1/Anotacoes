package exceptionHandle;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class ResourceHandlingExample
   {

   public static void main(String[] args)
      {
      try (BufferedReader reader = new BufferedReader(new FileReader("example.txt")))
         {
         String line = reader.readLine();
         System.out.println("Read: " + line);
         }
      catch (IOException e)
         {
         System.out.println("An error occurred: " + e.getMessage());
         }
      }
   }