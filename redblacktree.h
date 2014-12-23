#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

template <class K, class V>
class RedBlackTree
{
    struct node {
        K key;
        V value;
        bool color;
        node *left, *right;
    };
    node root;

    node rotateLeft(node n);
    node rotateRight(node n);
    void flipColor(node n);

public:
    RedBlackTree();
    ~RedBlackTree();
    void add(K key, V val);
    V find(K key);
    void remove(K key);
};

#endif // REDBLACKTREE_H
