#include "table.h"
#include "functions.h" //types.h included here


class DataBase{
private:
	table_vec tables;
	bool query_where, to_insert;
	str_vec values_to_compare;	
	
	bool interpret_query(str query, str& name, strp_vec& vec, char_name_vec& cvec, uint_vec& num);
		
public:
	DataBase();
	void createTable(str query);
};
