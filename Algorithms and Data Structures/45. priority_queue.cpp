// Priority queue

using namespace std;

template <class T, class Compare = less<typename vector<T>::value_type>>
class priority_queue {
	typedef typename vector<T>::value_type value_type;
	typedef typename vector<T>::size_type size_type;
	typedef typename vector<T>::reference reference;
	typedef typename vector<T>::const_reference const_reference;
public:
	bool empty() const noexcept { return data.empty(); }
	size_type size() const noexcept { return data.size(); }
	void push(value_type const & value) {
		data.push_back(value);
		push_heap(begin(data), end(data), comparer);
	}

	void pop() {
		pop_heap(begin(data), end(data), comparer);
		data.pop_back();
	}
	const_reference top() const { return data.front(); }
	void swap(priority_queue& other) noexcept {
		swap(data, other.data);
		swap(comparer, other.comparer);
	}
private:
	vector<T> data;
	Compare comparer;
};

template<class T, class Compare>
void swap(priority_queue<T, Compare>& lhs, priority_queue<T, Compare>& rhs)
noexcept(noexcept(lhs.swap(rhs))) {
	lhs.swap(rhs);
}

int main() {
	priority_queue<int> q;
	for (int i : {1, 5, 3, 1, 13, 21, 8}) {
		q.push(i);
	}
	assert(!q.empty());
	assert(q.size() == 7);
	while (!q.empty()) {
		cout << q.top() << ' ';
		q.pop();
	}
}