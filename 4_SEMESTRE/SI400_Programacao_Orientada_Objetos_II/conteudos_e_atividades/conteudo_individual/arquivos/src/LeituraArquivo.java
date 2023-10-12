import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class LeituraArquivo {
    public static void main(String[] args) {
        try {
            FileReader fileReader = new FileReader("../files/arquivo.txt");
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            String linha;
            while((linha = bufferedReader.readLine()) != null) {
                System.out.println(linha);
            }

            bufferedReader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
