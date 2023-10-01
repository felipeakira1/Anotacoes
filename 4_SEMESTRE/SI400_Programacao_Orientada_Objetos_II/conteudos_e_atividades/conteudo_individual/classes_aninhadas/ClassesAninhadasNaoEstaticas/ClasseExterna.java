public class ClasseExterna {
    // Membro não estático
    private int dadoExterno = 20;
    private static int dadoExternoEstatico = 30;

    // Classe aninhada não estática
    class ClasseInterna {
        public void display() {
            System.out.println("Atributo nao estatico da classe externa: " + dadoExterno);
            System.out.println("Atributo estatico da classe externa: " + dadoExternoEstatico);
        }
    }

    public static void main(String[] args) {
        ClasseExterna externo = new ClasseExterna();
        ClasseExterna.ClasseInterna interno = externo.new ClasseInterna();
        interno.display();
    }
}