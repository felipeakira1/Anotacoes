public class ex03 {
    public static void main(String[] args) {
        int[] numeros = {1, 2, 3, 4, 5};
        for(int i = 0; i < 5; i++) {
            System.out.println(numeros[i]);
        }
        try {
            System.out.println(numeros[6]);
        } catch(ArrayIndexOutOfBoundsException e) {
            System.err.println(e);
        }
    } 
}
