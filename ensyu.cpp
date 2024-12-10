#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>

class PiCalculator {
public:
    static double calculatePi(int iterations) {
        double pi = 0.0;

        // グレゴリ・ライプニッツ級数の実装部分
        for (int k = 0; k < iterations; ++k) {
            pi += (std::pow(-1, k)) / (2 * k + 1);
        }
        
        return 4 * pi;
    }

    //ターミナルに表示する内容設定
    static void displayResults(int iterations, double calculatedPi, std::chrono::duration<double> executionTime) {
        const double actualPi = M_PI;
        
        std::cout << "反復回数: " << iterations << std::endl;
        std::cout << std::fixed << std::setprecision(15);
        std::cout << "計算されたπ: " << calculatedPi << std::endl;
        std::cout << "実際のπ:     " << actualPi << std::endl;
        std::cout << "誤差:        " << std::abs(calculatedPi - actualPi) << std::endl;
        std::cout << std::fixed << std::setprecision(6);
        std::cout << "実行時間:    " << executionTime.count() * 1000000 << "μs" << std::endl;
        std::cout << std::endl;
    }
};

int main() {
    // 反復回数の指定
    int iterations_list[] = {10, 100, 1000, 10000};
    
    for (int iterations : iterations_list) {
        // 開始時間を記録
        auto start = std::chrono::high_resolution_clock::now();
        
        // 円周率計算
        double calculatedPi = PiCalculator::calculatePi(iterations);
        
        // 終了時間を記録
        auto end = std::chrono::high_resolution_clock::now();
        
        // 実行時間を計算
        std::chrono::duration<double> executionTime = end - start;
        
        // 結果と実行時間を表示
        PiCalculator::displayResults(iterations, calculatedPi, executionTime);
    }
    
    return 0;
}
