public class Coordenada {
    private int x;
    private int y;

    public Coordenada(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public String toString() {
        return "(" + this.x + ", " + this.y + ")";
    }

    public static double distanciaCoordenadas(Coordenada c1, Coordenada c2) {
        double deltaX = c1.x - c2.x;
        double deltaY = c1.y - c2.y;
        double cateto1 = Math.pow(deltaX, 2);
        double cateto2 = Math.pow(deltaY, 2);
        return Math.sqrt(cateto1 + cateto2);
    }
    
    public void translacaoCoordenada(int deltaX, int deltaY) {
        this.x += deltaX;
        this.y += deltaY;
    }
}