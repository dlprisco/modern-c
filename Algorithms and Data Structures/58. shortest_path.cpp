// The shortest path between nodes


/*

	To solve the proposed problem you must use the Dijkstra algorithm for finding the shortest
  path in a graph. Although the original algorithm finds the shortest path between two given
  nodes, the requirement here is to find the shortest path between one specified node and all
  the others in the graph, which is another version of the algorithm.


*/

using namespace std;

template <typename Vertex = int, typename Weight = double>
class graph {
public:
	typedef Vertex vertex_type;
	typedef Weight weight_type;
	typedef pair<Vertex, Weight> neighbor_type;
	typedef vector<neighbor_type> neighbor_list_type;
public:	
	void add_edge(Vertex const source, Vertex const target,Weight const weight, bool const bidirectional = true) {
		adjacency_list[source].push_back(make_pair(target, weight));
		adjacency_list[target].push_back(make_pair(source, weight));
	}

	size_t vertex_count() const { 
		return adjacency_list.size(); 
	}

	vector<Vertex> verteces() const {
		vector<Vertex> keys;
		for (auto const & kvp : adjacency_list)
			keys.push_back(kvp.first);
		return keys;
	}

	neighbor_list_type const & neighbors(Vertex const & v) const {
		auto pos = adjacency_list.find(v);
		if (pos == adjacency_list.end())
			throw runtime_error("vertex not found");
		return pos->second;
	}

	constexpr static Weight Infinity = numeric_limits<Weight>::infinity();

private:
	map<vertex_type, neighbor_list_type> adjacency_list;
};	

template <typename Vertex, typename Weight>
void shortest_path(graph<Vertex, Weight> const & g,Vertex const source,map<Vertex, Weight>& min_distance,map<Vertex, Vertex>& previous) {
	auto const n = g.vertex_count();
	auto const verteces = g.verteces();
	min_distance.clear();
	for (auto const & v : verteces)
		min_distance[v] = graph<Vertex, Weight>::Infinity;
	min_distance[source] = 0;


	previous.clear();
	set<pair<Weight, Vertex> > vertex_queue;
	vertex_queue.insert(make_pair(min_distance[source], source));

	while (!vertex_queue.empty()) {
		auto dist = vertex_queue.begin()->first;
		auto u = vertex_queue.begin()->second;
		vertex_queue.erase(begin(vertex_queue));
		auto const & neighbors = g.neighbors(u);
		for (auto const & neighbor : neighbors) {
			auto v = neighbor.first;
			auto w = neighbor.second;
			auto dist_via_u = dist + w;
			if (dist_via_u < min_distance[v]) {
				vertex_queue.erase(make_pair(min_distance[v], v));
				min_distance[v] = dist_via_u;
				previous[v] = u;
				vertex_queue.insert(make_pair(min_distance[v], v));
			}
		}
	}
}


template <typename Vertex>
void build_path(map<Vertex, Vertex> const & prev, Vertex const v, vector<Vertex> & result) {
	result.push_back(v);
	auto pos = prev.find(v);
	if (pos == end(prev)) return;
	build_path(prev, pos->second, result);
}

template <typename Vertex>
vector<Vertex> build_path(map<Vertex, Vertex> const & prev,Vertex const v) {
	vector<Vertex> result;
	build_path(prev, v, result);
	reverse(begin(result), end(result));
	return result;
}

template <typename Vertex>
void print_path(vector<Vertex> const & path) {
	for (size_t i = 0; i < path.size(); ++i) {
		cout << path[i];
		if (i < path.size() - 1) cout << " -> ";
	}
}

int main() {
	graph<char, double> g;
	g.add_edge('A', 'B', 7);
	g.add_edge('A', 'C', 9);
	g.add_edge('A', 'F', 14);
	g.add_edge('B', 'C', 10);
	g.add_edge('B', 'D', 15);
	g.add_edge('C', 'D', 11);
	g.add_edge('C', 'F', 2);
	g.add_edge('D', 'E', 6);
	g.add_edge('E', 'F', 9);

	char source = 'A';
	map<char, double> min_distance;
	map<char, char> previous;
	shortest_path(g, source, min_distance, previous);
	for (auto const & kvp : min_distance) {
		cout << source << " -> " << kvp.first << " : " << kvp.second << '\t';
		print_path(build_path(previous, kvp.first));
		cout << endl;
	}
}