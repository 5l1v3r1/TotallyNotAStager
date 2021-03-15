package main

import(

	"fmt"
	"log"
	"net/http"
	"io/ioutil"
	"encoding/base64"
	"github.com/gorilla/mux"

)

func handler(){

	myRouter := mux.NewRouter().StrictSlash(true)
	myRouter.HandleFunc("/test", srv).Methods("GET")

	log.Fatal(http.ListenAndServe(":80", myRouter))

}

func srv(w http.ResponseWriter, r *http.Request){

	module := "a.bin"

	data, err := ioutil.ReadFile(module)
	if err != nil {

		fmt.Println(err)
		fmt.Fprintf(w, "")

	}
	
	// Add encryption here
	
	ret := base64.StdEncoding.EncodeToString(data) 
	fmt.Fprintf(w, ret)

}