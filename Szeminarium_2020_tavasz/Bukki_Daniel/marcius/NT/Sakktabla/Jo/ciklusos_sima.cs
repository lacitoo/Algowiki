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

            long l = 1;
            while (true)
            {
                long L = l * l;

                long less = L / 2;
                long more = L - less;

                if (!((less <= n && more <= m) || (less <= m && more <= n))) break;
                ++l;
            }
            Console.WriteLine(l - 1);
        }
    }
}
