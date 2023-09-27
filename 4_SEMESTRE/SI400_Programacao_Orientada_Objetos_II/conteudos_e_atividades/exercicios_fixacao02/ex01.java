import java.util.Scanner;

public class ex01 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite o numerador: ");
        int num1 = scanner.nextInt();
        System.out.print("Digite o denominador: ");
        int num2 = scanner.nextInt();
        try {
            double resultado = num1/num2;
            System.out.println("Resultado da divisão: " + resultado);
        } catch(ArithmeticException e) {
            System.out.println("Erro capturado. " + e.getMessage());
        }
        scanner.close();
    }
}
