package main

import "fmt"

type node struct {
	v int
	next *node
}

func (head *node) load(N int) {
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

func (head *node) pushTail(val int) {
	for head.next != nil {
		head = head.next
	}

	head.next = new(node)
	head = head.next
	head.v = val
	head.next = nil
}

func (head *node) pushHead(val int) {
	cpnode := &node{
		v: head.v,
		next: head.next,
	}
	head.v = val
	head.next = cpnode
}

func main() {
	lista := new(node)
	lista.next = nil

	lista.load(5)
	lista.pushTail(32)
	lista.pushHead(24)
	for lista != nil {
		fmt.Printf("%d ",lista.v)
		lista = lista.next
	}
}
