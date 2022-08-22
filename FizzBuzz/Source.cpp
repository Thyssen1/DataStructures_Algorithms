#include <iostream>
#include <map>
#include <string>

int main() {
	unsigned int N = 10000;

	std::map<int, std::string> my_map;
	std::string msg = "";

	my_map.emplace(3, "Fizz");
	my_map.emplace(5, "Buzz");
	my_map.emplace(7, "Bazz");

	for (int i = 1; i < N; i++) {
		for (auto it = my_map.begin(); it != my_map.end(); it++) {
			if (i % it->first == 0) { msg += it->second; }
		}
		if (msg == "") {
			msg = std::to_string(i);
		}

		//std::cout << msg << "\n";
		msg = "";
	}


	return 0;
}