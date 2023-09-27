import java.util.Scanner;

public class ex02 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.print("Digite um numero inteiro: ");
            int num = scanner.nextInt();
            System.out.println("O numero digitado foi: " + num);
            
        } catch (NumberFormatException e) {
            System.err.println("Erro capturado. " + e.getMessage());
        }
        
        scanner.close();
    }
}
