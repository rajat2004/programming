package main

// From https://tour.golang.org/concurrency/10

import (
	"fmt"
	"sync"
)

type Fetcher interface {
	// Fetch returns the body of URL and
	// a slice of URLs found on that page.
	Fetch(url string) (body string, urls []string, err error)
}

// Crawl uses fetcher to recursively crawl
// pages starting with url, to a maximum of depth.
func Crawl(url string, depth int, fetcher Fetcher) {
	// TODO: Fetch URLs in parallel.
	// TODO: Don't fetch the same URL twice.
	// This implementation doesn't do either:
	if depth <= 0 {
		return
	}
	body, urls, err := fetcher.Fetch(url)
	if err != nil {
		fmt.Println(err)
		return
	}
	fmt.Printf("found: %s %q\n", url, body)
	for _, u := range urls {
		Crawl(u, depth-1, fetcher)
	}
	return
}

// SafeMap includes a mutex for locking the map before reading or writing
type SafeMap struct {
	mu      sync.Mutex
	fetched map[string]bool
}

// ConcurrentMutexCrawler does parallel crawl and uses a mutex for locking
func ConcurrentMutexCrawler(url string, mp *SafeMap, fetcher Fetcher) {
	// Check whether url is already fetched or someone is doing it
	mp.mu.Lock()
	urlDone := mp.fetched[url]
	mp.fetched[url] = true // Mark that I'm doing it
	mp.mu.Unlock()

	if urlDone {
		return
	}

	body, urls, err := fetcher.Fetch(url)
	if err != nil {
		fmt.Println(err)
		return
	}

	fmt.Printf("Found: %s %q\n", url, body)

	var done sync.WaitGroup
	for _, u := range urls {
		// fmt.Printf("Urls: %s\n", u)
		done.Add(1)
		// Pass as arg otherwise it'll use a different value of u
		// Arg will be a private copy of the goroutine
		go func(url string) {
			ConcurrentMutexCrawler(url, mp, fetcher)
			done.Done()
		}(u)
	}

	done.Wait()
}

func main() {
	// Crawl("https://golang.org/", 4, fetcher)

	mp := SafeMap{fetched: make(map[string]bool)}
	ConcurrentMutexCrawler("https://golang.org/", &mp, fetcher)
}

// fakeFetcher is Fetcher that returns canned results.
type fakeFetcher map[string]*fakeResult

type fakeResult struct {
	body string
	urls []string
}

func (f fakeFetcher) Fetch(url string) (string, []string, error) {
	if res, ok := f[url]; ok {
		return res.body, res.urls, nil
	}
	return "", nil, fmt.Errorf("not found: %s", url)
}

// fetcher is a populated fakeFetcher.
var fetcher = fakeFetcher{
	"https://golang.org/": &fakeResult{
		"The Go Programming Language",
		[]string{
			"https://golang.org/pkg/",
			"https://golang.org/cmd/",
		},
	},
	"https://golang.org/pkg/": &fakeResult{
		"Packages",
		[]string{
			"https://golang.org/",
			"https://golang.org/cmd/",
			"https://golang.org/pkg/fmt/",
			"https://golang.org/pkg/os/",
		},
	},
	"https://golang.org/pkg/fmt/": &fakeResult{
		"Package fmt",
		[]string{
			"https://golang.org/",
			"https://golang.org/pkg/",
		},
	},
	"https://golang.org/pkg/os/": &fakeResult{
		"Package os",
		[]string{
			"https://golang.org/",
			"https://golang.org/pkg/",
		},
	},
}
