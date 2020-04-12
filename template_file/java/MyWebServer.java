import java.io.*;
import java.net.*;

public class MyWebServer
{
    public static void main(String []args) throws Exception{
        ServerSocket ss = new ServerSocket(9999);
        System.out.println("MyWebServer wait for connecting ...");
        Socket s = ss.accept();
        System.out.println("MyWebServer connected");
        OutputStream os = s.getOutputStream();
        os.write("<h1>MyWebServer</h1>".getBytes());
        os.close();
        s.close();
    }
}
