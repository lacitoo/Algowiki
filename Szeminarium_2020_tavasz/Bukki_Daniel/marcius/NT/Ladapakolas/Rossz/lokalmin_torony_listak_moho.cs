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

            List<int>[] piles = new List<int>[sizes.Length];
            int[] heights = new int[sizes.Length];
            for (int i = 0; i < sizes.Length; ++i)
            {
                piles[i] = new List<int>() { sizes[i] };
                heights[i] = sizes[i];
            }

            int freed = 0;
            bool again = true;
            while (again)
            {
                again = false;
                freed = 0;
                for (int i = 0; i < piles.Length; ++i)
                {
                    if (piles[i] != null)
                    {
                        int l = i - 1;
                        int r = i + 1;
                        bool leftexists = l >= 0 && piles[l] != null;
                        bool rightexists = r < piles.Length && piles[r] != null;
                        bool fitsleft = leftexists && piles[i][0] < piles[l][piles[l].Count - 1] && heights[i] + heights[l] <= hlimit;
                        bool fitsright = rightexists && piles[i][0] < piles[r][piles[r].Count - 1] && heights[i] + heights[r] <= hlimit;
                        if (fitsleft)
                        {
                            if (fitsright || !rightexists)
                            {
                                piles[l].AddRange(piles[i]);
                                piles[i] = null;
                                heights[l] += heights[i];
                                heights[i] = 0;
                                again = true;
                            }
                        }
                        else
                        {
                            if (fitsright)
                            {
                                piles[r].AddRange(piles[i]);
                                piles[i] = null;
                                heights[r] += heights[i];
                                heights[i] = 0;
                                again = true;
                            }
                        }
                    }
                    else ++freed;
                }
            }
            Console.WriteLine(freed);
        }
    }
}
