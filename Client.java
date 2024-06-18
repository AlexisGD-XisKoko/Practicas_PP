import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        String hostName = "localhost"; // Dirección del servidor, localhost significa que está en la misma máquina
        int port = 5000; // El puerto debe coincidir con el que el servidor está escuchando

        try (Socket socket = new Socket(hostName, port)) {
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            out.println("Hola, servidor!"); // Enviar un mensaje al servidor
            System.out.println("Mensaje enviado al servidor.");

            // Leer la respuesta del servidor
            String response = in.readLine();
            System.out.println("Respuesta del servidor: " + response);

            // Cerrar los streams y el socket
            in.close();
            out.close();
            socket.close();
        } catch (UnknownHostException e) {
            System.out.println("No se pudo detectar el servidor en " + hostName);
            System.out.println(e.getMessage());
        } catch (IOException e) {
            System.out.println("No se pudo obtener I/O para la conexión con: " + hostName);
            System.out.println(e.getMessage());
        }
    }
}
