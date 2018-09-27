#include "structs.h"
//types at structs.h
class Table{
private:
	str name;
	Data* t_data;
public:
	Table(str name, strp_vec& vec, uint_vec nums, char_name_vec& cvec);
	str getName();
	void desc();
	friend void writeTable(txt_file& file, Table* t);
	friend void writeHeaderTable(txt_file& file, Table* t);
};
