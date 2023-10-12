package colecoes;
import java.util.ArrayList;

public class ArrayList01 {
    public static void main(String[] args) {
        ArrayList<Integer> lista = new ArrayList<>();
        for(int i = 0; i < 10; i++) {
            lista.add(i);
        }
        System.out.print("[ ");
        for(Integer elemento : lista) {
            System.out.print(elemento + " ");
        }
        System.out.println("]");
    }
}
