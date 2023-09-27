public final class BasicElementsStart
   {
   public static void main(String[] args)
      {
      System.out.println("Welcome to BasicElementsStart. Enjoy it.\n");

      demoBooleanType();
      demoCharType();
      demoIntegerTypes();
      demoRealTypes();

      System.out.println("Good bye. See you later.");
      }

   private static void demoBooleanType()
      {
      System.out.println("Boolean type");

      // two ways to initialize
      boolean myBooleanTrue  = true;
      boolean myBooleanFalse = Boolean.FALSE;
      
      System.out.println("\tShowing values for the boolean type:\n");
      System.out.println("\tTrue .......: " + myBooleanTrue);
      System.out.println("\tFalse ......: " + myBooleanFalse);
      System.out.println();
      }

   private static void demoCharType()
      {
      System.out.println("Char type");
      char myCharHigh = Character.MAX_VALUE;
      char myCharLow  = Character.MIN_VALUE;

      System.out.println("\tShowing values for the character type:\n");
      System.out.println("\tMaximum .......: " + myCharHigh + " (" + (int) (myCharHigh) + ")");
      System.out.println("\tMinimum .......: " + myCharLow + " (" + (int) (myCharLow) + ")");
      System.out.println("\tA .............: " + 'A' + " (" + (int) ('A') + ")");
      System.out.println("\ta .............: " + 'a' + " (" + (int) ('a') + ")");
      System.out.println("\tZ .............: " + 'Z' + " (" + (int) ('Z') + ")");
      System.out.println("\tz .............: " + 'z' + " (" + (int) ('z') + ")");
      System.out.println();
      }

   private static void demoIntegerTypes()
      {
      System.out.println("Integer types");
      int   myInteger      = Integer.MAX_VALUE;
      short myShortInteger = Short.MAX_VALUE;
      long  myLongInteger  = Long.MAX_VALUE;
      byte  myByte         = Byte.MAX_VALUE;

      System.out.println("\tShowing maximum value for the integer types:\n");
      System.out.println("\tInteger .......: " + myInteger);
      System.out.println("\tShort Integer .: " + myShortInteger);
      System.out.println("\tLong Integer ..: " + myLongInteger);
      System.out.println("\tByte ..........: " + myByte);
      System.out.println();
      }

   private static void demoRealTypes()
      {
      System.out.println("Real types");
      float myFloatHigh = Float.MAX_VALUE;
      float myFloatLow  = Float.MIN_VALUE;
      ;

      double myDoubleHigh       = Double.MAX_VALUE;
      double myDoubleLow        = Double.MIN_VALUE;

      double myDoubleInfinity   = Double.POSITIVE_INFINITY;
      double myDoubleNotANumber = Double.NaN;

      System.out.println("\tShowing values for the real types:\n");
      System.out.println("\tFloat high ......: " + myFloatHigh);
      System.out.println("\tFloat low .......: " + myFloatLow);
      System.out.println();
      System.out.println("\tDouble high .....: " + myDoubleHigh);
      System.out.println("\tDouble low ......: " + myDoubleLow);
      System.out.println();
      System.out.println("\tDouble infinity .: " + myDoubleInfinity);
      System.out.println("\tDouble NaN ......: " + myDoubleNotANumber);
      System.out.println();
      }

   }
