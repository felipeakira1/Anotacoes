public class Main {
    public static void main(String[] args) {
        Coordenada c1 = new Coordenada(0, 0);
        Coordenada c2 = new Coordenada(4, 3);
        System.out.println(c1.toString());
        System.out.println(c2.toString());

        Segmento s1 = new Segmento(c1, c2);
        System.out.println(s1.toString());
        System.out.println("Comprimento do segmento é: " + s1.comprimentoSegmento());
        s1.inverterSegmento();
        System.out.println(s1.toString());
        s1.translacaoSegmento(10, 10);
        System.out.println(s1.toString());

        Coordenada centroCirculo = new Coordenada(0, 0);
        Circulo circulo = new Circulo(centroCirculo, 10);
        System.out.println("Area do circulo: " + circulo.calcularArea());
        System.out.println("Area do perimetro: " + circulo.calcularPerimetro());
        
    }
}
