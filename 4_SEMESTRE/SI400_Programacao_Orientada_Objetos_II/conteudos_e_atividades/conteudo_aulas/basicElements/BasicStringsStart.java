package classContent.basicElements;
/*
 * BasicStringsStart

    � pacotes e classes
    � m�todo main()
    � estruturas sequenciais, condicionais e repetitivas
    � entrada de dados (classe Scanner)
    � atributos est�ticos
    � m�todos est�ticos
    � encapsulamento de m�todos (public / private)
    � Strings � declara��o e uso
    � Strings � compartilhamento de mem�ria
    � Strings � compara��es
    � Strings � m�todos da classe
    � convers�o de tipos (byte x char)
 */

import java.util.Scanner;

public final class BasicStringsStart
   {
   static private Scanner scanner = new Scanner(System.in);

   public static void main(String[] args)
      {
      System.out.println("Welcome to BasicStringsStart. Enjoy it.");

      String stringA = "Unicamp";
      String stringB = "Unicamp";
      String stringC = "unicamp";
      String stringD = "Faculdade de Tecnologia";

      System.out.println();
      System.out.println(stringA + " - " + stringD);

      System.out.println("Pay attention !");
      System.out.println();

      // First block: basic

      if (stringA == stringB)
         {
         System.out.println(stringA + " is equal to " + stringB + " (operator ==)");
         }
      else
         {
         System.out.println(stringA + " is NOT equal to " + stringB + " (operator ==)");
         }

      if (stringA.equals(stringB))
         {
         System.out.println(stringA + " is equal to " + stringB + " (method equals())");
         }
      else
         {
         System.out.println(stringA + " is NOT equal to " + stringB + " (method equals())");
         }
      System.out.println();

      // Second block: ignore case

      if (stringA == stringC)
         {
         System.out.println(stringA + " is equal to " + stringC + " (operator ==)");
         }
      else
         {
         System.out.println(stringA + " is NOT equal to " + stringC + " (operator ==)");
         }

      if (stringA.equals(stringC))
         {
         System.out.println(stringA + " is equal to " + stringC + " (method equals())");
         }
      else
         {
         System.out.println(stringA + " is NOT equal to " + stringC + " (method equals())");
         }

      if (stringA.equalsIgnoreCase(stringC))
         {
         System.out.println(stringA + " is equal to " + stringC + " (method equalsIgnoreCase())");
         }
      else
         {
         System.out.println(stringA + " is NOT equal to " + stringC + " (method equalsIgnoreCase())");
         }
      System.out.println();

      // Third block: unshared strings

      System.out.println("Pleas, type \"" + stringA + "\" + [ENTER]");

      stringB = scanner.next().trim();

      if (stringA == stringB)
         {
         System.out.println(stringA + " is equal to " + stringB + " (operator ==)");
         }
      else
         {
         System.out.println(stringA + " is NOT equal to " + stringB + " (operator ==)");
         }

      if (stringA.equals(stringB))
         {
         System.out.println(stringA + " is equal to " + stringB + " (method equals())");
         }
      else
         {
         System.out.println(stringA + " is NOT equal to " + stringB + " (method equals())");
         }
      if (stringA.equalsIgnoreCase(stringB))
         {
         System.out.println(stringA + " is equal to " + stringB + " (method equalsIgnoreCase())");
         }
      else
         {
         System.out.println(stringA + " is NOT equal to " + stringB + " (method equalsIgnoreCase())");
         }

      System.out.println();
      System.out.println("Your string is formed by");

      for (int count = 0; count < stringB.length(); count++)
         {
         System.out.print(stringB.charAt(count) + "  ");
         }
      System.out.println();

      for (Byte myByte : stringB.getBytes())
         {
         System.out.print(myByte + "\t");
         }
      System.out.println();
      for (Byte myByte : stringB.getBytes())
         {
         System.out.print(((char) (myByte & 0xFF)) + "\t");
         }
      System.out.println();

      System.out.println();
      System.out.println("Good bye. See you later.");
      }
   }
