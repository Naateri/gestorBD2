#include<iostream>
#include "db.h"
using namespace std;

int main (int argc, char *argv[]) {
	DataBase DB;
	while (true){
		str query;
		getline(std::cin, query);
		//DB.createTable(query);
		//DB.insert_row(query);
		DB.i_query(query);
	}
	return 0;
}

