#pragma once
#include "ring_queue.h"
#include <cstddef>
#include <array>
#include <optional>


namespace tree
{
    template <typename T>
    class Node
    {
        public:
        Node<T> *lChild;
        Node<T> *rChild;
        T value;
    };

    template <typename T>
    class BinaryTree
    {
        public:
            BinaryTree();
            ~BinaryTree();
            template <size_t N> 
            void createTree(const std::array<std::optional<T>, N> &a);
            std::vector<T> preOrder(Node<T> *root);
            std::vector<T> postOrder(Node<T>* root);
            std::vector<T> inOrder(Node<T>* root);
            void levelOrder(Node<T>* root);
            void Height(Node<T> *root);

        private:
            Node<T> *root;
            void destroy(Node<T> *node);
            void preOrderHelper(Node<T> *node, std::vector<T> &v);
            void postOrderHelper(Node<T> *node, std::vector<T> &v);
            void inOrderHelper(Node<T> *node, std::vector<T> &v);
    };

    template <typename T>
    BinaryTree<T>::BinaryTree() : root(nullptr) {}

    template <typename T>
    BinaryTree<T>::~BinaryTree()
    {
        destroy(root);
    }

    template <typename T>
    void BinaryTree<T>::destroy(Node<T> *node)
    {
        if (!node) return;

        destroy(node->lChild);
        destroy(node->rChild);
        delete node;
    }

    template <typename T>
    template <size_t N> 
    void BinaryTree<T>::createTree(const std::array<std::optional<T>, N> &a)
    {
        // Temporary pointers p - for current Node, t - for creating child node
        Node<T> *p, *t;
        T value;
        size_t idx = 0;

        // if first values is -1 - no root return error
        if (!a[idx++].has_value())
            return;

        // create queue of pointers to nodes
        Queue<Node<T>*> q(N);

        // allocate root node
        root = new Node<T>;
        root->value = *a[0];
        root->lChild = nullptr;
        root->rChild = nullptr;

        // store root node address
        q.enqueue(root);

        while(!q.isEmpty() && idx < N)
        {
            // get node (parent)
            q.dequeue(p);

            if (a[idx].has_value()) // a is std::optional<T>. value by dereference "*", reading if value does not exist is UB
            {
                // to do: change to move it will be faster!
                t = new Node<T>;
                t->lChild = nullptr;
                t->rChild = nullptr;
                t->value = *a[idx++];

                // assign new Node to lef child of parent.
                p->lChild = t;
                q.enqueue(t);
            }
            else
                idx++;

            if (a[idx].has_value())
            {
                // to do: change to move it will be faster!
                t = new Node<T>;
                t->lChild = nullptr;
                t->rChild = nullptr;
                t->value = *a[idx++];
                
                // assign new Node to lef child of parent.
                p->rChild = t;
                q.enqueue(t);
            }
            else
                idx++;
        }

        
    }

    template <typename T>
    std::vector<T> BinaryTree<T>::preOrder(Node<T> *root)
    {
        std::vector<T> v;
        preOrderHelper(root, v);
        return v;
    }

    template <typename T>
    void BinaryTree<T>::preOrderHelper(Node<T> *node, std::vector<T> &v)
    {
        if (!node) return;
        v.push_back(node->value);
        preOrderHelper(node->lChild, v);
        preOrderHelper(node->rChild, v);

    }

    template <typename T>
    std::vector<T> BinaryTree<T>::postOrder(Node<T>* root)
    {
        std::vector<T> v;
        postOrderHelper(root, v);
        return v;
    }

    template <typename T>
    void BinaryTree<T>::postOrderHelper(Node<T> *node, std::vector<T> &v)
    {
        if (!node) return;
        
        postOrderHelper(node->lChild, v);
        postOrderHelper(node->rChild, v);
        v.push_back(node->value);

    }

    template <typename T>
    std::vector<T> BinaryTree<T>::inOrder(Node<T>* root)
    {
        std::vector<T> v;
        inOrderHelper(root, v);
        return v;
    }

    template <typename T>
    void BinaryTree<T>::inOrderHelper(Node<T> *node, std::vector<T> &v)
    {
        if (!node) return;
        
        inOrderHelper(node->lChild, v);
        v.push_back(node->value);
        inOrderHelper(node->rChild, v);
    }
}



