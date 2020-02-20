#include <iostream>
// 3-2. Add a read_from and a write_to function to Listing 3-6. These functions should read or write to upper or lower as
// appropriate. Perform bounds checking to prevent buffer overflows.

char readFrom(char pom[] /* !!!!! it will be only pointer here forever NOT ARRAY */, int n_pom, int ind) {
    int vel{ (sizeof(&pom) / sizeof(pom[0])) };
    std::cout << "\n-- vel is: " << vel << "\n"
              << "-- pom[] is: " << pom << "\n";
    std::cout << "-- n_pom is: " << n_pom << "\n";
    if(n_pom < 0) {
        std::cout << "-- Size of array is 0";
        return ('&');
    } else if(ind >= 0 && ind < n_pom) {
        return pom[ind];
    } else {
        std::cout << "\n --Index is not within size of array \n";
        return '#';
    };
}

int main() {
    char lower[] = "abc?e";
    char upper[] = "ABC?E";
    char* upper_ptr = upper; // Equivalent: &upper[0]

    lower[3] = 'd';     // lower now contains a b c d e \0
    upper_ptr[3] = 'D'; // upper now contains A B C D E \0

    char letter_d = lower[3];     // letter_d equals 'd'
    char letter_D = upper_ptr[3]; // letter_D equals 'D'
    std::cout << "letter_d: " << letter_d << " ----- "
              << "letter_D: " << letter_D << "\n";

    std::cout << "lower: " << lower << "\n"
              << "upper: " << upper << "\n";

    int lower_size{ sizeof(lower) / sizeof(char) };
    std::cout << "Size of lower is: " << lower_size << "\n";
    std::cout << "readFrom(lover,lower_size,2) is: " << readFrom(lower, lower_size, 2) << "\n";

    lower[7] = 'g'; // Super bad. You must never do this.
}