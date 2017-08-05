package main

import "fmt"

type node struct {
	v int
	next *node
}

func main() {
	lista := new(node)
	lista.next = nil

	lista.carica(5)

	for lista != nil {
		fmt.Printf("%d ",lista.v)
		lista = lista.next
	}
}

func (head *node) carica(N int) {
	if N < 1 {
		return
	}

	for i := 0; i < N-1; i++ {
		fmt.Scanf("%d", &head.v)
		head.next = new(node)
		head = head.next
	}
	fmt.Scanf("%d", &head.v)
	head.next = nil
}
