#include "table.h"
#include "functions.h" //types.h included here


class DataBase{
private:
	table_vec tables;
	bool query_where, to_insert;
	str_vec values_to_compare;	
	int comparator; //0: EQUAL, 1: GREATER, 2: EQUAL
	
	bool interpret_query(str query, str& name, strp_vec& vec, char_name_vec& cvec, uint_vec& num);
	bool interpret_query_i(str query, str& name, str_vec& values);
	bool interpret_query_s(str query, str& name, str_vec& values, str& column);
	bool interpret_query_d(str query, str& name, str_vec& values, str& column);
	bool interpret_query_u(str query, str& name, str_vec& values, str& column, str_vec& columns);
	
	str_vec select_query(read_file& file, str_vec columns, str name, str column); //each position at the vec returned is a row of data
	void delete_query(read_file& file, txt_file& outfile, str_vec columns, str name, str column);
	void update_query(read_file& file, txt_file& outfile, str_vec columns, str_vec values, str name, str column);
	
	u_int finding_atribute_type(str type_name, str table_name, int& pos);
		
public:
	DataBase();
	void i_query(str query); //general interpret query
	void createTable(str query);
	void insert_row(str query);
	void select_data(str query);
	void delete_data(str query);
	void update_data(str query);
};
