#include "table.h"
#include "functions.h" //types.h included here


class DataBase{
private:
	table_vec tables;
	tree_vec indices;
	bool query_index, query_where, to_insert, index_eval, id_index;
	str_vec values_to_compare;	
	int comparator; //0: EQUAL, 1: GREATER, 2: EQUAL
	
	bool interpret_query(str query, str& name, strp_vec& vec, char_name_vec& cvec, uint_vec& num);
	bool interpret_query_index(str query, str& name_index, str& name_table, str& name_col);
	bool interpret_query_aRam(str query, str& name_index);
	bool interpret_query_i(str query, str& name, str_vec& values);
	bool interpret_query_s(str query, str& name, str_vec& values, str& column);
	bool interpret_query_d(str query, str& name, str_vec& values, str& column);
	bool interpret_query_u(str query, str& name, str_vec& values, str& column, str_vec& columns);
	bool interpret_query_i_m(str query, str& name, str_vec& values);
	bool interpret_query_i_index(str query, str& name, str_vec& values, str_vec& name_indices, int_vec& num_col, str& num_fila);
	
	str_vec select_query(read_file& file, str_vec columns, str name, str column); //each position at the vec returned is a row of data
	void select_query2(read_file& file, str_tree* m_tree, str column);
	void read_index(read_file& file, str_tree* m_tree);
	void delete_query(read_file& file, txt_file& outfile, str_vec columns, str name, str column);
	void update_query(read_file& file, txt_file& outfile, str_vec columns, str_vec values, str name, str column);
	
	u_int finding_atribute_type(str type_name, str table_name, int& pos);
		
public:
	DataBase();
	void i_query(str query); //general interpret query
	void createTable(str query);
	void createIndex(str query);
	void insert_row(str query);
	void insert_row_index(str query);
	void select_data(str query);
	void delete_data(str query);
	void update_data(str query);
	void insert_multiple(str query);
	void aRam(str query);
	str_vec id_values(char* name);
};
