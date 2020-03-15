import java.math.BigInteger;

/**
 * An implementation of fraction in Java.
 *
 * @author hshen
 * @version 2019-07-31
 */
class Fraction implements Comparable<Fraction> {

    private static final int        ARGUMENT_LENGTH = 6;
    /**
     * Fields of a fraction.
     */
    private              BigInteger numerator;
    private              BigInteger denominator;

    /**
     * Constructor which takes the numerator and the denominator whose type are both String
     */
    private Fraction(String numerator, String denominator) {
        this(new BigInteger(numerator), new BigInteger(denominator));
    }

    /**
     * Constructor which takes the numerator and the denominator whose type are both BigInteger
     *
     * @param numerator   the numerator of the fraction
     * @param denominator the denominator of the fraction
     */
    private Fraction(BigInteger numerator, BigInteger denominator) {
        if (denominator.compareTo(BigInteger.ZERO) == 0) {
            throw new ArithmeticException("/ zero");
        }

        // Since BigInteger is immutable, there is no need to do a deepcopy.
        this.numerator = numerator;
        this.denominator = denominator;

        // The denominator would always be positive
        if (this.denominator.compareTo(BigInteger.ZERO) < 0) {
            this.denominator = this.denominator.multiply(new BigInteger("-1"));
            this.numerator = this.numerator.multiply(new BigInteger("-1"));
        }
        reduce();
    }

    /**
     * Copy constructor
     *
     * @param obj another Fraction object
     */
    private Fraction(Fraction obj) {
        this(obj.getNumerator(), obj.getDenominator());
    }

    /**
     * A method checks if the string is not an integer.
     *
     * @param s the string to check
     * @return true if the string is not an integer, otherwise false.
     */
    private static boolean isNotInteger(String s) {
        // Case 1: s contains redundant leading zeros
        if (s.length() > 1 && s.charAt(0) == '0') {
            return true;
        }
        // Case 2: s contains only a '-'
        if (s.length() == 1 && s.charAt(0) == '-') {
            return true;
        }
        // Case 3: s contains illegal characters.
        for (int i = 0; i < s.length(); ++i) {
            if (i == 0 && s.charAt(i) == '-') {
                continue;
            }
            if (!Character.isDigit(s.charAt(i))) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        try {
            if (args.length != ARGUMENT_LENGTH) {
                throw new IllegalArgumentException();
            }
            for (String arg : args) {
                if (isNotInteger(arg)) {
                    throw new IllegalArgumentException();
                }
            }
            Fraction a = new Fraction(args[0], args[1]);
            Fraction b = new Fraction(args[2], args[3]);
            System.out.println(a.add(b));
            System.out.println(a.subtract(b));
            System.out.println(a.multiply(b));
            System.out.println(a.divide(b));

            a.setNumerator(new BigInteger(args[4]));
            b.setNumerator(new BigInteger(args[5]));
            System.out.println(a);
            System.out.println(b);

        } catch (ArithmeticException ae) {
            System.out.println(ae.toString());
        } catch (Exception ex) {
            System.out.println("Usage: ./Fraction numerator denominator");
            System.exit(0);
        }
    }

    /**
     * Subtraction for two Fraction objects
     *
     * @param obj another Fraction object
     * @return a Fraction object
     */
    public Fraction subtract(Fraction obj) {
        BigInteger numerator = this.numerator.multiply(obj.getDenominator()).subtract(this.denominator.multiply(
                obj.getNumerator()));
        BigInteger denominator = this.denominator.multiply(obj.getDenominator());
        return new Fraction(numerator, denominator);
    }

    public Fraction add(Fraction obj) {
        BigInteger numerator =
                this.numerator.multiply(obj.getDenominator()).add(this.denominator.multiply(obj.getNumerator()));
        BigInteger denominator = this.denominator.multiply(obj.getDenominator());
        return new Fraction(numerator, denominator);
    }

    public Fraction multiply(Fraction obj) {
        BigInteger numerator   = this.numerator.multiply(obj.getNumerator());
        BigInteger denominator = this.denominator.multiply(obj.getDenominator());
        return new Fraction(numerator, denominator);
    }

    public Fraction divide(Fraction obj) {
        BigInteger numerator   = this.numerator.multiply(obj.getDenominator());
        BigInteger denominator = this.denominator.multiply(obj.getNumerator());
        return new Fraction(numerator, denominator);
    }

    private BigInteger getNumerator() {
        return this.numerator;
    }

    void setNumerator(BigInteger numerator) {
        this.numerator = numerator;
        reduce();
    }

    private BigInteger getDenominator() {
        return this.denominator;
    }

    void setDenominator(BigInteger denominator) {
        if (denominator.compareTo(BigInteger.ZERO) == 0) {
            throw new ArithmeticException();
        }
        this.denominator = denominator;
        reduce();
    }

    /**
     * A method to reduce a fraction by its gcd(numerator, denominator).
     */
    private void reduce() {
        BigInteger gcd = this.numerator.gcd(this.denominator);
        this.numerator = this.numerator.divide(gcd);
        this.denominator = this.denominator.divide(gcd);
    }

    @Override
    public String toString() {
        if (numerator.mod(denominator).compareTo(BigInteger.ZERO) == 0) {
            return numerator.divide(denominator).toString();
        }
        return numerator.toString() + "/" + denominator.toString();
    }

    @Override
    public int compareTo(Fraction other) {
        Fraction a = new Fraction(this.subtract(other));
        return Integer.compare(a.getNumerator().compareTo(BigInteger.ZERO), 0);
    }
}
