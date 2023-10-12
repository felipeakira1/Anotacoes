/* Leia dois arquivos de texto e concatene o conteúdo deles em um terceiro arquivo. */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class ConcatenarArquivos {
    public static void main(String[] args) {
        String filePath1 = "../files/arquivo.txt";
        String filePath2 = "../files/arquivo2.txt";
        String filePath3 = "../files/arquivo3.txt";

        try(BufferedReader reader1 = new BufferedReader(new FileReader(filePath1));
            BufferedReader reader2 = new BufferedReader(new FileReader(filePath2));
            BufferedWriter writer = new BufferedWriter(new FileWriter(filePath3))) {
                
                String linha;

                while((linha = reader1.readLine()) != null) {
                    writer.write(linha);
                    writer.newLine();
                }

                while((linha = reader2.readLine()) != null) {
                    writer.write(linha);
                    writer.newLine();
                }
                System.out.println("Arquivos concatenados com sucesso!");
        } catch (IOException e) {
            System.err.println("Erro: " + e.getMessage());
        }
    }
}
