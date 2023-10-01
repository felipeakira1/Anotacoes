public class ClasseExterna {
    // Membro estático
    private static int atributoExternoEstatico = 10;
    private int atributoExterno = 20;

    // Classe aninhada estática
    static class ClasseAninhadaEstatica {
        public void display() {
            System.out.println("Atributo estatico da classe externa: " + atributoExternoEstatico);
            // System.out.println("Atributo nao estatico da classe externa: " + atributoExterno);
        }
    }

		public static void main(String[] args) {
        // Acesso à classe aninhada estática sem instanciar a classe externa
        ClasseExterna.ClasseAninhadaEstatica nested = new ClasseExterna.ClasseAninhadaEstatica();
        nested.display();
    }
}