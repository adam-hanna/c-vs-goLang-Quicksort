package main

import (
	"fmt"
	"math/rand"
	"time"
)

func swap(x *int, y *int) {
	temp := *y
	*y = *x
	*x = temp
}

func partition(array []int, p uint, q uint, pivotLocation uint) uint {

	pivot := array[pivotLocation]
	swap(&array[pivotLocation], &array[q])
	i := p
	for j := p; j < q; j++ {
		if array[j] <= pivot {
			swap(&array[i], &array[j])
			i++
		}
	}
	swap(&array[q], &array[i])
	return i
}

func quicksort(array []int, start uint, end uint) {
	if start < end {
		pivot := (end + start) / 2
		r := partition(array, start, end, pivot)
		if r > start {
			quicksort(array, start, r-1)
		}
		quicksort(array, r+1, end)
	}
}

func main() {
	a1 := make([]int, 100000000)

	for i := 0; i < 100000000; i++ {
		a1[i] = rand.Int()
	}

	fmt.Printf("a1[0]: %d, a1[1]: %d, a1[2]: %d\n", a1[0], a1[1], a1[2])

	// now run the test
	t0 := time.Now()
	quicksort(a1, 0, 100000000-1)
	t1 := time.Now()
	fmt.Printf("n of %v took %v to run.\n", len(a1), t1.Sub(t0))
	fmt.Printf("a1[0]: %d, a1[1]: %d, a1[2]: %d\n", a1[0], a1[1], a1[2])
}
