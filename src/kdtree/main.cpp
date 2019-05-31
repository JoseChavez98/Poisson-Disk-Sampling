#include <iostream>
#include "kdtree.h"
#include <unistd.h>
#include <python3.5m/Python.h>
#include <string>

using namespace std;


int main(int argc, char **argv)
{
	string fileName(argv[1]);
	KdTree<int> tree;
	tree.load(fileName);
	tree.build();
	tree.print();	
	tree.write();
	string cmd = "python3 draw.py " + fileName;
	system(cmd.c_str());

	string line;
	
	while(true)
	{
		vector<int> user_point;

		stringstream sstream;
		cout << "Find nearest neighbor of point: ";
		getline(cin,line);
		sstream << line;
		string cmd = "python3 draw.py " + fileName;
		int inputPos, i = 0;
		while(sstream >> inputPos)
		{
			user_point.push_back(inputPos);
			cmd += " " + to_string(user_point[i++]);
		}

		if(user_point.size() < tree.k)
			cout << "ERROR: too few point coordinates. Insert new coordinates (k="<<tree.k<<")"<<endl;
		

		else if(user_point.size() > tree.k)
			cout << "ERROR: too many point coordinates. Insert new coordinates (k="<<tree.k<<")"<<endl;
		
		else
		{
			//find nearest point
			system(cmd.c_str());
		}

	}
	
/*	
	Node<int>* ptrNode =new Node<int>({3,5});
	Node<int>* ptrNode1 =new Node<int>({2,6});
	Node<int>* ptrNode2 =new Node<int>({1,7});
	Node<int>* ptrNode3 =new Node<int>({8,9});
	Node<int>* ptrNode4 =new Node<int>({9,10});
	Node<int>* ptrNode5 =new Node<int>({1,2});

	cout << endl;
	MinHeap<Node<int>*> minheap(6);
	minheap.insert(ptrNode);
	minheap.insert(ptrNode1);
	minheap.insert(ptrNode2);
	minheap.insert(ptrNode3);
	minheap.insert(ptrNode4);
	minheap.insert(ptrNode5);
	minheap.print();
	cout<< endl;

	cout << endl;
	MaxHeap<Node<int>*> maxheap(6);
	maxheap.insert(ptrNode);
	maxheap.insert(ptrNode1);
	maxheap.insert(ptrNode2);
	maxheap.insert(ptrNode3);
	maxheap.insert(ptrNode4);
	maxheap.insert(ptrNode5);
	maxheap.print();
	cout<< endl;

	cout << endl;
	MedianHeap<Node<int>*> medheap(6);
	medheap.insert(ptrNode);
	medheap.insert(ptrNode1);
	medheap.insert(ptrNode2);
	medheap.insert(ptrNode3);
	medheap.insert(ptrNode4);
	medheap.insert(ptrNode5);
	medheap.print();
	cout<< endl;
*/

}