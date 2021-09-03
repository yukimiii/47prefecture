package main

import (
	"fmt"
	"hash/fnv"
	"math/rand"
	"sync"
	"time"
	//"os"
	//"log"
)

// Number of philosophers is simply the length of this list.
var philosophoi = []string{"Azuma ", "Joe   ", "Minato", "Tsuru ", "Sakura", "Miii  "}

const hunger = 2               // Number of times each philosopher eats
const think = time.Second / 10 // Mean think time
const eat = time.Second / 10   // Mean eat time
var dining sync.WaitGroup

//var fmt = log.New(os.Stdout, "", 0)

func diningProblem(phName string, dominantHand, otherHand *sync.Mutex) {
	fmt.Println(time.Now().Nanosecond(), phName, "Seated")
	h := fnv.New64a()
	h.Write([]byte(phName))
	rg := rand.New(rand.NewSource(int64(h.Sum64())))
	rSleep := func(t time.Duration) {
		time.Sleep(t/2 + time.Duration(rg.Int63n(int64(t))))
	}
	for h := hunger; h > 0; h-- {
		fmt.Println(time.Now().Nanosecond(), phName, "Hungry")
		dominantHand.Lock() // pick up forks
		otherHand.Lock()
		fmt.Println(time.Now().Nanosecond(), phName, "Eating")
		rSleep(eat)
		dominantHand.Unlock() // put down forks
		otherHand.Unlock()
		fmt.Println(time.Now().Nanosecond(), phName, "Thinking")
		rSleep(think)
	}
	fmt.Println(time.Now().Nanosecond(), phName, "Satisfied")
	dining.Done()
	fmt.Println(time.Now().Nanosecond(), phName, "Left the table")
}

func main() {
	fmt.Println("Table empty")
	dining.Add(len(philosophoi))
	fork0 := &sync.Mutex{}
	forkLeft := fork0
	for i := 1; i < len(philosophoi); i++ {
		forkRight := &sync.Mutex{}
		go diningProblem(philosophoi[i], forkLeft, forkRight)
		forkLeft = forkRight
	}
	go diningProblem(philosophoi[0], fork0, forkLeft)
	dining.Wait()
	fmt.Println("Table empty")
}
