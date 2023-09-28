public interface Teste {
    void cumprimentar();
}

public class InterfaceTeste implements Teste {
    @Override
    public void cumprimentar() {
        System.out.println("Ola");
    }

    public static void main(String[] args) {
        
    }
}
