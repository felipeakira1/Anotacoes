package classContent.basicElements;
/*
 * MathLibraryStart

    � pacotes e classes
    � m�todo main()
    � constantes de classe (uso)
    � m�todos de classe (uso)
    � classe Math
 */

public final class MathLibraryStart
   {

   public static void main(String[] args)
      {
      double value01 = Math.PI;
      double value02 = Math.abs(-4.94);
      double value03 = Math.cos(360.0);
      double value04 = Math.sin(360.0);
      double value05 = Math.log(1024);
      double value06 = Math.log10(1000);
      double value07 = Math.random();
      double value08 = Math.sqrt(144);
      double value09 = Math.pow(2, 8);

      System.out.println("Value of PI is " + value01);
      System.out.println("Absolute value of -4.94 is " + value02);
      System.out.println("Cossine of 360.0 is " + value03);
      System.out.println("Sine of 360. is " + value04);
      System.out.println("Log natural of 1024 is " + value05);
      System.out.println("Log 10 of 1000 is " + value06);
      System.out.println("A randon value is " + value07);
      System.out.println("Square root of 144 is " + value08);
      System.out.println("2 ^ 8 is " + value09);
      
      System.out.println();
      System.out.println("The area of a unitary cirlce is " + (Math.PI * 1.00 * 1.00));
      }

   }
