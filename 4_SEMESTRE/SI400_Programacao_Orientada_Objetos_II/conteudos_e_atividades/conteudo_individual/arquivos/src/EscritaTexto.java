import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class EscritaTexto {
    public static void main(String[] args) {
        String path = "../files/arquivo.txt";

        try(Scanner scanner = new Scanner(System.in);
            BufferedWriter writer = new BufferedWriter(new FileWriter(path))) {
                System.out.print("Digite as linhas do arquivo (digite 'fim' para parar): ");
                String linha;

                while(true) {
                    linha = scanner.nextLine();
                    if(linha.equalsIgnoreCase("fim")) {
                        break;
                    }
                    writer.write(linha);
                    writer.newLine();
                }

                System.out.println("Conteudo foi escrito no arquivo com sucesso!");
            } catch(IOException e) {
                System.out.println("Erro: " + e.getMessage());
            }
    }
}
