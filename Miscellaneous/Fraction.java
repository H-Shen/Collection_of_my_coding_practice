import java.math.BigInteger;

/**
 * An implementation of fraction in Java.
 *
 * @author hshen
 * @version 2019-07-31
 */
class Fraction implements Comparable<Fraction> {

    /**
     * Fields of a fraction.
     */
    private BigInteger numerator;
    private BigInteger denominator;

    /**
     * Constructor which takes the numerator and the denominator
     *
     * @param numerator   the numerator of the fraction
     * @param denominator the denominator of the fraction
     */
    private Fraction(BigInteger numerator, BigInteger denominator) {
        if (denominator.compareTo(BigInteger.ZERO) == 0) {
            throw new ArithmeticException("/ zero");
        }

        this.numerator = numerator;
        this.denominator = denominator;

        // the denominator would always be positive
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
        numerator = obj.getNumerator();
        denominator = obj.getDenominator();
        reduce();
    }

    /**
     * Subtraction for two Fraction objects
     * @param a another Fraction object
     * @return
     */
    private Fraction subtract(Fraction a) {
        BigInteger n = numerator.multiply(a.getDenominator()).subtract(denominator.multiply(
                a.getNumerator()));
        BigInteger m = denominator.multiply(a.getDenominator());
        return new Fraction(n, m);
    }

    private BigInteger getNumerator() {
        return numerator;
    }

    void setNumerator(BigInteger numerator) {
        this.numerator = numerator;
    }

    private BigInteger getDenominator() {
        return denominator;
    }

    void setDenominator(BigInteger denominator) {
        this.denominator = denominator;
    }

    /**
     * A method to reduce a fraction by its gcd(numerator, denominator).
     */
    private void reduce() {
        BigInteger gcd = numerator.gcd(denominator);
        numerator = numerator.divide(gcd);
        denominator = denominator.divide(gcd);
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

    private static final int ARGUMENT_LENGTH = 2;

    public static void main(String[] args) {
        try {
            if (args.length != ARGUMENT_LENGTH) {
                throw new IllegalArgumentException();
            }
            BigInteger numerator   = new BigInteger(args[0]);
            BigInteger denominator = new BigInteger(args[1]);
            System.out.println(new Fraction(numerator, denominator));
        } catch (ArithmeticException ae) {
            ae.printStackTrace();
        } catch (Exception ex) {
            System.out.println("Usage: ./Fraction numerator denominator");
            System.exit(0);
        }
    }
}
