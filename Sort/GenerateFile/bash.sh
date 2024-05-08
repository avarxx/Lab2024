createFolders() 
{
  local folders=("very_small_tests" "small_tests" "big_tests" "test_most_duplicates")
  for folder in "${folders[@]}"; do
      mkdir -p "$folder" || {
          echo "Error: Failed to create directory '$folder'." >&2
          exit 1
      }
  done
}


generateTests() 
{
  local folder_name=$1
  local from_size=$2
  local to_size=$3
  local step=$4
  local num_tests_per_size=$5
  local max_element_value=$6

  local total_tests=$(( ((to_size - from_size) / step) * num_tests_per_size +  num_tests_per_size)) 
  local current_test=0

  # Цикл для каждого размера теста
  for size in $(seq $from_size $step $to_size); do
      for ((i=1; i<=$num_tests_per_size; i++)); do
          input_file="${folder_name}/${size}_${i}.in"
          output_file="${folder_name}/${size}_${i}.out"

          ./generateArray $size $max_element_value > "$input_file"

          ./sort < "$input_file" > "$output_file" || {
              echo "Error: Sorting failed for test '$input_file'." >&2
              exit 1
          }
      done
  done
  echo ""
}

# Основная функция скрипта
main() 
{
    createFolders

    very_small_tests_params=(0 150 1 5 32767)
    small_tests_params=(0 1000 50 5 32767)
    big_tests_params=(0 1000000 10000 1 32767)
    test_most_duplicates_params=(0 1000000 10000 1 10000)

    generateTests "very_small_tests"     "${very_small_tests_params[@]}"
    generateTests "small_tests"          "${small_tests_params[@]}"
    generateTests "big_tests"            "${big_tests_params[@]}"
    generateTests "test_most_duplicates" "${test_most_duplicates_params[@]}"

    echo "All tests generated"
}

# Вызываем основную функцию
main "$@"
