package main

import "fmt"

func add(a int, b int) int {
	return a+b
}

func main() {
	// fmt.Printf("Hello World!\n")
	// var a int
	// a = 12
	var arr = [] int{12,24,34}

	for i:=0; i<10; i++ {
		fmt.Println("Sum is",add(arr[0],arr[1]))
	}
}
