// https://www.nowcoder.com/practice/6221faa383fc49f1b10dffcb62c866bf

import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;
import java.util.Scanner;

public class Main {

    public static void main(String[] arg) throws ScriptException {

        ScriptEngineManager manager = new ScriptEngineManager();
        ScriptEngine        engine  = manager.getEngineByName("js");
        Scanner             in      = new Scanner(System.in);
        String              expr;
        while (in.hasNextLine()) {
            expr = in.nextLine();
            if ("END".equals(expr)) {
                break;
            }
            System.out.println(engine.eval(expr));
        }
    }
}