using System;
using System.Collections.Generic;

namespace ELTE_CSharp
{
    public class Program
    {
        private class Node
        {
            public Node Parent;
            public LinkedList<Node> Nodes;
            public int MaxDepth;
            public int Level;


            public Node()
            {
                Parent = null;
                Nodes = new LinkedList<Node>();
                MaxDepth = 0;
                Level = 0;
            }
        }


        static void Main(string[] args)
        {
            int n, x;
            ReadInts(out n, out x);
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; ++i)
                nodes[i] = new Node();
            for (int i = 1; i < n; ++i)
            {
                int l, r;
                ReadInts(out l, out r);
                --l;
                --r;
                nodes[l].Nodes.AddLast(nodes[r]);
                nodes[r].Nodes.AddLast(nodes[l]);
            }
            Traverse(nodes[0]);

            Node curnode = nodes[x - 1];
            int level = curnode.Level;
            int ascend = (level & 1) == 1 ? (level >> 1) : ((level >> 1) - 1);
            for (int l = 0; l < ascend; ++l)
                curnode = curnode.Parent;

            Console.WriteLine((curnode.MaxDepth + level - ascend) << 1);
        }

        private static void Traverse(Node root)
        {
            LinkedList<Node> q = new LinkedList<Node>();
            q.AddLast(root);
            while (q.Count != 0)
            {
                Node n = q.First.Value;
                q.RemoveFirst();

                bool leaf = true;
                int clev = n.Level + 1;
                foreach (Node node in n.Nodes)
                {
                    if (node != n.Parent)
                    {
                        node.Parent = n;
                        node.Level = clev;
                        leaf = false;
                        q.AddLast(node);
                    }
                }
                if (leaf)
                {
                    n.MaxDepth = 0;
                    Node p = n;
                    while (p.Parent != null)
                    {
                        int depth = p.MaxDepth + 1;
                        if (depth > p.Parent.MaxDepth)
                        {
                            p.Parent.MaxDepth = depth;
                            p = p.Parent;
                        }
                        else break;
                    }
                }
            }

            /*int max = -1;
            int clev = n.Level + 1;
            foreach (Node node in n.Nodes)
            {
                if (node != n.Parent)
                {
                    node.Parent = n;
                    node.Level = clev;
                    Traverse(node);
                    if (node.MaxDepth > max)
                        max = node.MaxDepth;
                }
            }
            n.MaxDepth = max + 1;*/
        }

        private static void ReadInts(out int a, out int b)
        {
            string s = Console.ReadLine();
            int index = s.IndexOf(' ');
            a = int.Parse(s.Substring(0, index));
            b = int.Parse(s.Substring(index + 1));
        }
    }
}
