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
                long less = 0;
                long more = 0;
                for (long y = 0; y < l; ++y)
                {
                    for (long x = 0; x < l; ++x)
                    {
                        if (x % 2 == y % 2)
                            ++more;
                        else ++less;
                    }
                }

                if (!((less <= n && more <= m) || (less <= m && more <= n))) break;
                ++l;
            }
            Console.WriteLine(l - 1);
        }
    }
}
