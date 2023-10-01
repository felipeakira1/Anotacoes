public class ClasseExterna {
    private int atributoExterno = 30;

    public void localInnerExample() {
        // Classe local
        class LocalInner {
            void display() {
                System.out.println("Data from outer class: " + atributoExterno);
            }
        }

        LocalInner localInner = new LocalInner();
        localInner.display();
    }

    public static void main(String[] args) {
        ClasseExterna outer = new ClasseExterna();
        outer.localInnerExample();
    }
}