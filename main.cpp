
// Example for Breadth First Search and Depth First Search

#include <iostream>
#include <map>
#include <set>
#include <list>

using namespace std;

class Tree
{
public:
	std::map< int, std::set<int> >	elem_conn;
	std::map< int, bool >   visited;  //  Let's always use maps (instead of sets)
	std::list< int >			to_visit;
	std::map< int, bool >	inserted;
	int							tree_size;


	Tree() {
		cout<<"\nTree initialized\n";
		tree_size = 0;
	};

	void  add_edge(int ori, int tgt) {
		elem_conn[ori].insert(tgt);
		cout<<"Added connection: "<< ori <<" -> "<< tgt <<"\n";
	}

	void  DSearch(int start) {  //  Depth First Search
		if (elem_conn.count(start)==0) {
			cout<<"Element "<< start <<" doesn't exist!\n";
			return;
		}
		tree_size = 0;
		visited.clear();
		recursive_search(start);
		cout<<"Number of elements: "<< tree_size <<"\n";
	}	
		
	void  recursive_search(int start) {
		if (visited.count(start)>0) {
//			cout<<"Element "<< start <<" already found...\n";
			return;
		}

		cout<<"Found element: "<< start <<"\n";
		tree_size += 1;

		visited[start] = true;
		for (auto e : elem_conn[start]) {
			recursive_search(e);
		}

	}

	void  BSearch(int start) {  //  Breadth First Search
		if (elem_conn.count(start)==0) {
			cout<<"Element "<< start <<" doesn't exist!\n";
			return;
		}
		tree_size = 0;
		visited.clear();
		to_visit.clear();
		inserted.clear();
		
		to_visit.push_back(start);
		inserted[start] = true;
		int		to_vis;

		while (to_visit.empty()==false) {
			to_vis = to_visit.front(); 
			to_visit.pop_front();
			if (visited.count(to_vis)!=0) cout<<"Already visited!\n"; 
			if (visited.count(to_vis)==0) //  Actually superflous
			{
				cout<<"Found element: "<< to_vis <<"\n";
				tree_size += 1;
				visited[to_vis] = true;
				for (auto el : elem_conn[to_vis]) {
					if (inserted.count(el)==0) {
						to_visit.push_back(el);
						inserted[el] = true;
					}
				}
			}
		}
		cout<<"Number of elements: "<< tree_size <<"\n";
	
	}

};


int main() 
{

  Tree		mytree;
  mytree.add_edge(0, 1);
  mytree.add_edge(0, 2); 
  mytree.add_edge(0, 3);
  mytree.add_edge(1, 2); 
  mytree.add_edge(2, 4);
  mytree.add_edge(3, 3); 
  mytree.add_edge(4, 4);	

	cout<<"\nDepth first search\n";
	mytree.DSearch(5);
	cout<<"\nDepth first search\n";
	mytree.DSearch(0);
	cout<<"\nBreadth first search\n";
	mytree.BSearch(0);
	
	
	Tree   T2;
	T2.add_edge(2, 1);
	T2.add_edge(2, 0);
	T2.add_edge(1, 3);
	T2.add_edge(1, 4);
	T2.add_edge(0, 5);
	T2.add_edge(0, 6);
	T2.add_edge(0, 7);
	T2.add_edge(3, 8);
	T2.add_edge(4, 9);
	T2.add_edge(5,10);
	T2.add_edge(1, 5);
	
	cout<<"\nDepth first search\n";
	T2.DSearch(2);
	cout<<"\nBreadth first search\n";
	T2.BSearch(2);
	return(0);

}
