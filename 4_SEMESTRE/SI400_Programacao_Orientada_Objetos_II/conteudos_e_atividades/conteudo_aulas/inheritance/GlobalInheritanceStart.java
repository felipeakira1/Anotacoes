package inheritance;

public final class GlobalInheritanceStart
   {
   public GlobalInheritanceStart()
      {
      System.out.println("All Java classes have the same primordial ancestor: OBJECT CLASS !");
      }

   public static void main(String[] args)
      {
      GlobalInheritanceStart globalInheritanceStart = new GlobalInheritanceStart();
      System.out.println("Hash code: " + globalInheritanceStart.hashCode());
      System.out.println("toString : " + globalInheritanceStart.toString());
      }

   @Override
   public int hashCode()
      {
      // TODO Auto-generated method stub
      return super.hashCode();
      }

   @Override
   public boolean equals(Object obj)
      {
      // TODO Auto-generated method stub
      return super.equals(obj);
      }

   @Override
   protected Object clone() throws CloneNotSupportedException
      {
      // TODO Auto-generated method stub
      return super.clone();
      }

   @Override
   public String toString()
      {
      // TODO Auto-generated method stub
      return super.toString();
      }

   @Override
   protected void finalize() throws Throwable
      {
      // TODO Auto-generated method stub
      super.finalize();
      }

   }
