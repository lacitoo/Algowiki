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
            Console.WriteLine(Math.Floor(Math.Sqrt(1 + 2 * Math.Min(n, m))));
        }
    }
}
