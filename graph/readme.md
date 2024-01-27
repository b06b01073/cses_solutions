# Writeup

Solutions to some of the hard problems.

## [Flight discount](https://cses.fi/problemset/task/1195)

Use Dijstra to solve two single source shortest path problems, one start from node `1` the other start from node `n`. Let's say `src[i]` is the shortest path from `1` to node `i` and `dst[i]` is the shortest path from `n` to node `i`.

We next iterate all edges $E$, for each edge $e$ the weight is denoted by $w_e$ and the end points connected by the edge are from $A_e$ to $B_e$.

Then, the answer is 

$$
min_{\{e \in E\}} \ src[A_e] + dst[B_e] + \frac{w_e}{2}.
$$

## [Flight routes check](https://cses.fi/problemset/task/1682/)
Quite an interesting question. It can be solved by Kosaraju's algorihtm, but it's an overkill, since we only need to know whether the graph is a **single** strongly connected component. We can use an interesting property, that is, **if every node can reach node $1$ and node $1$ can reach every other nodes, then the graph is strongly connected**. This can be proved with ease, given two vertices $v, u \in G$, we can always travel from $u$ to $v$ by first travel from $u$ to $1$, then from $1$ to $v$, therefore, $G$ is strongly connected.

Here, we only show that the condition is sufficient. The neccessity of the condition can also be proved easily. That is, we want to show that **if the graph is strongly connected, then every node can reach node $1$ and node $1$ can reach every other nodes**. This statement is automatically true by the definition of a strongly connected component. Therefore, the two conditions are equivalent.


#### Note: How to find whether every other nodes can reach node $1$?
reverse the graph and run dfs start from node $1$.


## [Cycle Finding](https://cses.fi/problemset/task/1197/)

Read the [post](https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html).

In the problem, the graph may contains multiple components. We can solve this problem by

1. Run Bellman-Ford algorithm on each components.
1. Add a pseudo node $0$ that connects to all the existing node with weight $0$. Adding a pseudo node does not make the negative cycle disappear or appear. However, adding this node makes things much more easier, we can simpoly run Bellman-Ford algorithm by treating $0$ as our starting point.

and we use approach 2 in this problem by setting the distance from node $0$ to other nodes to $0$ at line 25.

In the last iteration of Bellman-Ford algorithm (iteration $n$), we record **a** node that is in the negative cycle. Now, we simply visit the parents iteratively to find the cycle.


## [Coin Collector](https://cses.fi/problemset/task/1686)

SCC + DP. It turns out that after SCC, there's no need to perform topological sort before dynamic programming, since the sequence of the SCCs are in topo sequence already.
