#include <iostream>
#include <vector>

template <typename T>
void merge(std::vector<T> &v, int left_idx, int mid_idx, int right_idx) {
	int i, j, k = left_idx;
	int left_size = mid_idx - left_idx + 1;
	int right_size = right_idx - mid_idx;

	std::vector<T> left_vector(left_size), right_vector(right_size);
	for (i=0; i<left_size; ++i) {
		left_vector.push_back(v[left_idx + i]);
	}
	for (j=0; j<right_size; ++j) {
		right_vector.push_back(v[mid_idx+1+j]);
	}

	i=0, j=0;
	while ((i<left_size) && (j<right_size)) {
		if (left_vector[i] <= right_vector[j]) {
			v[k] = left_vector[i];
			i++;
		}
		else {
			v[k] = right_vector[j];
			j++;
		}
		k++;
	}

	while (i<left_size) {
		v[k] = left_vector[i];
		i++;
		k++;
	}

	while (j<right_size) {
		v[k] = right_vector[j];
		j++;
		k++;
	}
}

template <typename T>
void merge_sort(std::vector<T> &v, int left_idx, int right_idx) {
	if (left_idx < right_idx) {
		int mid_idx = (left_idx + right_idx) / 2;

		merge_sort(v, left_idx, mid_idx);
		merge_sort(v, mid_idx+1, right_idx);

		merge(v, left_idx, mid_idx, right_idx);
	}
}

int main() {
	return 0;
}
