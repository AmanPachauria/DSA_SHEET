function quicksort(arr, low, high) {
  if (low < high) {
    const partitionIndex = partition(arr, low, high);
    quicksort(arr, low, partitionIndex - 1);
    quicksort(arr, partitionIndex + 1, high);
  }
}

function partition(arr, low, high) {
  const pivot = arr[low];
  let i = low;
  let j = high;

  while (i < j) {
    while (arr[i] <= pivot && i <= high) {
      i++;
    }
    while (arr[j] > pivot && j >= low) {
      j--;
    }
    if (i < j) {
      // Swap arr[i] and arr[j]
      [arr[i], arr[j]] = [arr[j], arr[i]];
    }
  }

  // Swap arr[low] and arr[j]
  [arr[low], arr[j]] = [arr[j], arr[low]];

  return j;
}

// Example usage:
const arr = [5, 3, 8, 4, 2, 7, 1];
quicksort(arr, 0, arr.length - 1);
console.log(arr); // Sorted array
