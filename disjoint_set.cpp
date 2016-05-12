#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Node
{
public:
    int value;
    int rank;
    Node* parent;
    Node(int x = 0, int r = 0) : value(x), parent(this), rank(r) {}
};

Node* Find(Node* x)
{
    if(x->parent == x)
        return x->parent;
    else
    {
        x->parent = Find(x->parent);
        return x->parent;
    }
}

void Merge(Node* x, Node* y)
{
    if(x->rank < y->rank)
        x->parent = y;
    else
    {
        y->parent = x;
        if(x->rank == y->rank)
            x->rank += 1;
    }
}

void Union(Node* x, Node* y)
{
    if(x->parent != y->parent)
        Merge(x->parent, y->parent);
}

int main(int argc, char ** argv)
{
    unsigned int T;
    cin >> T;
    vector<vector<char> > M;
    vector<Node> L(T);

    for(int i = 0; i < T; i++)
    {
        L[i].value = i;
    }

    for(int i = 0; i < T; i++)
    {
        vector<char> tmp;
        for(int j = 0; j < T; j++)
        {
            char c;
            cin >> c;
            tmp.push_back(c);
        }
        M.push_back(tmp);
    }

    for(int i = 0; i < T; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(M[i][j] == 'Y')
                Union(&L[i], &L[j]);
        }
    }

    /*
    for(int i = 0; i < T; i++)
    {
        cout << L[i].parent << " ";
    }
    cout << endl;
    */

    set<Node*> S;
    for(int i = 0; i < T; i++)
    {
        S.insert(L[i].parent);
    }
    cout << S.size() << endl;
    return 0;
}
