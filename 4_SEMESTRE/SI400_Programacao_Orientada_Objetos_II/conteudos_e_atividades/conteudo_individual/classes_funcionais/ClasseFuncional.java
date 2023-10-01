public class ClasseFuncional {
    @FunctionalInterface
    interface Operacao  {
        int calcular(int a, int b);
    }
    public static void main(String[] args) {
        Operacao soma = (a, b) -> a + b;
        Operacao subtracao = (a, b) -> a - b;
        Operacao multiplicacao = (a, b) -> a * b;
        Operacao divisao = (a, b) -> a / b;
        int a = 5;
        int b = 10;
        System.out.println("A soma de " + a + " e " + b + " eh: " + soma.calcular(a, b));
        System.out.println("A subtracao de " + a + " e " + b + " eh: " + subtracao.calcular(a, b));
        System.out.println("A multiplicacao de " + a + " e " + b + " eh: " + multiplicacao.calcular(a, b));
        System.out.println("A divisao de " + a + " e " + b + " eh: " + divisao.calcular(a, b));
    }
}
