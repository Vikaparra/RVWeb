#include "xmlParser\pugixml.hpp"
#include <iostream>
using namespace std;

int main() {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("C:\\Users\\k\\Documents\\Unicamp\\IC\\ReservoirViewerWeb\\RVWeb\\xmlParser\\PX_PH_config.xml");

    std::cout << "Load result: " << result.description() << ", mesh name: " << doc.child("mesh").attribute("name").value() << std::endl;
	cout << "hello!" << endl; // prints
	return 0;
}