#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>

void selection_sort(size_t n){
   double * arr { new double[n] };
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_real_distribution<> dist(0.0,100.0);
   
   for(auto i {0} ; i<n ; i++){
	arr[i] = dist(gen);	
   }
   
   for(auto k{n-1} ; k>0 ; k--){
     auto maxI = 0;
     for(auto i{1} ; i<=k; i++){
        if(arr[i]>arr[maxI]) 
	  maxI = i;
     }
     double tmp = arr[maxI];
     arr[maxI] = arr[k];
     arr[k] = tmp;
   }

   delete [] arr;
}

#define N_RUNS (3)

int main(int argc , char ** argv) {

    std::ofstream outfile{argv[1]};
    if(!outfile){
       std::cerr << "Failed to open the output file : " << argv[1] << std::endl;
    }

    // List of problem sizes to test
    std::vector<size_t> problem_sizes = {
        10 , 20 , 100, 200, 1000, 2000, 10000, 20000, 100000 , 200000
    };

    std::cout << std::left << std::setw(15) << "Problem Size" 
              << std::setw(15) << "Time (ms)" << "\n";
    std::cout << std::string(30, '-') << "\n";

    for (auto size : problem_sizes) {

	double total_elapsed {0.0};

	for( auto i{0} ; i<N_RUNS ; i++ ){
          auto start = std::chrono::steady_clock::now();

          selection_sort(size); 

          auto end = std::chrono::steady_clock::now();
          std::chrono::duration<double, std::milli> elapsed = end - start;
          total_elapsed += elapsed.count();
        }

        std::cout << std::setw(15) << size 
                  << std::setw(15) << total_elapsed/N_RUNS << std::endl;
        outfile << size << " " << total_elapsed/N_RUNS << std::endl;
    }

    outfile.close();

    return 0;
}
