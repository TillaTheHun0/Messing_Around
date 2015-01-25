/*
Author:Tyler Hall
crude implementation of merge sort for practicing purposes
*/

#include <vector>
#include <stack>
#include <algorithm>

template<typename type>
std::vector<type> merge(std::vector<type> &vec, const std::vector<type> &left, const std::vector<type> &right){
	std::vector<type> result;
	int l_index = 0, r_index = 0;
	//start comparing the lists until one empties
	while (l_index < left.size() && r_index < right.size()){
		if (left[l_index] < right[r_index]){
			result.push_back(left[l_index]);
			l_index++;
		}
		else{
			result.push_back(right[r_index]);
			r_index++;
		}
	}
	//one list emptied. Push remaining values onto result.
	//one of these loops wont execute
	while (l_index < left.size()){
		result.push_back(left[l_index]);
		l_index++;
	}
	while (r_index < right.size()){
		result.push_back(right[r_index]);
		r_index++;
	}
	//assign result to vec
	vec = result;
	return vec;
}

template<typename type>
std::vector<type> mergeSort(std::vector<type> &vec){

	//base case
	if (vec.size() == 1){
		return vec;
	}
	
	//make iterator in middle of list
	std::vector<type>::iterator mid = vec.begin() + (vec.size() / 2);

	std::vector<type> left(vec.begin(), mid);
	std::vector<type> right(mid, vec.end());

	//recursively split list
	left = mergeSort(left);
	right = mergeSort(right);

	//when list all get down to 1 element they will recursively merge back up through stack
	return merge(vec,left, right);
}

int main(){
	std::vector<int> myvec;
	int i = 1;
	for (; i <= 20; i++){
		int random = i * rand();
		myvec.push_back(random);
		printf("%d ", random);
	}
	printf("\n\n");
	mergeSort(myvec);
	printf("\nSorted List:\n");
	//std::sort(myvec.begin(), myvec.end());

	for (std::vector<int>::iterator iter = myvec.begin(); iter != myvec.end(); iter++){
		printf("%d", *iter);
	}
	return 0;
}