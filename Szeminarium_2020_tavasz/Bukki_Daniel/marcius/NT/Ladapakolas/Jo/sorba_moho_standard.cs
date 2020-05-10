using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ELTE_Gyakorlas
{
    public class Program
    {
        private static int[] ReadInts(string s, int n)
        {
            int index = 0;
            int i = 0;
            int[] values = new int[n];
            while (true)
            {
                int next = s.IndexOf(' ', index);
                if (next == -1)
                {
                    values[i] = int.Parse(s.Substring(index));
                    break;
                }
                else
                {
                    values[i++] = int.Parse(s.Substring(index, next - index));
                    index = next + 1;
                }
            }
            return values;
        }

        public static void Main()
        {
            int[] options = ReadInts(Console.ReadLine(), 2);
            int[] sizes = ReadInts(Console.ReadLine(), options[0]);// iterates over all 1 000 000 sizes one more time than needed

            int freed = 0;
            List<int> p = new List<int>();
            int last = sizes[0];
            int height = last;
            p.Add(last);
            bool increasing = true;
            for (int i = 1; i < sizes.Length; ++i)
            {
                bool inc = last < sizes[i];
                int h = height + sizes[i];
                if (sizes[i] != last && (increasing || !inc) && (!p.Contains(sizes[i]) && h <= options[1]))
                {
                    p.Add(sizes[i]);
                    height = h;
                    ++freed;
                    increasing = inc;
                }
                else
                {
                    p.Clear();
                    p.Add(sizes[i]);
                    height = sizes[i];
                    increasing = true;
                }
                last = sizes[i];
            }
            Console.WriteLine(freed);
        }
    }
}
