#include "functions.h"

int rdtsc(){
	__asm__ __volatile__("rdtsc");
}

u_int stringToUint(str a){
	u_int ret;
	ss convi(a);
	convi >> ret;
	return ret;
}

int stringToInt(str a){
	int ret;
	ss convi(a);
	convi >> ret;
	return ret;
}

str intToString(int a){
	str ret;
	ss leString;
	leString << a;
	return leString.str();
}

LL stringToLL(str a){
	LL ret;
	ss convi(a);
	convi >> ret;
	return ret;
}

int rand_between(int a, int b){
	srand( rdtsc() );
	return rand() % b + a;
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


void write_multiple(txt_file& file, read_file& file2, str_vec t){ //not efficient xdxdxdxd
	int_vec a, b; //random numbers
	int rands = 0, j, k, num_char = 0;
	str num, le_text;
	str_vec chars;
	uint_vec what_to_insert; //0: Incrementer, 1: Random, 2: char
	bool char_inserted;
	for(int i = 0; i < t.size(); i++){
		if (t.at(i)[0] == 'I') what_to_insert.push_back(0);
		else if (t.at(i)[0] == 'R'){
			rands++;
			what_to_insert.push_back(1);
		} else what_to_insert.push_back(2);
	}
	rands = 0;
	for (int i = 0; i < t.size(); i++){ //getting random numbers
		if (t.at(i)[0] == 'R'){
			num.clear();
			j = 1;
			while (t.at(i)[j] != ','){ //Rnum1,num2 
				num += t.at(i)[j++];
			}
			j++;
			a.push_back( stringToInt(num) );
			num.clear();
			while (j < t.at(i).size() ){
				num += t.at(i)[j++];
			}
			b.push_back( stringToInt(num) );
		}
	}
	getline(file2, num);
	j = 0;
	for (int i = 0; i < what_to_insert.size(); i++){
		char_inserted = 0;
		if (what_to_insert.at(i) == 2){
			k = 0;
			le_text.clear();
			while((j) < num.size() ){
				if (num[j] == ','){
					if (k == i){
						chars.push_back(le_text);
						char_inserted = 1;
					}
					k++;
					j++;
					le_text.clear();
				}
				le_text += num[j];
				j++;
			}
			if (!char_inserted) {
				chars.push_back(le_text);
			}
		}
	}
	for (int i = 0; i < 10000; i++){
		rands = 0;
		num_char = 0;
		str lel;
		lel.clear();
		for (j = 0; j < what_to_insert.size(); j++){
			if (what_to_insert.at(j) == 0){
				if (j != what_to_insert.size() - 1) {
					lel += intToString(i+1) + ',';
					//file << i+1 << ',';
				}
				else{
					//file << i+1 << '\n';
					lel += intToString(i+1) + '|';
				}
			}
			else if (what_to_insert.at(j) == 1){
				if (j != what_to_insert.size() - 1){
					//file << rand_between(a.at(rands), b.at(rands)) << ',';
					lel += intToString(rand_between(a.at(rands), b.at(rands))) + ',';
				}
				else {
					//file << rand_between(a.at(rands), b.at(rands)) << '\n';
					lel += intToString(rand_between(a.at(rands), b.at(rands))) + '|';
				}
				rands++;
			} else {				
				if (j != what_to_insert.size() - 1){
					//file << chars.at(num_char) << i+1 << ',';
					lel += chars.at(num_char) + intToString(i+1) + ',';
				}
				else {
					//file << chars.at(num_char) << i+1 << '\n';
					lel += chars.at(num_char) + intToString(i+1) + '|';
				}
				num_char++;
			}
		}
		
		while (lel.size() <= 35) lel += ' ';
		lel += '\n';
		file << lel;
		/*if (i != 1000 - 1) file << ',';
		else file << '\n';*/
	}
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
