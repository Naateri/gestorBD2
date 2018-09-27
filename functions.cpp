#include "functions.h"

u_int stringToUint(str a){
	u_int ret;
	ss convi(a);
	convi >> ret;
	return ret;
}

LL stringToLL(str a){
	LL ret;
	ss convi(a);
	convi >> ret;
	return ret;
}

void print_vec(strp_vec vec, char_name_vec cvec){
	int j = 0;
	for(int i = 0; i < vec.size(); i++){
		std::cout << "Tipo de dato: " << vec.at(i).first << '\n';
		std::cout << "Nombre de la columna: " << vec.at(i).second << '\n';
		if (vec.at(i).first == "VARCHAR" ){
			std::cout << "El VARCHAR es de " << cvec.at(j).second << std::endl;
			j++;
		}
		std::cout << std::endl;
	}
	
}

void writeInsert(txt_file& file, str_vec t){
	for (int i = 0; i < t.size(); i++){
		if (i != t.size() - 1) file << t.at(i) << ',';
		else file << t.at(i) << '\n';
	}
	//file << '\n';
}

int findInArray(char to_be_found, char* to_look, int size){
	int index;
	for(index = 0; index < size; index++){
		if (to_be_found == to_look[index]) return index;
	}
	return -1; //if it wasn't found
}

str updateRow(str temp, uint_vec position, str_vec values){
	str ret, temp2, temp3;
	bool last_col;
	for (int i = 0; i < position.size(); i++){
		last_col = 1;
		int j = 0, k = 0;
		temp2.clear();
		temp3.clear();
		while (k < temp.size()){
			temp3 += temp[k];
			if (temp[k] == ',' || k == temp.size() - 1){
				
				if (position.at(i) == j){
					temp2 += values.at(i);
					temp2 += ',';
					last_col = 0;
					//break;
				} else {
					temp2 += temp3;
				}
				//temp2 += ',';
				j++; k++;
				temp3.clear();
				continue;
			}
			
			k++;
		}
		if (last_col){
			k = temp.size() - 1;
			while (temp[k] != ','){
				k--;
			}
			temp3 += values.at(i);
		}
		temp = temp2;
	}
	return temp;
}
