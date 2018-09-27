#include "db.h"

str create_tab = "CREATE TABLA ";
str insert_into = "INSERTAR EN "; //11
//str select = "SELECT ";

txt_file tables_txt;
read_file tables_txt2;

DataBase::DataBase(){
	;
}

bool DataBase::interpret_query(str query, str& name, strp_vec& vec, char_name_vec& cvec, uint_vec& num){
	str temp, type, type_name, char_num;
	int i, int_count, char_count;
	int_count = char_count = 0;
	vec.clear();
	temp.clear();
	temp = query.substr(0, 13); //temp = "CREATE TABLE "
	std::cout << "temp is " << temp << std::endl;
	if (temp != create_tab){
		std::cout << "Sintaxis incorrecta. Vuelva a intentarlo.\n";
		return 0;
	}
	i = 13;
	name.clear();
	while (query[i] != ' '){
		name += query[i];
		i++;
	}
	i++; //so query[i] != ' '
	while (query[i] != ';' && query[i] != ' '){
		type.clear();
		type_name.clear();
		str_pair data_name_pair; //pair of str(type), str(name)
		char_name char_name_pair;
		while (query[i] != ' ' && query[i] != '('){ //filling with type
			type += query[i];
			i++;
		}
		i++;
		if (type == "INTEGER"){
			int_count++; //i++ because next is a space
			while (query[i] != ' ' && query[i] != ';'){ //filling with the name chosen
				type_name += query[i];
				i++;
			}
			data_name_pair.first = type;
			data_name_pair.second = type_name;
			vec.push_back(data_name_pair);
			i++;
		} else if (type == "VARCHAR") {
			char_count++;
			char_num.clear();
			while (query[i] != ')' && query[i] != ';'){ //filling with the amount of bytes chosen
				char_num += query[i];
				i++;
			}
			i++; //i is now ' ' 
			i++; //i is now the letter
			while (query[i] != ' ' && query[i] != ';'){
				type_name += query[i];
				i++;
			}
			
			data_name_pair.first = type;
			data_name_pair.second = type_name;
			
			char_name_pair.first = type_name;
			char_name_pair.second = stringToUint(char_num); //n chars
			
			vec.push_back(data_name_pair);
			cvec.push_back(char_name_pair);
			
			i++;
		} else {
			std::cout << "Sintaxis incorrecta. Vuelva a intentarlo.\n";
			return 0;
		}
	}
	num.at(0) = (int_count);
	num.at(1) = (char_count);
	//num.at(2) = (date_count);
	return 1;
}	

bool DataBase::interpret_query_i(str query, str& name, str_vec& values){
	str temp, temp2;
	int i;
	values.clear();
	temp = query.substr(0, 12); //temp = "INSERTAR EN "
	if (temp != insert_into){
		std::cout << "Sintaxis incorrecta. Vuelva a intentarlo.\n";
		return 0;
	}
	i = 12;
	name.clear();
	while (query[i] != ' '){ //getting the name of the table
		name += query[i];
		i++;
	}
	i++; //so query[i] != ' '
	for (int j = 0; j < 8; j++){
		temp2 += query[i++];
	}
	if (temp2 != "VALORES "){
		std::cout << "Sintaxis incorrecta. Vuelva a intentarlo.\n";
		return 0;
	}
	while (query[i] != ';' && query[i] != ' '){
		temp.clear();
		while (query[i] != ' ' && query[i] != ';'){ //filling with type
			temp += query[i];
			i++;
		}
		i++;
		values.push_back(temp);
	}
	return 1;
}

void DataBase::createTable(str query){
	str name;
	strp_vec vec;
	char_name_vec cvec;
	uint_vec num (2);
	int i;
	
	if (!interpret_query(query, name, vec, cvec, num)) return;
	Table* temp = new Table(name, vec, num, cvec);
	//add_table(temp); 
	
	tables_txt.open("tables.ggwp", std::fstream::app); //adding to the file in hdd
	writeTable(tables_txt, temp);
	tables_txt.close();
	
	name += ".table";
	char* file_name = new char[name.size() + 1];
	for (i = 0; i < name.size(); i++){
		file_name[i] = name.at(i);
	}
	file_name[i] = '\0';
	tables_txt.open(file_name);
	writeHeaderTable(tables_txt, temp);
	tables_txt.close();
	
	delete [] file_name;
	
	std::cout << "Tabla " << temp->getName() << " creada.\n";
	temp->desc();
}

void DataBase::insert_row(str query){
	str name;
	str_vec vec;
	int i;
	
	if (!interpret_query_i(query, name, vec)) return;
	name += ".table";
	char* file_name = new char[name.size() + 1];
	for (i = 0; i < name.size(); i++){
		file_name[i] = name.at(i);
	}
	file_name[i] = '\0';
	tables_txt.open(file_name, std::fstream::app);
	//write the info retrieved to file_name
	writeInsert(tables_txt, vec);
	tables_txt.close();
	
	delete [] file_name;
	std::cout << "Datos insertados.\n";
	
}
