using System;
using System.Collections.Generic;
using System.Text;

namespace komponensek
{
    class Program
    {
        private class Node
        {
            public LinkedList<Node> Nodes;
            public bool Unvisited;


            public Node()
            {
                Nodes = new LinkedList<Node>();
                Unvisited = true;
            }
        }


        static void Main(string[] args)
        {
            int n, m;
            ReadInts(out n, out m);
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; ++i)
                nodes[i] = new Node();

            for (int i = 0; i < m; ++i)
            {
                int l, r;
                ReadInts(out l, out r);
                --l; --r;
                nodes[l].Nodes.AddLast(nodes[r]);
                nodes[r].Nodes.AddLast(nodes[l]);
            }

            LinkedList<int> roots = new LinkedList<int>();
            for (int i = 0; i < n; ++i)
            {
                if (nodes[i].Unvisited)
                {
                    roots.AddLast(i);
                    nodes[i].Unvisited = false;

                    Queue<Node> q = new Queue<Node>();
                    q.Enqueue(nodes[i]);
                    while (q.Count != 0)
                    {
                        Node node = q.Dequeue();
                        foreach (Node other in node.Nodes)
                        {
                            if (other.Unvisited)
                            {
                                other.Unvisited = false;
                                q.Enqueue(other);
                            }
                        }
                    }
                }
            }

            StringBuilder sb = new StringBuilder();
            if (roots.Count > 1)
            {
                int pivot = roots.First.Value + 1;
                roots.RemoveFirst();
                string _pivot = pivot.ToString();

                sb.Append(roots.Count);
                sb.AppendLine();
                foreach (int target in roots)
                {
                    sb.Append(_pivot);
                    sb.Append(' ');
                    sb.Append(target + 1);
                    sb.AppendLine();
                }
            }
            else sb.AppendLine("0");
            Console.WriteLine(sb.ToString());
        }

        private static void ReadInts(out int left, out int right)
        {
            string s = Console.ReadLine();
            int index = s.IndexOf(' ');
            left = int.Parse(s.Substring(0, index));
            right = int.Parse(s.Substring(index + 1));
        }
    }
}
