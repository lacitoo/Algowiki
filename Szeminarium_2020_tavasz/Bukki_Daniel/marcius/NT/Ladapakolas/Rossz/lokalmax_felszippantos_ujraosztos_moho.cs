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
            int hlimit = options[1];

            int freed = 0;
            int last = sizes.Length - 1;
            bool again = true;
            while (again)
            {
                again = false;
                for (int i = 0; i < sizes.Length; ++i)
                {
                    if (sizes[i] != 0 && (i == 0 || sizes[i] >= sizes[i - 1]) && (i == last || sizes[i] >= sizes[i + 1]))
                    {
                        List<int> pile = new List<int>();
                        int height = sizes[i];
                        pile.Add(sizes[i]);

                        int left = sizes[i];
                        for (int l = i - 1; l >= 0 && sizes[l] != 0; --l)
                        {
                            if (sizes[l] < left && !pile.Contains(sizes[l]))
                            {
                                pile.Add(sizes[l]);
                                height += sizes[l];
                                left = sizes[l];
                                sizes[l] = 0;
                            }
                            else break;
                        }

                        int right = sizes[i];
                        for (int r = i + 1; r < sizes.Length && sizes[r] != 0; ++r)
                        {
                            if (sizes[r] < right && !pile.Contains(sizes[r]))
                            {
                                pile.Add(sizes[r]);
                                height += sizes[r];
                                right = sizes[r];
                                sizes[r] = 0;
                            }
                            else break;
                        }

                        sizes[i] = 0;
                        int rem;
                        int count = Math.DivRem(pile.Count, hlimit, out rem);
                        if (rem != 0)
                            ++count;
                        freed += pile.Count - count;
                        again = true;
                    }
                }
            }
            Console.WriteLine(freed);
        }
    }
}
