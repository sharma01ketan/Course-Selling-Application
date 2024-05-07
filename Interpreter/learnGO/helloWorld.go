package main

import (
	"fmt"
	// "math"
)

func main(){
	fmt.Println("hello world");
	a := "initial";
	fmt.Println(a);
	var b,c int = 1,2;
	fmt.Println(b,c);
	const s = "const";
	fmt.Println(s);

	for i := 0; i < 10; i++{
		fmt.Println("ketan bro")
	}
	
	var n int = 10;
	fmt.Println(n);

	if (true && false){
		fmt.Println(true);
	} else{
		fmt.Println("galat baat");
	}

	num := 0

    for num < 4 {
        fmt.Println(num)
		if(num==2){
			break;
		}
        num++
    }
	
	DeploymentOptions := [...]string{"R-pi", "AWS", "GCP", "Azure"}

	/* Loop through the deployment options array */
	for index, option := range DeploymentOptions {
		fmt.Println(index, option)
	}

}