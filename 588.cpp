#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

struct ele {
	ele() {
		d = true;
		s = "";
		name = "";
		m.clear();
	}
	bool d;
	string name;
	string s;
	map<string, ele> m;
};

class FileSystem {
public:
	FileSystem() {
		root = ele();
	}

	vector<string> ls(string path) {
		ele cur = findEle(path, 0);
		vector<string> result;
		if (cur.d) {
			for (auto it : cur.m) {
				result.push_back(it.first);
			}
		}
		else {
			result.push_back(cur.name);
		}
		return result;
	}

	void mkdir(string path) {
		findEle(path, 1);
	}

	void addContentToFile(string filePath, string content) {
		findEle(filePath, 2).s += content;
	}

	string readContentFromFile(string filePath) {
		ele cur = findEle(filePath, 0);
		return cur.s;
	}

private:
	ele & findEle(string path, int category) {
		if (path.length() == 1) {
			return root;
		}
		else {
			vector<string> paths = split(path);
			ele * cur = &root;
			for (int i = 0; i < paths.size(); i++) {
				auto next = cur->m.find(paths[i]);
				if (next != cur->m.end()) {
					cur = &next->second;
				}
				else {
					cur->m[paths[i]] = ele();
					if (i + 1 == paths.size() && category == 2) {
						cur->m.find(paths[i])->second.d = false;
						cur->m.find(paths[i])->second.name = paths[i];
					}
					cur = &cur->m.find(paths[i])->second;
				}
			}
			return *cur;
		}
	}

	vector<string> split(string path) {
		path += '/';
		vector<string> result;
		int pos = 1;
		for (int i = 1; i < path.length(); i++) {
			if (path[i] == '/') {
				result.push_back(path.substr(pos, i - pos));
				pos = i + 1;
			}
		}
		return result;
	}

	ele root;
};

int main()
{
	FileSystem s;
	cin.get();
}
