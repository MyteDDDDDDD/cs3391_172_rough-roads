# include <iostream>
# include <queue>

using namespace std;


int cal(int *a[], int j) {	//Dijkstra’s algorithm
	int *d;
	d = new int[j];//distance from source to certain junctions
	int *p;
	p = new int[j];// for the nodes on th shortest path from 0 junctions to n-1 junction, p[n] is its parent node 
	

	for (int i = 0; i < j; i++) {
		d[i] = 20 * j;//initial all d to 20*j ( go through all roads and each road with maximum length)
		d[0] = 0;
	}
	
	int count = 0;
	while (count<j) {
		for (int i = 0;i < j;i++) { // the road whose source is count-th junction and destination is i-th junction
			if (a[count][i]>1) {// there is the road whose destination junction is the count-th junction
		
					if (d[i] > d[count] + a[count][i]) {
						d[i] = d[count] + a[count][i];
						p[i] = count;
					
				}
				
			}	
		}
		count++;
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

		int **roads = new int*[j];// a j*j matrix stors all roads;
		for (int i = 0; i < j; i++) {
			roads[i] = new int[j];
		}

		int tempa, tempb, templ;
		for (int i = 0; i < r; i++) {
			cin >> tempa >> tempb >> templ;
			roads[tempa][tempb] = templ;
			roads[tempb][tempa] = templ;
		}
		c.push(cal(roads, j));
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
