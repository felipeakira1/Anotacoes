interface Cumprimentar {
    void cumprimentar();
}

public class ClasseAnonima {
    public static void main(String[] args) {
        // Classe anônima implementando a interface Greeting
        Cumprimentar cumprimento = new Cumprimentar() {
            @Override
            public void cumprimentar() {
                System.out.println("Ola!");
            }
        };

        cumprimento.cumprimentar(); // Chama o método da classe anônima
    }
}
