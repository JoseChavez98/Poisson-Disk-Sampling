#include <iostream>
#include <chrono>
#include <iomanip>
#include "kdtree.h"
#include <unistd.h>
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
		 	cout << "Insert radius: "; 
		 	getline(cin,line);
		 	int radius = stoi(line); 
		 	Node<int> *nodo = new Node<int>(user_point);
		    auto start = chrono::high_resolution_clock::now();
		    cout << "Neighbors within a radius of "<<radius <<" units: " << endl;
		    tree.buscarEnRadio(radius,nodo);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> runtime4 = end - start;
            cout << "Time taken: "<< fixed << setprecision(10) << runtime4.count() << " secs" << endl<<endl;		    
		 	system(cmd.c_str()); 
		 } 

	 } 
	
}
