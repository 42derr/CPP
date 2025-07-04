#!/bin/bash

# WINDOW
# Check for input argument
if [ $# -ne 1 ]; then
    echo "Usage: ./test NUMBER"
    exit 1
fi

n=$1
if ! [[ "$n" =~ ^[0-9]+$ ]]; then
    echo "Error: Input must be a positive integer"
    exit 1
fi

# Calculate F(n)
calc_comparisons() {
    local num=$1
    local sum=0
    for ((k=1; k<=num; k++)); do
        value=$(echo "scale=10; 0.75 * $k" | bc)
        log2=$(echo "l($value)/l(2)" | bc -l)
        ceil=$(echo "($log2 + 0.9999999999)/1" | bc)
        sum=$((sum + ceil))
    done
    echo "$sum"
}

comparisons=$(calc_comparisons "$n")
echo "Comparisons : F($n) = $comparisons"

# Generate n random numbers (0 to 9999)
random_numbers=$(shuf -i 0-$((n - 1)) -n "$n" | xargs)

# Run ./PmergeMe with the generated numbers
./PmergeMe "$random_numbers"

# # MAC
# # Check for input argument
# if [ $# -ne 1 ]; then
#     echo "Usage: ./test.sh NUMBER"
#     exit 1
# fi

# n=$1
# if ! [[ "$n" =~ ^[0-9]+$ ]]; then
#     echo "Error: Input must be a positive integer"
#     exit 1
# fi

# # Calculate F(n)
# calc_comparisons() {
#     local num=$1
#     local sum=0
#     for ((k=1; k<=num; k++)); do
#         value=$(echo "scale=10; 0.75 * $k" | bc)
#         log2=$(echo "l($value)/l(2)" | bc -l)
#         ceil=$(echo "($log2 + 0.9999999999)/1" | bc)
#         sum=$((sum + ceil))
#     done
#     echo "$sum"
# }

# comparisons=$(calc_comparisons "$n")
# echo "Comparisons : F($n) = $comparisons"

# # Generate n random integers in range 0–9999 (macOS-friendly)
# # random_numbers=$(jot -r "$n" 0 9999 | sort -R | xargs)
# random_numbers=$(jot "$n" 1 "$n" | sort -R | xargs)

# # Run PmergeMe with numbers as a single string argument
# ./PmergeMe "$random_numbers"
