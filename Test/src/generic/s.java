package generic;

public class s {

        public static void main(String[] args) {
            Integer X = new Integer (1) ;
            Integer Y = new Integer (1) ;
            System.out.println ( "a: X.equals(1) is " + X.equals(1) );
            System.out.println ( "b: X.equals(Y) is " + X.equals(Y) );
            System.out.println ( "c: (X == 1) is " + (X == 1)  );
            System.out.println ( "d: (X == Y) is " + (X == Y)  );
            System.out.println ( "e: (X != Y) is " + (X != Y)  );
            System.out.println ( "f: (X != 1) is " + (X != 1)  );
            System.out.println ( "g: (X >  1) is " + (X >  1)  );
            System.out.println ( "h: (X <  1) is " + (X <  1)  );
        }
}
