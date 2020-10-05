public class Outer {
    private int innerCounter;
    class Inner{
        Inner(){innerCounter++;}
        public String toString(){
            return String.valueOf(innerCounter);
        }
    }
    public void multiply(){
        Inner inner = new Inner();
        this.new Inner();
        System.out.print(inner);
        inner = new Outer().new Inner();
        System.out.println(inner);
    }

    public static void main(String[] args) {
        new Outer().multiply();
    }
}
