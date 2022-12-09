#include <iostream>
#include <cpr/cpr.h>

void get(cpr::Response r) {
	r = cpr::Get(cpr::Url("http://httpbin.org/get"));
	std::cout << r.text << std::endl;
}

void post(cpr::Response r, std::string name, std::string city) {
	std::cout << "Name: ";
	std::cin >> name;
	std::cout << "City: ";
	std::cin >> city;
	r = cpr::Post(cpr::Url("http://httpbin.org/post"), cpr::Payload({{"name", name.c_str()}, {"city", city.c_str()}}));
	std::cout << r.text << std::endl;
}

void put(cpr::Response r) {
	r = cpr::Put(cpr::Url("http://httpbin.org/put"));
	std::cout << r.text << std::endl;
}

void del(cpr::Response r) {
	r = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
	std::cout << r.text << std::endl;
}

void patch(cpr::Response r) {
	r = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
	std::cout << r.text << std::endl;
}

int main() {
	cpr::Response r;
	std::string name, city, command;
	do {
		std::cout << "Command: ";
		std::cin >> command;

		if (command == "get") {
			get(r);
		}
		
		if (command == "post") {
			post(r, name, city);
		}

		if (command == "put") {
			put(r);
		}

		if (command == "delete") {
			del(r);
		}

		if (command == "patch") {
			patch(r);
		}		
	} while (command != "exit");

	return 0;
}