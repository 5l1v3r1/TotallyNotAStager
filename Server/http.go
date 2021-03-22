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

	ret := base64.StdEncoding.EncodeToString(payload) 
	fmt.Fprintf(w, ret)

}