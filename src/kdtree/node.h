#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Node {

    vector<T> position;
    int index;      //index of current comparing value
    int level;

public:
    Node* leftChild;
    Node* rightChild;

    Node(T val)
    {
        position.push_back(val);
        index = 0;
        leftChild = NULL;
        rightChild = NULL;
        level = 0;
    }

    Node(vector<T> args) 
    {
        position = args;
        index = 0;
        level = 0;
    }

    void increaseLevel()
    {
        level++;
    }

    int getLevel()
    {
        return level;
    }

    T pos(int i)
    {
        return position[i];
    }

    int getIndex()
    {
        return index;
    }

    void print()
    {
        //Format: { <level> : <position>}
        cout << "{";
        cout << level<<":";
        for(int i = 0; i < position.size();i++)
        {
            if(i!= 0)
                cout << ",";
            cout << position[i];
        }
        cout << "} ";
    }

    T comparingVal()
    {
        return position[index];
    }

    T nextComparingVal()
    {
        ++index;
        if(index == position.size()){index = 0;}
        return position[index];
    }

    bool operator < (Node<T> cmp)
    {
        return (comparingVal() < cmp.comparingVal()); 
    } 
    bool operator > (Node<T> cmp)
    {
        return (comparingVal() > cmp.comparingVal()); 
    } 

    double ecuclidiana(Node<T> *goal) {
        double answer = 0;
        for(int i = 0; i < position.size();i++)
        {
            answer += pow((goal->pos(i)) - this->pos(i),2);
        }
        return (double)sqrt(answer);
    }
};

#endif
