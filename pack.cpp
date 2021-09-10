#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>

using namespace std;
using namespace chrono;

typedef vector<int> Vi;

int calcPrice(int w, int h);
bool isSameBox(int i, int j, int k);
int minPrice(const Vi& width, const Vi& height);

int main(void) {
	Vi width(6);
	Vi height(6);

	for (int i = 0; i < 3; i++) {
		cin >> width.at(i) >> height.at(i);
		width[i + 3] = height[i];
		height[i + 3] = width[i];
	}

	int price = minPrice(width, height);

	cout << price << endl;

	return 0;
}


bool isSameBox(int i, int j, int k) {
	if (i % 3 == j % 3 or j % 3 == k % 3 or k % 3 == i % 3)
		return true;
	return false;
}

int calcPrice(int w, int h) {
	return w * w + h * h;
}

int minPrice(const Vi& width, const Vi& height) {
	int result = 8000000;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 6; k++) {

				if (isSameBox(i, j, k))
					continue;

				int w, h;

				w = width[i] + width[j] + width[k];
				h = max(height[i], max(height[j], height[k]));

				result = min(calcPrice(w, h), result);
				
				w = max(width[i] + width[j], width[k]);
				h = max(height[i], height[j]) + height[k];

				result = min(calcPrice(w, h), result);
			}
		}
	}
	return result;
}