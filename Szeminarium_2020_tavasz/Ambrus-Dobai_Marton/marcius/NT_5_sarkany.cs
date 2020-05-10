using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace sarkany01
{
    class Program
    {
        static double answer(double a, double b, double n)
        {
            double ans = -1;
            if (n < 17 && a<100001 && b<100001)
            {
                double c = Math.Pow(10, n);
                if (a * b > c)
                {
                    for (double i = Math.Pow(10, n - 1); i < c && ans == -1; ++i)
                    {
                        if (i % a == 0 && i % b == 0) { ans = i; }
                    }
                }
                else
                {
                    double i = Math.Pow(10, n - 1);
                    double j = a * b;
                    while (j < i)
                    {
                        j = j * 10;
                    }
                    ans = j;
                }
            }
            return ans;
        }

        static long number(long a)
        {
            long i = 0;
            while (a > 0)
            {
                ++i;
                a /= 10;
            }
            return i;
        }

        static long lowest_common(long a, long b)
        {
            long x = a, y = b;
            long[] al = new long[a + 1];
            long[] bl = new long[b + 1];
            //Console.WriteLine(a+" primjei:");
            long i = 2;
            while (i <= a)
            {
                if (a % i == 0)
                {
                    a /= i;
                    ++al[i];
                    //Console.Write(i + "*");
                }
                else
                {
                    i++;
                }
            }
            //Console.WriteLine();
            //Console.WriteLine(b + " primjei:");
            i = 2;
            while (i <= b)
            {
                if (b % i == 0)
                {
                    b /= i;
                    ++bl[i];
                   // Console.Write(i + "*");
                }
                else
                {
                    i++;
                }
            }
            //Console.WriteLine();
            long ret = 1;
            long max = (x<y?y:x);
            //Console.WriteLine("ret = ");
            for (long k = 2; k <= max; k++)
            {
                long mmax;
                if (k > x)
                {
                     mmax = bl[k];
                }
                else if (k > y)
                {
                     mmax = al[k];
                }
                else
                {
                     mmax = (al[k] < bl[k] ? bl[k] : al[k]);
                }

                for(long j = 0; j < mmax; ++j)
                {
                    ret = ret * k;
                    //Console.Write(k+ "*");
                }
            }
            //Console.WriteLine();
            return ret;
        }

        static void answer2(long a, long b, long n)
        {
            long c = a * b;
            long num = number(c);
            if (num == n)
            {
                Console.WriteLine(c);
            }
            else if (num < n)
            {
                Console.Write(c);
                for(long i =0; i < (n - num); ++i)
                {
                    Console.Write(0);
                }
                Console.WriteLine();
            }
            else
            {
                long lc = lowest_common( a,  b);
                num = number(lc);
                if (num > n)
                {
                    Console.WriteLine(-1);
                }
                else
                {
                    Console.Write(lc);
                    for (long i = 0; i < (n - num); ++i)
                    {
                        Console.Write(0);
                    }
                    Console.WriteLine();
                }
            }
        }

        static void Main(string[] args)
        {
            //double a, b, n;
            long al, bl, nl;
            string[] s = Console.ReadLine().Split(' ');
            /*a = double.Parse(s[0]);
            b = double.Parse(s[1]);
            n = double.Parse(s[2]);
            Console.WriteLine(answer(a,b,n));*/
            al = long.Parse(s[0]);
            bl = long.Parse(s[1]);
            nl = long.Parse(s[2]);
            //Console.WriteLine(lowest_common(al,bl));
            answer2(al, bl, nl);

            s = Console.ReadLine().Split(' ');
            /*a = double.Parse(s[0]);
            b = double.Parse(s[1]);
            n = double.Parse(s[2]);
            Console.WriteLine(answer(a, b, n));*/
            al = long.Parse(s[0]);
            bl = long.Parse(s[1]);
            nl = long.Parse(s[2]);
            //Console.WriteLine(lowest_common(al, bl));
            answer2(al, bl, nl);

            s = Console.ReadLine().Split(' ');
            /*a = double.Parse(s[0]);
            b = double.Parse(s[1]);
            n = double.Parse(s[2]);
            Console.WriteLine(answer(a, b, n));*/
            al = long.Parse(s[0]);
            bl = long.Parse(s[1]);
            nl = long.Parse(s[2]);
            //Console.WriteLine(lowest_common(al, bl));
            answer2(al, bl, nl);

            Console.ReadLine();
        }
    }
}
//1.bead 15/55  mohó n-jegyün végig limitekkel double-ban számolva
//2.bead 3/55   előző + a*b jó-e
//3.bead 21/55  előző hiba kijavítással
//4.bead 0/55   hibás
//5.bead 37/55  a*b és utána megfelelő számú nulla
//6.bead 55/55 ha a*b nem jó akkor legkissebb közös többszörös