/* 
Assignment 4: Weather Forecast

This assignment works with template functions and lambdas to become the best weather forecaster
at the Stanford Daily. Be sure to read the assignment details in the PDF.

Submit to Paperless by 11:59pm on 2/16/2024.
*/

// to support concepts
// g++ -std=c++20 main.cpp -o main.exe

// TODO: import anything from the STL that might be useful!
#include <iostream>
#include <fstream>
#include <vector>
#include <concepts>
#include <algorithm>
#include <numeric>  // to support accumulate()

// TODO: write convert_f_to_c function here. Remember it must be a template function that always returns
// a double.
// [function definition here]
template <typename T>
concept Numeric = std::floating_point<T> || std::integral<T>;   // concepts are template predicates of type

template <Numeric T>
double convert_f_to_c(T f) {
    return (f - 32.0) * 5.0 / 9.0;
}

template <typename Function>
std::vector<double> get_forecast(std::vector<std::vector<double>> readings, Function fn) {
    // TODO: write get_forecast here!
    // fn must be a unary function
    std::vector<double> outputs(readings.size());
    std::transform(readings.begin(), readings.end(), outputs.begin(), fn);
    return outputs;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (const auto& elem : vec) {
        os << elem << ", ";
    }
    os << "]";
    return os;
}

int main() {
    std::vector<std::vector<int>> readings = {
        {70, 75, 80, 85, 90},
        {60, 65, 70, 75, 80},
        {50, 55, 60, 65, 70},
        {40, 45, 50, 55, 60},
        {30, 35, 40, 45, 50},
        {50, 55, 61, 65, 70},
        {40, 45, 50, 55, 60}
    };

    std::ofstream ofs("output.txt");
    // TODO: Convert temperatures to Celsius and output to output.txt
    std::vector<std::vector<double>> creadings(
        readings.size(),
        std::vector<double>(readings[0].size())
    );
    auto convert_column = [] (const std::vector<int>& col) {
        std::vector<double> ccol(col.size());
        std::transform(col.cbegin(), col.cend(), ccol.begin(), convert_f_to_c<int>);
        return ccol;
    };
    std::transform(readings.cbegin(), readings.cend(), creadings.begin(), convert_column);
    ofs << creadings << std::endl;

    // TODO: Find the maximum temperature for each day and output to output.txt
    auto find_max = [] (const std::vector<double>& v) {
        return *std::max_element(v.cbegin(), v.cend());
    };
    ofs << get_forecast(creadings, find_max) << std::endl;

    // TODO: Find the minimum temperature for each day and output to output.txt
    auto find_min = [] (const std::vector<double>& v) {
        return *std::min_element(v.cbegin(), v.cend());
    };
    ofs << get_forecast(creadings, find_min) << std::endl;

    // TODO: Find the average temperature for each day and output to output.txt
    auto calculate_avg = [] (const std::vector<double>& v) {
        return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
    };
    ofs << get_forecast(creadings, calculate_avg) << std::endl;

    return 0;
}