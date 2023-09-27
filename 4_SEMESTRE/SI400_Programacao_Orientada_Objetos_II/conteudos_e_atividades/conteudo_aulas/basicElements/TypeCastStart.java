package classContent.basicElements;
/*
TypeCastStart

    � pacotes e classes
    � m�todo main()
    � convers�o de tipos 
    � truncamento * 
 */



public class TypeCastStart
   {

   public static void main(String[] args)
      {
      System.out.println("Welcome to TypeCastStart. Enjoy it.");

      System.out.println("\nAutomatic type cast");
      System.out.println("\n\tbyte --> short --> int --> long --> float --> double");

      byte   myByte;
      short  myShort;
      int    myInt;
      long   myLong;
      float  myFloat;
      double myDouble;
      char   myChar;

      myByte   = 127;
      myShort  = myByte;
      myInt    = myShort;
      myLong   = myInt;
      myFloat  = myLong;
      myDouble = myFloat;
      System.out.println("\tDouble value from byte is " + myDouble);

      System.out.println("\n\tchar --> int");
      myChar = 256;
      myInt  = myChar;

      System.out.println("\tint value from char is " + myInt);
      System.out.println();

      System.out.println("Data loss");
      myDouble = 1.999999;
      myInt    = (int) myDouble;
      System.out.println("\tint value from double is " + myInt);
      
      System.out.println();
      System.out.println("Good bye. See you later.");
      }

   }
