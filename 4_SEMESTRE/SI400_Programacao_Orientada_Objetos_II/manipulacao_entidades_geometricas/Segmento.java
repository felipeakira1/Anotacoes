public class Segmento {
    private Coordenada inicio;
    private Coordenada fim;

    public Segmento(Coordenada inicio, Coordenada fim) {
        this.inicio = inicio;
        this.fim = fim;
    }

    @Override
    public String toString() {
        return "Segmento: [" + this.inicio.toString() + ", " + this.fim.toString() + "]";
    }

    public double comprimentoSegmento() {
        return Coordenada.distanciaCoordenadas(inicio, fim);
    }

    public void inverterSegmento() {
        Coordenada aux = this.inicio;
        this.inicio = this.fim;
        this.fim = aux;
    }
    
    public void translacaoSegmento(int deltaX, int deltaY) {
        this.inicio.translacaoCoordenada(deltaX, deltaY);
        this.fim.translacaoCoordenada(deltaX, deltaY);
    }
}
