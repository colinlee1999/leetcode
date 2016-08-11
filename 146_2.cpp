#include "iostream"
#include <vector>
#include <unordered_map>
#include <algorithm>
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)
using namespace std;

class LRUCache {
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
		heap_element h(0, 0);
		heap.push_back(h);
		global_time = 0;
	}

	int get(int key) {
		//cout << key << "++++++++++" << endl;
		//for (auto it : heap)
		//	cout << it.key << "\t" << it.times << endl;
		auto mit = m.find(key);
		if (mit == m.end()) return -1;
		else
		{
			heap[mit->second.pos].times = global_time++;
			heap_filter_down(mit->second.pos);
			return mit->second.value;
		}		
	}

	void set(int key, int value) {
		int result = get(key);
		if (result == -1)
		{
			if ((int)heap.size() - 1 == capacity)
				heap_remove_first();
			heap_insert(key, value);
		}
		else
			m[key].value = value;
	}

private:
	void heap_remove_first()
	{
		heap_swap(1, (int)heap.size() - 1);
		m.erase(heap.back().key);
		heap.pop_back();
		heap_filter_down(1);
	}

	void heap_insert(	int key,
		int value)
	{
		heap_element h(global_time++, key);
		heap.push_back(h);
		node n(value, (int)heap.size() - 1);
		m.insert(pair<int, node>(key, n));
		//heap_filter_up((int)heap.size() - 1);
	}

	//void heap_filter_up(int cur)
	//{
	//	while (cur > 1)
	//	{
	//		if (heap[cur / 2].times <= heap[cur].times) break;
	//		heap_swap(cur / 2, cur);
	//		cur /= 2;
	//	}
	//}

	void heap_filter_down(int cur)
	{
		while (cur + cur <= (int)heap.size() - 1)
		{
			int next = cur + cur;
			if (next + 1 <= (int)heap.size() - 1 && heap[next + 1].times < heap[next].times)
				next = next + 1;
			if (heap[next].times >= heap[cur].times) break;
			heap_swap(cur, next);
			cur = next;
		}
	}

	void heap_swap(int p1, int p2)
	{
		int k1 = heap[p1].key;
		int k2 = heap[p2].key;
		m[k1].pos = p2;
		m[k2].pos = p1;
		heap_element temp = heap[p1];
		heap[p1] = heap[p2];
		heap[p2] = temp;
	}

	struct node
	{
		node()
		{}

		node(int value, int pos)
		{
			this->value = value;
			this->pos = pos;
		}

		int value;
		int pos;
	};

	struct heap_element
	{
		heap_element(int times, int key)
		{
			this->times = times;
			this->key = key;
		}

		int times;
		int key;
	};

	vector<heap_element> heap; // small heap
	unordered_map<int, node> m;
	int capacity;
	int global_time;
};

int main()
{
	LRUCache l(2);
	l.set(2, 1);
	l.set(2, 2);
	cout << l.get(2) << endl;
	l.set(1, 1);
	l.set(4, 1);
	cout << l.get(2) << endl;
	//LRUCache l(4);
	//cout << l.get(1) << endl;
	//cout << l.get(2) << endl;
	//l.set(2, 2);
	//l.set(3, 3);
	//l.set(4, 4);
	//l.set(5, 5);
	//cout << l.get(2) << endl;
	//cout << l.get(3) << endl;
	//cout << l.get(4) << endl;
	//l.set(6, 6);
	//cout << l.get(2) << endl;
	//cout << l.get(3) << endl;
	//cout << l.get(4) << endl;
	//cout << l.get(5) << endl;
	//cout << l.get(6) << endl;
	//l.set(2, 10);
	//cout << l.get(2) << endl;
	// Solution s;
    cin.get();
}
