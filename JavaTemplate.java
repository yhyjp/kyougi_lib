import java.io.*;
import java.util.*;
import java.math.*;

class Main
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext())
		{
			int b = sc.nextInt();
			BigInteger a = sc.nextBigInteger();
			BigInteger c = BigInteger.ZERO;
			BigInteger t = a;
			for (int i = 1; i <= b; ++i)
			{
				c = c.add(t.multiply(BigInteger.valueOf(i)));
				t = t.multiply(a);
			}
			System.out.println(c);
		}
	}
}
