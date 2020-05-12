using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ELTE_Gyakorlas
{
    public class Program
    {
        public static void Main()
        {
            string line = Console.ReadLine();
            int index = line.IndexOf(' ');
            int n = int.Parse(line.Substring(0, index));
            int m = int.Parse(line.Substring(index + 1));
            int min = Math.Min(n, m);
            int sum = n + m;

            long l = 1;
            while (true)
            {
                long L = l * l;
                if (L > sum || L / 2 > min) break;
                ++l;
            }
            Console.WriteLine(l - 1);
        }
    }
}
