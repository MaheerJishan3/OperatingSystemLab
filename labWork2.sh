#!/bin/bash

while true; do
    echo "Choose an operation:"
    echo "1. Addition"
    echo "2. Subtraction"
    echo "3. Multiplication"
    echo "4. Division"
    echo "5. Factorial"
    echo "6. nPr (Permutation)"
    echo "7. Exit"
    read -p "Enter your choice [1-7]: " choice

    case $choice in
        1)
            read -p "Enter first number: " a
            read -p "Enter second number: " b
            if [[ $a =~ ^-?[0-9]+$ && $b =~ ^-?[0-9]+$ ]]; then
                echo "Result: $((a + b))"
            else
                echo "Invalid input. Please enter integers."
            fi
            ;;
        2)
            read -p "Enter first number: " a
            read -p "Enter second number: " b
            if [[ $a =~ ^-?[0-9]+$ && $b =~ ^-?[0-9]+$ ]]; then
                echo "Result: $((a - b))"
            else
                echo "Invalid input. Please enter integers."
            fi
            ;;
        3)
            read -p "Enter first number: " a
            read -p "Enter second number: " b
            if [[ $a =~ ^-?[0-9]+$ && $b =~ ^-?[0-9]+$ ]]; then
                echo "Result: $((a * b))"
            else
                echo "Invalid input. Please enter integers."
            fi
            ;;
        4)
            read -p "Enter numerator: " a
            read -p "Enter denominator: " b
            if [[ $a =~ ^-?[0-9]+$ && $b =~ ^-?[0-9]+$ ]]; then
                if [ "$b" -eq 0 ]; then
                    echo "Error: Division by zero is not allowed."
                else
                    echo "Result: $((a / b))"
                fi
            else
                echo "Invalid input. Please enter integers."
            fi
            ;;
        5)
            read -p "Enter a non-negative integer: " n
            if [[ $n =~ ^[0-9]+$ ]]; then
                if [ "$n" -lt 0 ]; then
                    echo "Error: Factorial of negative number is not defined."
                else
                    fact=1
                    for ((i=2; i<=n; i++)); do
                        fact=$((fact * i))
                    done
                    echo "Result: $fact"
                fi
            else
                echo "Invalid input. Please enter a non-negative integer."
            fi
            ;;
        6)
            read -p "Enter n (non-negative integer): " n
            read -p "Enter r (non-negative integer): " r
            if [[ $n =~ ^[0-9]+$ && $r =~ ^[0-9]+$ ]]; then
                if [ "$n" -lt "$r" ]; then
                    echo "Error: n must be greater than or equal to r."
                else
                    fn=1
                    for ((i=2; i<=n; i++)); do
                        fn=$((fn * i))
                    done
                    fnr=1
                    for ((i=2; i<=n-r; i++)); do
                        fnr=$((fnr * i))
                    done
                    npr=$((fn / fnr))
                    echo "Result: $npr"
                fi
            else
                echo "Invalid input. Please enter non-negative integers."
            fi
            ;;
        7)
            echo "Exiting calculator. Goodbye!"
            break
            ;;
        *)
            echo "Invalid choice. Please select a valid option (1-7)."
            ;;
    esac
    echo
done