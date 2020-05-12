using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace suits
{
    class Program
    {
        static void Main(string[] args)
        {
            int a, b, c, d, e, f;
 
            a = Convert.ToInt32(Console.ReadLine());
            b = Convert.ToInt32(Console.ReadLine());
            c = Convert.ToInt32(Console.ReadLine());
            d = Convert.ToInt32(Console.ReadLine());
            e = Convert.ToInt32(Console.ReadLine());
            f = Convert.ToInt32(Console.ReadLine());
 
            int m = Math.Min(b, Math.Min(c, d));
            int all = m * f + e * Math.Min(a, d - m);
 
            int x = Math.Min(a, d);
            int y = x * e + f * Math.Min(b, Math.Min(c, d - x));
 
            int vegleges = Math.Max(y, all);
 
            Console.WriteLine(vegleges);
        }
    }
}