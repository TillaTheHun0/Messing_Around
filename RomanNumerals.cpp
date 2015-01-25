/*
Author: Tyler Hall
This code converts Roman Numeral Numbers into Decimal
*/

#include<unordered_map>

struct converter{
	std::unordered_map<char, int> r2d;

	converter(){
		r2d['I'] = 1;
		r2d['V'] = 5;
		r2d['X'] = 10;
		r2d['L'] = 50;
		r2d['C'] = 100;
		r2d['D'] = 500;
		r2d['M'] = 1000;
	}

	int helper(char digit){
		return r2d.at(digit);
	}

	int convert(std::string num){
		int total = 0;
		for (int index = 0; index < num.length(); index++){
			//last digit
			if (index == num.length() - 1){
				total += helper(num[index]);
			}
			else{
				int cur = helper(num[index]), next = helper(num[index+1]);
				//true if something like IV, IX, CD
				if (next > cur){
					total += (next - cur);
					//skip next number because two 
					//digits represent 1 number place
					index++;
				}
				//normal add to total
				else{
					total += cur;
				}
			}
		}
		return total;
	}
};

int main(){
	converter converter;
	//2015, 1066, 1954, 1990, 2014
	std::string test[] = { "MMXV", "MLXVI", "MCMLIV", "MCMXC", "MMXIV" };

	for (int i = 0; i < 5; i++){
		printf("%d\n", converter.convert(test[i]));
	}
	return 0;
}