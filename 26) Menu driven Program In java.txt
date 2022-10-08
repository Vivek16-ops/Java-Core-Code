import java.io.*;

class abc {
    void fiboacci() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter The Number To Generate Fibonacci Series");
        int x = Integer.parseInt(br.readLine());
        int n1 = 0, n2 = 1, n3, i, count = x;
        System.out.println(n1 + " " + n2);// Print 0 and 1 because it is already declare
        System.out.println("Fibonacci series is");
        for (i = 2; i < count; ++i)// loop starts from 2 because 0 and 1 are already printed
        {
            n3 = n1 + n2;
            System.out.println(" " + n3);
            n1 = n2;
            n2 = n3;
        }
    }

    static int armstrong(int num) {
        int x, a = 0;
        while (num != 0) {
            x = num % 10;
            a = a + (x * x * x);
            num /= 10;
        }
        return a;
    }

    void armcalling() throws IOException // Call this method in main
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter two number to generate armstrong number between them");
        int w = Integer.parseInt(br.readLine());
        int z = Integer.parseInt(br.readLine());
        int i = w, arm;
        System.out.println("Armstrong numbers between " + w + " to " + z + " are");
        while (i < z) {
            arm = armstrong(i);
            if (arm == i)
                System.out.println(i);
            i++;
        }
    }

    void primenumber() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the number to be checked");
        int w = Integer.parseInt(br.readLine());
        int i, m = 0, flag = 0;
        int n = w;// it is the number to be checked
        m = n / 2;
        if (n == 0 || n == 1) {
            System.out.println(n + " is not prime number");
        } else {
            for (i = 2; i <= m; i++) {
                if (n % i == 0) {
                    System.out.println(n + " is not prime number");
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                System.out.println(n + " is prime number");
            }
        }
    }

    void factorial() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the number to calculate factorial");
        int s = Integer.parseInt(br.readLine());
        int i, fact = 1;
        int number = s;// It is the number to calculate factorial
        for (i = 1; i <= number; i++) {
            fact = fact * i;
        }
        System.out.println("Factorial of " + number + " is: " + fact);
    }

    void reverse() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the number to be reverse");
        int z = Integer.parseInt(br.readLine());
        int number = z, reverse = 0;
        while (number != 0) {
            int remainder = number % 10;
            reverse = reverse * 10 + remainder;
            number = number / 10;
        }
        System.out.println("The reverse of the given number is: " + reverse);
    }

    public static void main(String[] args) throws IOException {
        abc ob = new abc();
        while (true) {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.println(" 1) Fibonacci Number");
            System.out.println(" 2) Armstrong Number");
            System.out.println(" 3) Prime Number ");
            System.out.println(" 4) Factorial");
            System.out.println(" 5) Reverse");

            int ch = Integer.parseInt(br.readLine());
            switch (ch) {
                case 1:
                    ob.fiboacci();
                    break;

                case 2:
                    ob.armcalling();
                    break;
                case 3:
                    ob.primenumber();
                    break;
                case 4:
                    ob.factorial();
                    break;

                case 5:
                    ob.reverse();
                    break;

                default:
                    System.out.println("Wrong choice");
            }
        }

    }
}