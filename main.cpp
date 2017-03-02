# include <iostream>
# include <queue>

using namespace std;

int cal(int *a[],int j) {	//Dijkstra’s algorithm
	int *d;
	d = new int[j];//distance from source to certain junctions
	bool *q;
	q = new bool[j]; 

	for (int i = 0; i < j; i++) {//initial
		d[i] = 20 * j;
		q[i] = false;
	}
	int parent = 0;
	int count=0;
	
	while (q[count] != true) {

	}

	return d[j - 1];
}

int main() {
	queue<int> c;// store the records of cases;
	int j;// junctions number;
	int r;// roads number;

	cin >> j;
	while (!cin.eof()) {
		cin >> r;

		int **roads=new int*[j];// a j*j matrix stors all roads;
		for (int i = 0; i < j; i++) {
			roads[i] = new int[j];
		}
		
		int tempa, tempb,templ;
		for (int i = 0; i < r; i++) {
			cin >> tempa >> tempb >> templ;
			roads[tempa][tempb] = templ;
			roads[tempb][tempa] = templ;
		}
		c.push(cal(roads,j));
		cin >> j;
	}

	int count = 1;// count set number;
	while (!c.empty()) {//print result
		cout << "Set #" << count << endl;
		cout << c.front() << endl;
		c.pop();
		count++;
	}
	return 0;
}
