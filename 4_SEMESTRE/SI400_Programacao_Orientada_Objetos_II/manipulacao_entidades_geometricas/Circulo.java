public class Circulo extends FormaGeometrica {
    private Coordenada centro;
    private int raio;

    public Circulo(Coordenada centro, int raio) {
        this.centro = centro;
        this.raio = raio;
    }

    @Override
    public double calcularArea() {
        return Math.PI * raio * raio;
    }

    @Override
    public double calcularPerimetro() {
        return Math.PI * raio * 2;
    }

}