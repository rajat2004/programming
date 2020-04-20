// Based on https://blog.rapid7.com/2016/08/04/build-a-simple-cli-tool-with-golang/
package main

import (
	"flag"
	"fmt"
	"os"
)

func main() {
	// Add submcommands
	countCmd := flag.NewFlagSet("count", flag.ExitOnError)
	listCmd := flag.NewFlagSet("list", flag.ExitOnError)

	// Count subcommands
	countTextPtr := countCmd.String("text", "", "Text to Parse (Required")

	textPtr := flag.String("text", "", "Text to parse. (Required)")
	flag.Parse()

	if *textPtr=="" {
		flag.PrintDefaults()
		os.Exit(1)
	}

	fmt.Printf("textPtr: %s\n", *textPtr)
}
