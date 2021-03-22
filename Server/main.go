package main 

import (

	"fmt"
	"flag"
	"io/ioutil"

)

type FlagOptions struct { 

	help             bool
	module         string

}

var payload []byte 

func options() *FlagOptions {

	help := flag.Bool("h", false, "Help Menu")
	module := flag.String("m", "", "module to load for staging")
	flag.Parse()

	return &FlagOptions{

		help:	*help,
		module: *module,

	}

}

func main() {

	fmt.Println("Staging Server")
	opt := options()

	if opt.help {

		fmt.Println("Server.exe -m <module.bin>")
		return

	} else if opt.module == "" {
	
		fmt.Println("Server.exe -m <module.bin>")
		return
		
	
	} else {

		

		data, err := ioutil.ReadFile(opt.module)
		if err != nil {
	
			fmt.Println(err)
	
		}

		payload = data
		handler() // do the actual shizz if you know what I mean

	}

}