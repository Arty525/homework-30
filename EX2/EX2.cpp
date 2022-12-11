#include <cpr/cpr.h>
#include <iostream>
#include <string>

int main() {
	std::string header;
	cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"), cpr::Header{ {"Accept", "text/html"} });

	int start = r.text.find("<h1>", 0) + 4;
	int end = r.text.find("</h1>", start);

	header = r.text.substr(start, end - start);
	std::cout << "Header: " << header << std::endl;

	return 0;
}