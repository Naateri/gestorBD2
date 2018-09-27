#include "table.h"

Table::Table(str name, strp_vec& vec, uint_vec nums, char_name_vec& cvec){
	this->name = name;
	Data *temp = new Data(nums.at(0), nums.at(1), vec, cvec);
	this->t_data = temp;
}

str Table::getName(){
	return this->name;
}

void Table::desc(){
	int camps;
	camps = this->t_data->n + this->t_data->v;
	std::cout << "Tabla: " << this->name << '\n';
	std::cout << "Hay " << camps << " atributos.\n"; 
	print_vec(this->t_data->names, this->t_data->vchars);
}


void writeTable(txt_file& file, Table* t){
	int j = 0;
	file << t->name << '\n';
	for(int i = 0; i < t->t_data->names.size(); i++){
		file << t->t_data->names.at(i).second << ' '; //STORED: DATA_NAME DATA_TYPE ENDL 
		if (t->t_data->names.at(i).first == "VARCHAR" ){
			file << "VARCHAR(" << t->t_data->vchars.at(j).second << ")" << '\n';
			j++;
		} else file << t->t_data->names.at(i).first << '\n'; //TIPO DE DATO
	}
	file << "-----------------------------------------"; //SEPARATION BETWEEN TABLES 
	file << '\n' << std::endl;  //so the next one starts at the next line
}

void writeHeaderTable(txt_file& file, Table* t){
	int j = 0;
	for(int i = 0; i < t->t_data->names.size(); i++){
		if (i != t->t_data->names.size()-1) file << t->t_data->names.at(i).second << ','; //STORED: DATA_NAME,DATA_NAME,... ENDL 
		else file << t->t_data->names.at(i).second;
	}
	file << '\n'; //SEPARATION FOR THE DATA TO BE STORED
}
