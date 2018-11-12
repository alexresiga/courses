public class Complex {
    private double real, imag;

    public Complex() {
        this(0,0);
    }

    public Complex(double real){
        this(real, 0);
    }

    public Complex(double real, double imag) {
        this.real = real;
        this.imag = imag;
    }
}
