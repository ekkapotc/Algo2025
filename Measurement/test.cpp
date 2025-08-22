#include <iostream>
#include <random>

void selection_sort(size_t n) {
  double *arr{new double[n]};
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dist(0.0, 100.0);

  std::cout << "Before sorting : " << std::endl;

  for (auto i{0}; i < n; i++) {
    arr[i] = dist(gen);
    std::cout << arr[i] << " ";
  }

  std::cout << "\n";

  for (auto k{n - 1}; k > 0; k--) {
    auto maxI = 0;
    for (auto i{1}; i <= k; i++) {
      if (arr[i] > arr[maxI])
        maxI = i;
    }
    double tmp = arr[maxI];
    arr[maxI] = arr[k];
    arr[k] = tmp;
  }

  std::cout << "After sorting : " << std::endl;

  for (auto i{0}; i < n; i++) {
    std::cout << arr[i] << " ";
  }

  std::cout << "\n";
  delete[] arr;
}

int main() {

  selection_sort(20);

  return 0;
}
