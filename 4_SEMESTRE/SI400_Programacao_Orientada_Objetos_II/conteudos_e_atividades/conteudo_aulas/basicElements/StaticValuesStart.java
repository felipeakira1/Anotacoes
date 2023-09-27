package classContent.basicElements;
/*
 * StaticValuesStart

    � pacotes e classes
    � m�todo main()
    � estruturas sequenciais, condicionais e repetitivas (+for each)
    � imports m�ltiplos
    � ArrayList
    � m�todos de ordena��o e embaralhamento
    � n�meros pseudoaleat�rios
    � constantes de classe (declara��o e uso)
    � constantes p�blicas
    � m�todos de classe (declara��o e uso)
    � instancia��o de objetos
    � m�ltipla declara��o de classes no arquivo
    � m�todos herdados sobrescritos (toString)
    � construtor e chamada de construtores ancestrais
    � encapsumamento b�sico (public / private)
    � implementa��o de interface (Comparable)
    � ponteiro this (ou refer�ncia this???)
    � desaloca��o autom�tica de mem�ria
 */

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public final class StaticValuesStart
   {
   static Random    randGen      = new Random();
   static final int maxValue     = 1024;
   static final int maxReference = 10;
   static final int minInstances = 2;

   public static void main(String[] args)
      {
      System.out.println("Welcome to StaticValuesStart. Enjoy it.");

      int                   count  = randGen.nextInt(maxReference) + minInstances;
      ArrayList<SimpleDemo> values = new ArrayList<SimpleDemo>();

      for (int instance = 0; instance < count; instance++)
         {
         values.add(new SimpleDemo(randGen.nextInt(maxValue)));
         }

      System.out.println("Original list\n");
      for (SimpleDemo simpleDemo : values)
         {
         System.out.println(simpleDemo);
         }
      System.out.println();

      System.out.println("Shuffled list\n");
      Collections.shuffle(values);

      for (SimpleDemo simpleDemo : values)
         {
         System.out.println(simpleDemo);
         }
      System.out.println();

      System.out.println("Sorted list\n");
      Collections.sort(values);

      System.out.println("public static method -- toString -- public final field");
      for (SimpleDemo simpleDemo : values)
         {
         System.out.println(SimpleDemo.getClassName() + " -->> " + simpleDemo + " -->> " + simpleDemo.ADVERTISING);
         }

      System.out.println();
      System.out.println("Good bye. See you later.");
      }

   }

class SimpleDemo implements Comparable<SimpleDemo>
   {
   private static final String NAME          = "SimpleDemo Class";
   public final String         ADVERTISING   = "Buy SimpleDemo objects!";

   private static int          instanceCount = 0;
   private int                 instanceId;
   private int                 value;

   SimpleDemo(int value)
      {
      super();
      this.instanceId = ++instanceCount;
      this.value      = value;
      }

   public static String getClassName()
      {
      return (NAME);
      }

   @Override
   public String toString()
      {
      return "SimpleDemo [ADVERTISING=" + ADVERTISING + ", instanceId=" + instanceId + ", value=" + value + "]";
      }

   @Override
   public int compareTo(SimpleDemo otherObject)
      {
      return (this.value - otherObject.value);
      }
   }
