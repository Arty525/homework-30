#include <iostream>
#include <cpr/cpr.h>
#include <vector>
#include <iterator>

cpr::Payload arg(std::vector<cpr::Pair> post) {
	cpr::Payload p = {post[0]};
	for (int i = 1; i < post.size(); ++i) {
		p.Add({ post[i] });
	}
	return p;
}

int main() {
	std::vector<cpr::Pair> post;
	std::map<std::string, std::string> get;
	std::string argName;
	std::string argVal;
	cpr::Response r;

	do {
		std::cout << "Enter argument: ";
		std::cin >> argName;
		if (argName != "get" && argName != "post") {
			std::cout << "Enter value: ";
			std::cin >> argVal;
		}
		else break;
		post.push_back(cpr::Pair((std::string)argName, (std::string)argVal));
		get.insert(std::pair<std::string, std::string>(argName, argVal));
	} while (argName != "get" || argName != "post");

	if (argName == "get") {
		std::string url = "http://httpbin.org/get?";
		for (std::map<std::string, std::string>::iterator it = get.begin(); it != get.end(); it++)
		{
			url += it->first + "=" + it->second;
			if(it != get.begin()) url += "&";
		}
		r = cpr::Get(cpr::Url(url));
	}

	else if (argName == "post") {
		r = cpr::Post(cpr::Url("http://httpbin.org/post"), cpr::Payload{arg(post)});
	}

	std::cout << r.text << std::endl;
	return 0;
}