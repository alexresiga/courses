import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        ArrayList<?> wildlist;
        ArrayList<Integer> intlist = new ArrayList<>();
        wildlist = intlist;
        intlist.add(1, new Integer(2));
        wildlist.add(1, new Integer(2));
        Integer a = intlist.get(1);
        Integer b = wildlist.get(1);
    }
}
