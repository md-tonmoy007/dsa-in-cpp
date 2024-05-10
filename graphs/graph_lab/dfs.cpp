#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
const int READY = 1;
const int WAITING = 2;
const int PROCESSED = 3;

class Node
{
public:
    char value;
    Node *next;
    Node(char v) : value(v), next(nullptr) {}
};

class Graph
{
private:
    unordered_map<char, Node *> adjacency_list;
    unordered_map<char, int> node_status;

public:
    void add_edge(char from_node, char to_node)
    {
        if (adjacency_list.find(from_node) == adjacency_list.end())
        {
            adjacency_list[from_node] = new Node(to_node);
        }
        else
        {
            Node *current = adjacency_list[from_node];
            while (current->next)
            {
                current = current->next;
            }
            current->next = new Node(to_node);
        }

        node_status[from_node] = READY;
        node_status[to_node] = READY;
    }

    void dfs(char start_node)
    {
        stack<char> q;

        for (auto &pair : node_status)
        {
            pair.second = READY;
        }

        q.push(start_node);
        node_status[start_node] = WAITING;

        while (!q.empty())
        {
            char current_node = q.top();
            q.pop();
            cout << current_node << " ";

            node_status[current_node] = PROCESSED;

            Node *neighbor = adjacency_list[current_node];
            while (neighbor)
            {
                if (node_status[neighbor->value] == READY)
                {
                    q.push(neighbor->value);
                    node_status[neighbor->value] = WAITING;
                }
                neighbor = neighbor->next;
            }
        }
        for (auto it = node_status.begin(); it != node_status.end(); ++it)
        {

            if (it->second == READY)
            {
                q.push(it->first);
                node_status[it->first] = WAITING;
                while (!q.empty())
                {
                    char current_node = q.top();
                    q.pop();
                    cout << current_node << " ";

                    node_status[current_node] = PROCESSED;

                    Node *neighbor = adjacency_list[current_node];
                    while (neighbor)
                    {
                        if (node_status[neighbor->value] == READY)
                        {
                            q.push(neighbor->value);
                            node_status[neighbor->value] = WAITING;
                        }
                        neighbor = neighbor->next;
                    }
                }
            }
        }
    }
};

int main()
{
    Graph graph;
    graph.add_edge('A', 'B');
    graph.add_edge('A', 'C');
    graph.add_edge('B', 'C');
    graph.add_edge('D', 'C');
    graph.add_edge('D', 'E');
    graph.add_edge('A', 'D');
    graph.add_edge('E', 'C');

    cout << "DFS Traversal starting from the given node: ";
    graph.dfs('C');
    cout << endl;

    return 0;
}
