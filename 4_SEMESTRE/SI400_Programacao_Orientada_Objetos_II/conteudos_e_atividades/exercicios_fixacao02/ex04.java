import java.util.Scanner;

class MyCustomException extends Exception{
    private String mensagemDetalhada;

    public MyCustomException(String mensagem) {
        super(mensagem);
        this.mensagemDetalhada = "Erro capturado: " + mensagem;
    }

    public String getMensagemDetalhada() {
        return mensagemDetalhada;
    }
}

public final class ex04 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.print("Digite um nome: ");
            String mensagem = scanner.next();
            throw new MyCustomException(mensagem);
        } catch(MyCustomException e) {
            System.err.println(e.getMensagemDetalhada());
        } finally {
            System.out.println("Bloco finally executado");
        }
        scanner.close();
    }
}