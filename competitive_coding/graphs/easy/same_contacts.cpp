//https://www.geeksforgeeks.org/find-same-contacts-in-a-list-of-contacts/
#include <iostream>
#include <vector> 
#include <unordered_map>


using namespace std;

#define V 4


class Contact
{	
public:
	string phoneNumber;
	string email;
	string userName;

	Contact(string phoneNumber, string email, string userName) {

		this -> phoneNumber = phoneNumber;
		this -> email = email;
		this -> userName = userName;

	}
	
};

int adj[V][V];
unordered_map<int, vector<int> > map;

void addEdge (int u, int v) {
	adj[u][v] = 1;
	adj[v][u] = 1;
}

// O(V)
void constructTree (vector<Contact> contacts) {
	for (int i = 0; i < V ;i++) {
		for (int j = i+1 ; j < V ; j++) {
			if (contacts[j].phoneNumber == contacts[i].phoneNumber 
				|| contacts[j].email == contacts[i].email
				|| contacts[j].userName == contacts[i].userName
				) {
				addEdge (i,j);
			}
		}
	}
}

// O(V + E)
void DFSUtil (int key, int c, vector<bool> &visited) {
	visited[key] = true;
	map[c].push_back (key);

	for (int i = 0 ; i < V ; i++) {
		if (!visited[i] && adj[key][i]) {
			DFSUtil (i, c, visited);
		}
	}
}

// O(V + E)
void findSameContacts (vector<Contact> contacts) {

	constructTree (contacts);
	vector<bool> visited (V, false);
	int c = 1;
	for (int i = 0; i < V ; i++) {
		if (!visited[i]) {
			vector<int> result;
			map.insert({c, result});
			DFSUtil (i, c, visited);
			c++;
		}
	}

	// O(V)
	for (int i = 0; i < map.size () ; i++) {
		for (int j = 0 ; j < map[i].size () ; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

}

int main () {
	vector<Contact> contacts;
	contacts.push_back (Contact ("Gaurav", "gaurav@gmail.com", "gaurav@gfgQA.com"));
	contacts.push_back (Contact ("Lucky", "lucky@gmail.com", "+1234567"));
	contacts.push_back (Contact ("gaurav123", "+5412312", "gaurav123@skype.com"));
	contacts.push_back (Contact ("gaurav1993", "+5412312", "gaurav@gfgQA.com"));

    findSameContacts (contacts);
}